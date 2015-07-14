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
	TraverseFolder(std::string, std::string);					//���캯�������ļ���Ŀ¼���б��ļ�������
	~TraverseFolder();
};

