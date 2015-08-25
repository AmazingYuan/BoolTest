/**
该对象解决任意数量的变量的指定维数排列组合的情况的遍历，interactionDimension是维数，variableNum是变量的数量，都通过构造函数指定好，使用++运算符遍历出来
*/

#pragma once
#include "Binary.h"
class PermutationAndCombination :
	public Binary
{
private:
	int variableNum;
public:
	
	PermutationAndCombination(int interactionDimension ,int variableNum);
	~PermutationAndCombination();
	bool operator++ ();
};

