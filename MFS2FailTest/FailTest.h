/**	
	这是一个FailTest类，用于对一组MFS生成对应的testcase，
	并输出到文件里。
	通过InsertMFS将mfs输入vector，使用MFS2TESTCASE进行转换，使用Output进行输出
*/
#pragma once
#include <set>
#include <vector>
class FailTest
{
private:
	std::set<std::string> testcases;
public:
	std::vector<std::string> MFS;
	void Output(std::string);
	void InsertMFS(char*);
	void MFS2TestCases();
	FailTest();
	~FailTest();
};

