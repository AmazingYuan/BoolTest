/**
	这是一个Binary方法，主要解决C++对于二进制数字支持的问题。
	number是一个数组，保存指定长度的二进制数。
	该类仅仅重载了一个++运算，是为本实验增加的遍历一个二进制数的方法。
	*/
#pragma once
#include "stdafx.h"
class Binary
{
private:
	
public:
	int bit;
	int* number;
	Binary(int);
	~Binary();
	bool operator++ ();
};

