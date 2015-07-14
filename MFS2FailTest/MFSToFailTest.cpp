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
	std::ifstream fp; //���ڴ�һ���б��ļ�
	fp.open(completeloc);
	if (!fp) {
		std::cout << "�ļ���������" << std::endl;
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
	//a�Ƕ�ȡ�ļ��е����ƣ�b��list�ļ������� , c������ļ��е�����
	MFSToFailTest::writeloc = c;
}


MFSToFailTest::~MFSToFailTest()
{
}

