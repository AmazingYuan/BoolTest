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
	std::map<std::vector<int>, int> numOfAValueAppeared;//����洢һ���м��������������һ������������ֵ��uncover�г��ִ������������map�ɵõ����ִ������Ĳ�����ֵ
	const int expressionLength;
	const int interactionDimension;
	int initTestCasesNum;
	void InitUncover();
	bool UncoverIsNotNULL();
	CoverArrayVector CoverArray;
	int Fac(int num);
	double CombinationNum(int VariableNum,int CombiNum);//�����������һ����С�����������������
	
public:
	void AETG(const int candidateNum);
	void PrintCoverArray();
	CombinatorialTest(const int expressionLength,const int interactionDimension,int initTestCasesNum);
	~CombinatorialTest();
};

