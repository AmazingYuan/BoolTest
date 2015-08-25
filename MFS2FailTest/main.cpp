// MFS2FailTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char** argv)
{
	
	time_t t_start, t_end;
	t_start = time(NULL);//计算程序开始运行的时间
	char shell_cmd[100];
	

	if (0 == std::strcmp(argv[1],"1"))
	{
		//该程序跑出19131个testcase耗费44s时间
		sprintf_s(shell_cmd, "mkdir %s", argv[3]);
		system(shell_cmd);
		MFSToFailTest mfs2fail(argv[2], "AllListFile.txt", argv[3]);
		mfs2fail.CreateListFile("TCAS");
		mfs2fail.TraverseFiles();
		int filenum = mfs2fail.fileNameList.size();
		for (int i = 0; i < filenum; ++i)
		{
			mfs2fail.ReadSingleFile(mfs2fail.fileNameList[i]);
		}
	}
	else if (0 == std::strcmp(argv[1], "2"))
	{
		//19131个testcase计算出有放回情况下所有理论概率的时间花费约419秒
		sprintf_s(shell_cmd, "mkdir %s", argv[3]);
		system(shell_cmd);
		RepRandom reprandom(argv[2], "AllListFile.txt", argv[3]);
		reprandom.CreateListFile("TCAS");
		reprandom.TraverseFiles();
		int filenum = reprandom.fileNameList.size();
		for (int i = 0; i < filenum; i++)
		{
			reprandom.ReadSingleFile(reprandom.fileNameList[i]);
			reprandom.Output(reprandom.fileNameList[i],reprandom.Calculate1Time());		
		}
	}
	else if (0 == std::strcmp(argv[1], "3"))
	{
		sprintf_s(shell_cmd, "mkdir %s", argv[3]);
		system(shell_cmd);
		CombinatorialTest CT(10,2,1);
		
		CT.AETG(10);
		CT.PrintCoverArray();
	}

	t_end = time(NULL);//计算程序运行结束的时间
	std::cout << "程序运行时间: " << difftime(t_end, t_start) << " s" << std::endl;
	return 0;
}

