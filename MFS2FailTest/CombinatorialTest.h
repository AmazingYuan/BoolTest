#pragma once
#include <vector>
#include <map>
#include <string>
class CombinatorialTest
{
private:
	std::vector<std::vector<std::map<int, std::vector<int>>>> uncover;
	const int expressionLength;
	const int interactionDimension;
	int initTestCasesNum;
	void InitUncover();
	bool UncoverIsNotNULL();
	std::vector<int *> CoverArray;
public:
	void AETG(const int candidateNum);
	CombinatorialTest(const int expressionLength,const int interactionDimension,int initTestCasesNum);
	~CombinatorialTest();
};

