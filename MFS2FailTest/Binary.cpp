#include "stdafx.h"


Binary::Binary(int a)
{
	if (a > 0)
	{
		number = new int[a];
		for (int i = 0; i < a; ++i)
		{
			number[i] = 0;
		}
		bit = a;
	}
}


Binary::~Binary()
{
	delete[]number;
}

bool Binary::operator++()
{
	++number[bit - 1];
	for (int i = 1; i <= bit; ++i)
	{
		if (number[bit - i] != 2)
		{
			return 1;
		}
		else{

			if (i != bit){
				++number[bit - i - 1];
			}
			else{
				return 0;
			}
			number[bit - i] = 0;
		}
	}
}