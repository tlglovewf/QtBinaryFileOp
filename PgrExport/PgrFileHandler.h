#pragma once

#include <memory>
#include <string>
#include <functional>
#pragma pack(push)
#pragma pack(1)
class ImageHeader {
public:
	ImageHeader()
	{
		memset(this, 0, sizeof(ImageHeader));
		sync[0] = 0xAA; sync[1] = 0xBB; sync[2] = 0xCC; sync[3] = 0xDD;
		
	}

public:
	char sync[4]; //4bytes
	//������
	uint16_t camid; //2bytes
	//ͼ���Դ�id �������
	uint32_t idgrab; //4bytes
	//����ļ�id �Զ��ۼ�
	uint32_t idsave; //4bytes
	//jpg��С
	uint32_t jpglen; // 4bytes
	//����Դ�ʱ��Ҳ������GPSʱ��
	double tmgrab; //8byts
	//ͼ�񵽵���ʱ��
	double tmsave; //8bytes
};

#pragma pack(pop)


class PgrFileHandler
{
public:
	/*
	 * ����pgr�ļ�
	 * @param path �ļ�·��
	 * @param func ������ͷ�ļ��ص�����
	 * @return     �ļ��Ƿ������
	 */
	static bool ParseFile(const  std::string& path, std::function<void(const ImageHeader&)> func = nullptr);

};

