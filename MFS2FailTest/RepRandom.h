/**
	这是一个RepRandom类，继承自TraverseFolder方法，重写了ReadSingleFile方法，新增了Calculate1Time方法，这个新增的方法主要计算1次抽取没有抽中的概率。
	多次抛投至少中一个的概率在Output方法中一边计算一边输出。
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

