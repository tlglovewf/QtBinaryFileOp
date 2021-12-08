#include "NetControl.h"	 
#include <QDebug>
#include <NetCon.h>
#include <wlanapi.h>
#include <atlconv.h>



NetControl::NetControl(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	connect(ui.btnLan, SIGNAL(clicked()), this, SLOT(onLan()));
	connect(ui.btnWLan , SIGNAL(clicked()), this, SLOT(onWLan()));
}


void NetControl::onLan()
{
	CoInitialize(nullptr);
	INetConnectionManager *pnetmgr;
	INetConnection *pnetconnec;
	IEnumNetConnection *penum;
	if (!SUCCEEDED(CoCreateInstance(CLSID_ConnectionManager, NULL, CLSCTX_SERVER, IID_INetConnectionManager, (void**)&pnetmgr)))
	{
		return;
	}

	pnetmgr->EnumConnections(NCME_DEFAULT, &penum);

	pnetmgr->Release();

	if (NULL == penum)
	{
		return;
	}
	ULONG celtFetched;

	while (penum->Next(1, &pnetconnec, &celtFetched) == S_OK)
	{
		USES_CONVERSION;

		NETCON_PROPERTIES *prop;
		pnetconnec->GetProperties(&prop);

		qDebug() << "Status1: " << (prop->Status == NCS_CONNECTED) << endl;

		//qDebug() << "Name:" << W2A(prop->pszwName) << endl;
		qDebug() << "Other:" << W2A(prop->pszwDeviceName) << endl;
		QString devname(W2A(prop->pszwDeviceName));

		if (devname.contains("Ethernet Connection", Qt::CaseInsensitive))
		{
			HRESULT rst = 0;
			if (prop->Status == NCS_CONNECTED)
			{
				rst = pnetconnec->Disconnect();
			}
			else
			{
				rst = pnetconnec->Connect();
			}
			if (SUCCEEDED(rst))
			{
				qDebug() << "Setting Successfully!! " << rst << endl;
			}
			
		}
		else if (devname.contains("Wireless Adapter", Qt::CaseInsensitive))
		{
			//wlan 禁用控制
			HRESULT rst = 0;
			if (prop->Status == NCS_CONNECTED)
			{
				pnetconnec->Disconnect();
			}
			else
			{
				pnetconnec->Connect();
			}
			if (SUCCEEDED(rst))
			{
				qDebug() << "Setting Successfully!! " << rst << endl;
			}
		}
		else
		{
			qDebug() << "Others" << endl;
		}

		//HRESULT rst = pnetconnec->Disconnect();
		//HRESULT rst = pnetconnec->Connect();
		//qDebug() << "disconnect : " << rst << endl;

		qDebug() << "Status2: " << (prop->Status == NCS_CONNECTED) << endl;
	}

}


DWORD GetWlanState()
{
	DWORD dwError = ERROR_SUCCESS;
	HANDLE hClient = NULL;
	DWORD dwServiceVersion;
	GUID guidIntf;
	WLAN_RADIO_STATE wlanRadioState;
	PWLAN_INTERFACE_INFO_LIST pIfList = NULL;
	PVOID pData = NULL;
	DWORD dwDataSize = 0;
	DWORD RadioState = -1;
	USES_CONVERSION;
	__try
	{
		// open handle
		if ((dwError = WlanOpenHandle(WLAN_API_VERSION, NULL, &dwServiceVersion, &hClient)) != ERROR_SUCCESS)
		{
			__leave;
		}
		DWORD dwResult = WlanEnumInterfaces(hClient, NULL, &pIfList);
		GUID guidIntf = pIfList->InterfaceInfo[0].InterfaceGuid;
		// query radio state information
		// this opcode is not supported in XP
		if ((dwError = WlanQueryInterface(
			hClient,
			&guidIntf,
			wlan_intf_opcode_radio_state,
			NULL,                       // reserved
			&dwDataSize,
			&pData,
			NULL                        // not interesed in the type of the opcode value
		)) != ERROR_SUCCESS &&
			dwError != ERROR_NOT_SUPPORTED)
		{
			__leave;
		}

		if (dwError == ERROR_SUCCESS)
		{
			if (dwDataSize != sizeof(WLAN_RADIO_STATE))
			{
				dwError = ERROR_INVALID_DATA;
				__leave;
			}

			wlanRadioState = *((PWLAN_RADIO_STATE)pData);

			//wlanRadioState.PhyRadioState[0].dot11HardwareRadioState
			if (wlanRadioState.PhyRadioState[0].dot11SoftwareRadioState == dot11_radio_state_on)
			{
				RadioState = 1;
			}
			else
				if (wlanRadioState.PhyRadioState[0].dot11SoftwareRadioState == dot11_radio_state_off)
				{
					RadioState = 0;
				}
			WlanFreeMemory(pData);
			pData = NULL;
		}
		else
		{
			//wcout << L"Querying radio state is not supported." << endl;
		}

	}
	__finally
	{
		if (pData != NULL)
		{
			WlanFreeMemory(pData);
		}

		// clean up
		if (hClient != NULL)
		{
			WlanCloseHandle(
				hClient,
				NULL            // reserved
			);
		}
	}

	return RadioState;
}

//打开或关闭无线网卡
DWORD SetRadioState(int radiostate)
{
	DWORD dwError = ERROR_SUCCESS;
	HANDLE hClient = NULL;
	DWORD dwServiceVersion;
	PWLAN_INTERFACE_INFO_LIST pIfList = NULL;

	PWLAN_INTERFACE_CAPABILITY pInterfaceCapability = NULL;
	DWORD i;
	WLAN_PHY_RADIO_STATE wlanPhyRadioState;



	if (radiostate == 0)
	{
		wlanPhyRadioState.dot11SoftwareRadioState = dot11_radio_state_off;
	}
	else
	{
		wlanPhyRadioState.dot11SoftwareRadioState = dot11_radio_state_on;
	}

	__try
	{
		// open handle
		if ((dwError = WlanOpenHandle(WLAN_API_VERSION, NULL, &dwServiceVersion, &hClient)) != ERROR_SUCCESS)
		{
			__leave;
		}
		DWORD dwResult = WlanEnumInterfaces(hClient, NULL, &pIfList);
		GUID guidIntf = pIfList->InterfaceInfo[0].InterfaceGuid;
		if (dwResult != ERROR_SUCCESS)
		{
			//qDebug() << " error ." << endl;
		}
		else
		{
			//qDebug() << "successfully." << endl;
		}
		// get interface capability, which includes the supported PHYs
		if ((dwError = WlanGetInterfaceCapability(
			hClient,
			&guidIntf,
			NULL,                       // reserved
			&pInterfaceCapability
		)) != ERROR_SUCCESS)
		{
			__leave;
		}

		// set radio state on every PHY
		for (i = 0; i < pInterfaceCapability->dwNumberOfSupportedPhys; i++)
		{
			// set radio state on every PHY
			wlanPhyRadioState.dwPhyIndex = i;

			if ((dwError = WlanSetInterface(
				hClient,
				&pIfList->InterfaceInfo[0].InterfaceGuid,
				wlan_intf_opcode_radio_state,
				sizeof(wlanPhyRadioState),
				(PBYTE)&wlanPhyRadioState,
				NULL                        // reserved
			)) != ERROR_SUCCESS)
			{
				// rollback is nice to have, but not required
				__leave;
			}
		}

	}
	__finally
	{
		// clean up
		if (hClient != NULL)
		{
			WlanCloseHandle(hClient, NULL);
		}
		if (pInterfaceCapability != NULL)
		{
			WlanFreeMemory(pInterfaceCapability);
		}
	}
	return dwError;
}

void NetControl::onWLan()
{
	

	switch (GetWlanState())
	{
	case 0:
		SetRadioState(1);
		break;
	case 1:
		SetRadioState(0);
		break;
	default:
		break;
	}
	qDebug() << "Current WLAN Status:" << GetWlanState() << endl;
}
