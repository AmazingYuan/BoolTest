/**	
	����һ��FailTest�࣬���ڶ�һ��MFS���ɶ�Ӧ��testcase��
	��������ļ��
	ͨ��InsertMFS��mfs����vector��ʹ��MFS2TESTCASE����ת����ʹ��Output�������
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

