#include "stdafx.h"
#include "TraverseFolder.h"


TraverseFolder::TraverseFolder(std::string a , std::string b)
{
	TraverseFolder::folder = a;
	TraverseFolder::listFileName = b;
}


TraverseFolder::~TraverseFolder()
{
}

void TraverseFolder::CreateListFile(std::string keyword)
{
	std::string shell_cmd;
	shell_cmd = "dir /b " + this->folder + keyword + "*.txt >" + this->folder + this->listFileName;
	const char* shell = shell_cmd.data();
	system(shell);
}

void TraverseFolder::TraverseFiles()
{
	std::string completeloc = TraverseFolder::folder + TraverseFolder::listFileName;
	std::ifstream ifstr;
	ifstr.open(completeloc);
	if (!ifstr) {
		std::cerr << "打开文件失败！" << std::endl;
		return;
	}
	char buffer[1024];
	while (ifstr.getline(buffer, 1024)) {
		this->fileNameList.push_back(buffer);
		/*TraverseFolder::ReadSingleFile(buffer);*/
	}
	ifstr.close();
}

