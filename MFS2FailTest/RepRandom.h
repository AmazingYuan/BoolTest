/**
	����һ��RepRandom�࣬�̳���TraverseFolder��������д��ReadSingleFile������������Calculate1Time��������������ķ�����Ҫ����1�γ�ȡû�г��еĸ��ʡ�
	�����Ͷ������һ���ĸ�����Output������һ�߼���һ�������
*/
#pragma once
#include "TraverseFolder.h"
#include <string>
class RepRandom :public TraverseFolder
{
private:
	std::string writeloc;
	int lineNum;
	int expLength;
public:
	void ReadSingleFile(std::string);
	double Calculate1Time();
	void Output(std::string, double);
	RepRandom(std::string, std::string, std::string);
	~RepRandom();
};

