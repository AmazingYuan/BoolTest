#include "stdafx.h"
#include "FiltFiles.h"


FiltFiles::FiltFiles(std::string a, std::string b, std::string c) :TraverseFolder(a, b)
{
	//a�Ƕ�ȡ�ļ��е����ƣ�b��list�ļ������� , c������ļ��е�����
	this->writeloc = c;
}


FiltFiles::~FiltFiles()
{
}

void FiltFiles::TraverseFiles()
{

}