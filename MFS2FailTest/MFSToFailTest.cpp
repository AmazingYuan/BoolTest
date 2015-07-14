#include "stdafx.h"
#include "MFSToFailTest.h"

void MFSToFailTest::ReadSingleFile(std::string filename)
{
	FailTest failtest;
	std::string completeloc;
	std::string completewriteloc;
	completeloc = TraverseFolder::folder + filename;
	int filenamelength = filename.length();
	std::string wfilename = filename.replace(filenamelength - 8, 4, "");
	completewriteloc = writeloc + wfilename;
	std::ifstream fp; //用于打开一个列表文件
	fp.open(completeloc);
	if (!fp) {
		std::cout << "文件操作错误！" << std::endl;
		return;
	}
	char buf[50];
	while (fp.getline(buf, 50)) {
		failtest.InsertMFS(buf);
	}
	failtest.MFS2TestCases();
	failtest.Output(completewriteloc);
	fp.close();
}
MFSToFailTest::MFSToFailTest(std::string a, std::string b ,std::string c) :TraverseFolder(a, b)
{
	//a是读取文件夹的名称，b是list文件的名称 , c是输出文件夹的名称
	MFSToFailTest::writeloc = c;
}


MFSToFailTest::~MFSToFailTest()
{
}

