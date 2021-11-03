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
	//相机序号
	uint16_t camid; //2bytes
	//图像自带id 触发序号
	uint32_t idgrab; //4bytes
	//存进文件id 自动累加
	uint32_t idsave; //4bytes
	//jpg大小
	uint32_t jpglen; // 4bytes
	//相机自带时间也可以是GPS时间
	double tmgrab; //8byts
	//图像到电脑时间
	double tmsave; //8bytes
};

#pragma pack(pop)


class PgrFileHandler
{
public:
	/*
	 * 解析pgr文件
	 * @param path 文件路径
	 * @param func 处理单个头文件回调函数
	 * @return     文件是否处理完成
	 */
	static bool ParseFile(const  std::string& path, std::function<void(const ImageHeader&)> func = nullptr);

};

