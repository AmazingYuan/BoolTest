#pragma once
#include <string>
#include <vector>
class TraverseFolder
{
protected:
	std::string folder;
	std::string listFileName;
public:
	std::vector<std::string> fileNameList;
	virtual void ReadSingleFile(std::string) = 0;
	virtual void CreateListFile(std::string);
	virtual void TraverseFiles();
	TraverseFolder(std::string, std::string);					//构造函数设置文件夹目录和列表文件的名字
	~TraverseFolder();
};

