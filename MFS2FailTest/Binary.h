/**
	����һ��Binary��������Ҫ���C++���ڶ���������֧�ֵ����⡣
	number��һ�����飬����ָ�����ȵĶ���������
	�������������һ��++���㣬��Ϊ��ʵ�����ӵı���һ�����������ķ�����
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

