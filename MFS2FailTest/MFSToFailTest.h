/**
	����һ��MFSToFailTest�࣬�̳���TraverseFolder�࣬��д��ReadSingleFile������
	�������������Ҫ��ÿһ���ļ�����Ӧ��һ��FailTest������������Ƚϼ򵥣�����������FailTest��
*/
#pragma once
#include "TraverseFolder.h"
#include <string>
class MFSToFailTest :public TraverseFolder
{
private:
	std::string writeloc;
public:
	void ReadSingleFile(std::string);
	MFSToFailTest(std::string, std::string, std::string);
	~MFSToFailTest();
};

