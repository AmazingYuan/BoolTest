/**
�ö��������������ı�����ָ��ά��������ϵ�����ı�����interactionDimension��ά����variableNum�Ǳ�������������ͨ�����캯��ָ���ã�ʹ��++�������������
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

