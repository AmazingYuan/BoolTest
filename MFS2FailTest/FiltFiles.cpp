#include "stdafx.h"
#include "FiltFiles.h"


FiltFiles::FiltFiles(std::string a, std::string b, std::string c) :TraverseFolder(a, b)
{
	//a是读取文件夹的名称，b是list文件的名称 , c是输出文件夹的名称
	this->writeloc = c;
}


FiltFiles::~FiltFiles()
{
}

void FiltFiles::TraverseFiles()
{

}