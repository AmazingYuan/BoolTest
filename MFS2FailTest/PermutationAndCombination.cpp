#include "stdafx.h"
#include "PermutationAndCombination.h"


PermutationAndCombination::PermutationAndCombination(int interactionDimension, int variableNum) :
Binary(interactionDimension),
variableNum(variableNum)
{
	for (int i = 0; i < bit; ++i)
	{
		number[i] = i;
	}
}


PermutationAndCombination::~PermutationAndCombination()
{
	
}

bool PermutationAndCombination::operator++()
{
	
	++number[bit - 1];
	for (int i = 1; i <= bit; ++i)
	{
		if (number[bit - i] < variableNum-i+1 )
		{
			return 1;
		}
		else{

			if (i < bit){
				++number[bit - i - 1];
			}
			else{
				return 0;
			}
			for (int j = i; j >0 ;--j)
			{
				number[bit - j] = number[bit - j - 1] + 1;
			}
		}
	}
}