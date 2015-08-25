#pragma once
#include <vector>
#include <map>
#include <string>
typedef std::vector<std::vector<int>> CoverArrayVector;
typedef std::multimap<std::vector<int>, std::vector<int>> UncoverMap;
//typedef std::map<std::vector<int>, std::vector<int>> InnerUncoverMap;
typedef std::vector<std::vector<int>> AppearNumberOfValue;
class CombinatorialTest
{
private:
	UncoverMap uncover;
	//AppearNumberOfValue numOfValue;
	std::map<std::vector<int>, int> numOfAValueAppeared;//这个存储一个中间变量，用来保存一个参数和它的值在uncover中出现次数，遍历这个map可得到出现次数最多的参数的值
	const int expressionLength;
	const int interactionDimension;
	int initTestCasesNum;
	void InitUncover();
	bool UncoverIsNotNULL();
	CoverArrayVector CoverArray;
	int Fac(int num);
	double CombinationNum(int VariableNum,int CombiNum);//下面两个获得一个较小的数的排列组合数量
	
public:
	void AETG(const int candidateNum);
	void PrintCoverArray();
	CombinatorialTest(const int expressionLength,const int interactionDimension,int initTestCasesNum);
	~CombinatorialTest();
};

