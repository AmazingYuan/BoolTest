#include "stdafx.h"
#include "RepRandom.h"


RepRandom::RepRandom(std::string a, std::string b, std::string c) :TraverseFolder(a, b)
{
	RepRandom::writeloc = c;
}


RepRandom::~RepRandom()
{
}

void RepRandom::ReadSingleFile(std::string filename)
{
	this->lineNum = 0;
	this->expLength = 0;
	std::string completeloc;
	completeloc = RepRandom::folder + filename;
	std::ifstream fp; 
	fp.open(completeloc);
	if (!fp) {
		std::cout << "文件操作错误！" << std::endl;
		return;
	}
	char buf[50];
	fp.getline(buf, 50);
	++lineNum;
	expLength = strlen(buf);
	while (fp.getline(buf, 50)) {
		++lineNum;
	}
	fp.close();
}

double RepRandom::Calculate1Time()
{
	double firstpb = (1 - pow(0.5, this->expLength)*this->lineNum);
	return firstpb;
}

void RepRandom::Output(std::string filename, double firstpb)
{
	double iter = pow(2.0, this->expLength);
	std::string completewirteloc;
	completewirteloc = this->writeloc + "Rep_" + filename;
	std::ofstream os(completewirteloc, std::ios::in | std::ios::trunc);
	if (os)
	{
		double output = 1;
		//os << 1 - firstpb << std::endl;
		for (int i = 1; i < (iter + 1); ++i)
		{
			output =firstpb*output;
			os << 1 - output << std::endl;
		}
		os.close();
	}
	else{
		std::cerr << "无法打开文件！" << std::endl;
	}
}