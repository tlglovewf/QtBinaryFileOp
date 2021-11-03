#include "PgrFileHandler.h"
#include <fstream>
#include <iostream>

static constexpr int headLen = sizeof(ImageHeader);
static constexpr char headMark[4] = { 0xAA,0xBB,0xCC,0xDD };
#define PGR_MAX (1024*1024*1024*2.1)      //不能有空格
#define JPEG_MAX (1024*1024*50)      //不能有空格
bool PgrFileHandler::ParseFile(const  std::string& path, std::function<void(const ImageHeader&)> func/* = nullptr*/)
{
	std::ifstream  pgrfile(path, std::ios::binary);

	if (pgrfile.is_open())
	{

		auto old = pgrfile.tellg();
		auto st = old;
		pgrfile.seekg(0, std::ios::end);
		auto length = pgrfile.tellg();
		pgrfile.seekg(0, std::ios::beg);

		if (length < headLen) //如果文件为空 或者一个头都没有 直接返回false
			return false;

		std::shared_ptr<char> buffer = std::shared_ptr<char>(new char[length], std::default_delete<char[]>());
		if (buffer == nullptr)
		{
			std::cout << "file can not open ." << std::endl;
			return false;
		}
		else
		{
			pgrfile.read(buffer.get(), length);
			pgrfile.close();

			size_t cur = 0;

			for (; cur < length;)
			{
				char head[headLen] = { 0 };
				memcpy(head, &buffer.get()[cur], headLen);
				ImageHeader *img = reinterpret_cast<ImageHeader*>(head);
				if ((0 == memcmp(headMark, img->sync, 4)) && (img->jpglen > 100) && (img->jpglen < JPEG_MAX))
				{
					if (func)
					{
						func(*img);
					}
					pgrfile.seekg(img->jpglen, std::ios::cur);
					cur += img->jpglen + headLen;
				}
				else
				{
					++cur;
				}
			}
			return true;
		}
	}
	else
	{
		std::cout << "file can not open." << std::endl;
		return false;
	}
}