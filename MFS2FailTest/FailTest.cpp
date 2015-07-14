#include "stdafx.h"


void FailTest::InsertMFS(char * mfs)
{
	MFS.push_back(mfs);
}

void FailTest::MFS2TestCases()
{
	std::vector<int> keyloc;
	unsigned int MFSsize = MFS.size();
	for (unsigned int i = 0; i < MFSsize; ++i)
	{
		unsigned int MFSilength = MFS[i].length();
		for (unsigned int j = 0; j < MFSilength; ++j)
		{
			if (MFS[i][j] == '-')
			{
				keyloc.push_back(j);
			}
		}
		int keynum = keyloc.size();
		if (keynum>0)
		{
			Binary binary(keynum);
			do
			{
				for (unsigned int k = 0; k < keynum; ++k)
				{

					MFS[i][keyloc[k]] = binary.number[k] + 48; //°´ÕÕASCIIÂë
				}
				testcases.insert(MFS[i]);
			} while (binary++);
		}
		else
		{
			testcases.insert(MFS[i]);
		}
		keyloc.clear();
	}
	//Output();
}
void FailTest::Output(std::string writeloc)
{
	std::ofstream op(writeloc, std::ios::trunc | std::ios::in);
	std::set<std::string>::iterator iter;
	for (iter = testcases.begin(); iter != testcases.end(); ++iter)
	{
		//std::cout << *iter << std::endl;
		op << *iter << std::endl;
	}
	op.close();
}
FailTest::FailTest()
{
}


FailTest::~FailTest()
{
}
