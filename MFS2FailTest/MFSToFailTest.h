/**
	这是一个MFSToFailTest类，继承自TraverseFolder类，重写了ReadSingleFile方法，
	在这个方法中主要是每一个文件都对应于一个FailTest对象，所以这个比较简单，大多操作都在FailTest中
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

