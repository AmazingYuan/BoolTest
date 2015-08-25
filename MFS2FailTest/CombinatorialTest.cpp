#include "stdafx.h"
#include <stdlib.h>
#include <time.h>

CombinatorialTest::CombinatorialTest(const int expressionLength, const int interactionDimension,int initTestCasesNum) :
expressionLength(expressionLength),
interactionDimension(interactionDimension),
initTestCasesNum(initTestCasesNum)
{
}


CombinatorialTest::~CombinatorialTest()
{
	/*for (CoverArrayVector::const_iterator iter = CoverArray.begin(); iter != CoverArray.end(); iter++)
	{
		delete [](*iter);	
	}*/
}

void CombinatorialTest::InitUncover()
{
	//这里初始化CoverArray，使用初始化给定的initTestCasesNum和expressionLength随机初始化出一定数量的测试用例
	srand((unsigned)time(NULL));
	rand();
	int xxxx = rand() % 1;
	for (int j = 0; j < initTestCasesNum; ++j)
	{
		//int *initExpression = new int[expressionLength];
		std::vector<int> initExpression(expressionLength);
		for (int i = 0; i < expressionLength; ++i)
		{
			rand() / double(RAND_MAX) > 0.5 ? initExpression[i] = 1 : initExpression[i] = 0;		
		}
		CoverArray.push_back(initExpression);
	}
	//输出一下这个初始化的coverarray
	/*for (CoverArrayVector::const_iterator iter = CoverArray.begin(); iter != CoverArray.end(); iter++)
	{
		for (int i = 0; i < expressionLength; ++i)
		{
			std::cout << (*iter)[i];
		}
		std::cout << "\n";
	}*/

	//以下初始化uncover，使用给定的interactionDimension做初始化工作。
	std::vector<std::vector<int>> someValuesOfVariablesVec;
	Binary binary(interactionDimension);   //使用Binary对象完成对一些变量取值的赋值
	do
	{

		std::vector<int> oneValuesOfVariables(interactionDimension);
		//std::vector<int> markPointOfThisCombination(2);
		for (unsigned int k = 0; k < interactionDimension; ++k)
		{
			oneValuesOfVariables[k] = binary.number[k];
		}
		
		someValuesOfVariablesVec.push_back(oneValuesOfVariables);
		//someValuesOfVariablesVec.insert(std::map<std::vector<int>, std::vector<int>>::value_type(oneValuesOfVariables, markPointOfThisCombination));
	} while (++binary);

	//以下初始化中间变量numOfAValueAppeared，即一个参数f以及其值i在uncover中出现的次数
	int appearNum = CombinationNum(expressionLength - 1, interactionDimension - 1) * 2;//这里乘2是因为每个组合的每个参数F均有取值为0和1的两种情况
	for (int i = 0; i < expressionLength; ++i)
	{
		for (int value = 0; value <= 1; ++value)
		{
			std::vector<int> factorAndValue(2);
			factorAndValue[0] = i;
			factorAndValue[1] = value;
			numOfAValueAppeared.insert(std::map<std::vector<int>, int>::value_type(factorAndValue, appearNum));
		}
	}
	//以下开始删除uncover中和numOfAValueAppeared中的初始化中已经覆盖了的元素，而且
	//下面应该写一个对象，可以把指定数量的排列组合给列出来，作为key，上面那个深拷贝的map作为value，来构建一个总的uncovermap
	PermutationAndCombination permutationAndcombination(interactionDimension, expressionLength);
	do{
		//std::vector<int> everyfacflag(expressionLength);
		//for (int i = 0; i < expressionLength; ++i)
		//{
		//	everyfacflag[i] = 0;
		//}//上面两部用来新增一个vector，使得一次组合中一个变量最多减掉一次，不会重复减
		std::vector<std::vector<int>> coppiedsomeValuesOfVariablesVec = someValuesOfVariablesVec;//经过测试，这个赋值操作是个深拷贝操作
		std::vector<int> uncoverKey(interactionDimension);
		std::vector<std::vector<int>> value; //用来保存两个参数的取值对
		for (int i = 0; i < interactionDimension; ++i){
			uncoverKey[i] = permutationAndcombination.number[i];

		}
		for (int j = 0; j < CoverArray.size(); ++j)
		{
			std::vector<int> oneValuePair(interactionDimension);
			for (int i = 0; i < interactionDimension; ++i)
			{
				oneValuePair[i] = CoverArray[j][uncoverKey[i]];
			}
			value.push_back(oneValuePair);
		}
		for (int i = 0; i < value.size(); ++i)
		{
			std::vector<std::vector<int>>::const_iterator iter = coppiedsomeValuesOfVariablesVec.begin();
			
			for (; iter != coppiedsomeValuesOfVariablesVec.end();)
			{
				if ((*iter) == value[i]){
					std::cout << "成功找到需要消除的uncover表！" << std::endl;
					//删除成功后再去中间变量里减掉相应的次数，以  ------------   为Key去numOfAValueAppeared找
					std::vector<int> tempKey(2);
					for (int k = 0; k < uncoverKey.size(); ++k){

						tempKey[0] = uncoverKey[k];
						tempKey[1] = (*iter)[k];

						std::map<std::vector<int>, int>::iterator tempiter = numOfAValueAppeared.find(tempKey);
						if (tempiter != numOfAValueAppeared.end())
						{
							tempiter->second = tempiter->second - 1;
							std::cout << "现在tempiter->second的值为" << tempiter->second << std::endl;
							if (tempiter->second == 0)
							{
								numOfAValueAppeared.erase(tempiter);
							}
						}
					}

					iter = coppiedsomeValuesOfVariablesVec.erase(iter);
				}
				else{
					iter++;
				}
			}
		}
		for (int i = 0; i < coppiedsomeValuesOfVariablesVec.size(); ++i)
		{
			uncover.insert(UncoverMap::value_type(uncoverKey, coppiedsomeValuesOfVariablesVec[i]));
		}
	} while (permutationAndcombination++);

	//这一段测试map的key能否通过vector查找到，答案是肯定的
	//std::vector<int> findit(interactionDimension);
	//findit[0] = 3; findit[1] = 20;
	//UncoverMap::iterator iter;
	//iter = uncover.find(findit);
	//if (iter != uncover.end())
	//{
	//	std::cout << "find it success!" << std::endl;
	//	iter->second;
	//}
	//else
	//{
	//	std::cout << "can't find it";
	//}

	

	int a = 1;

}

double CombinatorialTest::CombinationNum(int VariableNum, int CombiNum)
{
	double result = Fac(VariableNum) / (Fac(CombiNum)*Fac(VariableNum - CombiNum));
	return result;
}
int CombinatorialTest::Fac(int num)
{
	int facresult = 1;
	while (num){
		facresult *= num;
		--num;
	}
	return facresult;
}

bool CombinatorialTest::UncoverIsNotNULL()
{
	return !uncover.empty();
}

void CombinatorialTest::AETG(const int candidateNum)
{
	//初始化uncover和中间变量map
	InitUncover();
	srand((unsigned)time(NULL));//重新设定以下随机种子
	rand();
	while (UncoverIsNotNULL())//算法的开始条件
	{
		//存放candidate行迭代器，最后选出一行作为采用的
		std::vector<std::vector<UncoverMap::iterator>> AllItersInVec(candidateNum);
		//存放candidate行后选集取值，根据选出的迭代器的行数确定选出的测试用例
		std::vector<std::vector<int>> candidateTestCases(candidateNum);
		for (int i = 0; i < candidateNum;++i)//初始化一下这个候选测试集
		{
			srand((unsigned)time(NULL));
			rand();
			std::vector<int> testcase(expressionLength);
			for (int j = 0; j < expressionLength; ++j)
			{
				testcase[j] = rand() % 2;//给里面赋值随机的0或1，以防后患
			}
			candidateTestCases[i]= testcase;
		}
		for (int M = 0; M < candidateNum; ++M)//选出candidateNum个候选测试用例，然后选出一个覆盖最多的
		{
			//第一步，找到出现次数最多的f以及他的取值i
			std::map<std::vector<int>, int>::const_iterator iter = numOfAValueAppeared.begin();
			std::map<std::vector<int>, int>::const_iterator maxValueiter = iter;//这里先赋值，再++
			++iter;
			for (; iter != numOfAValueAppeared.end(); ++iter)
			{
				if (iter->second > maxValueiter->second){
					maxValueiter = iter;
				}

			}
			std::vector<int> pickedSubscripts; //按顺序记录已经被选中的下标
			pickedSubscripts.push_back(maxValueiter->first[0]);//将第一个被选中的下标加入
			candidateTestCases[M][maxValueiter->first[0]] = maxValueiter->first[1];//将第一个确定的取值按位置存好
			std::vector<int> surplusSubscripts;//记录还有哪些下标没有被选中
			for (int i = 0; i < expressionLength; ++i)//初始化这个剩余下标vector
			{
				if (i != maxValueiter->first[0])
				{
					surplusSubscripts.push_back(i);
				}
			}
			
			for (int i = 0; i < expressionLength - 1; ++i)
				/**这个for循环做到以下事情：
				随机产生一个下标，
				*/
			{
				
				int pickednum = rand() % surplusSubscripts.size();
				int pickedF = surplusSubscripts[pickednum];
				surplusSubscripts.erase(surplusSubscripts.begin() + pickednum);//在候选f中去掉这个选中的
				//接下来，让这个被选中的下标一一与之前已选中的下标进行两两组合，选出一个出现次数最多的取值组合
				for (int j = 0; j < pickedSubscripts.size(); ++j)
				{
					//这里存放两行迭代器，一行是取值为0的时候的指向Uncover中每一个组合的迭代器，另一行是取值为1的情况
					std::vector<std::vector<std::map<std::vector<int>, std::vector<int>>::iterator>> readyToClearUncoverIters(3);
					//首先，构造一个vector，保存两个下标，以此为key去uncover中寻找
					std::vector<int> twoSubscripts(2);
					bool positionOfpickedSubscripts = 0;
					if (pickedF < pickedSubscripts[j])//下标需要小的在前大的在后，不然会找不到
					{
						twoSubscripts[0] = pickedF;
						twoSubscripts[1] = pickedSubscripts[j];
						positionOfpickedSubscripts = 1;
					}
					else{
						twoSubscripts[0] = pickedSubscripts[j];
						twoSubscripts[1] = pickedF;
						
					}
					//开始寻找这个组合是否存在
					UncoverMap::iterator CombiOfF = uncover.find(twoSubscripts);
					if (CombiOfF != uncover.end())
					{
						//遍历依下这个组合的取值，找出找出符合条件的并放入存放Iterator的vector  readyToClearUncoverIters中
						for (int k = 0; k != uncover.count(twoSubscripts); ++k,++CombiOfF)
						{
							if (CombiOfF->second[positionOfpickedSubscripts] == candidateTestCases[M][pickedSubscripts[j]])
							{
								readyToClearUncoverIters[CombiOfF->second[!positionOfpickedSubscripts]].push_back(CombiOfF);
							}
						}
					}
					//readyToClearUncoverIters中已经存好了当前f在取值为0和1的情况下与uncover相交的iter，下面要判断取0还是取1
					if (readyToClearUncoverIters[0].size() > readyToClearUncoverIters[1].size())
					{
						///readyToClearUncoverIters[2] = readyToClearUncoverIters[0];//取0
						
						for (int x = 0; x < readyToClearUncoverIters[0].size();++x)
						{
							AllItersInVec[M].push_back(readyToClearUncoverIters[0][x]);//把迭代器都拎出来
						}
						candidateTestCases[M][twoSubscripts[!positionOfpickedSubscripts]] = 0;
					}
					else{
						//readyToClearUncoverIters[2] = readyToClearUncoverIters[1];//取1
						for (int x = 0; x < readyToClearUncoverIters[1].size(); ++x)
						{
							AllItersInVec[M].push_back(readyToClearUncoverIters[1][x]);
						}
						candidateTestCases[M][twoSubscripts[!positionOfpickedSubscripts]] = 1;
					}
				}
				pickedSubscripts.push_back(pickedF);//该把选好的下标放进去准备下一次循环，选择下一个f了
			}//以上代码未解决问题，确定好的迭代器们要放进另一个容器以便最后确定删除的时候一起删除，确定好的取值要保存下来，不然之后不知道这一位到底取值是几,已解决
		}
		//现在有AllItersInVec和candidateTestCases，选好删好重置好。
		int pickOneCase = 0;
		for (int i = 1; i < candidateNum; ++i)
		{
			if (AllItersInVec[i].size()>AllItersInVec[pickOneCase].size())
			{
				pickOneCase = i;
			}
		}
		CoverArray.push_back(candidateTestCases[pickOneCase]);
		//还差一步，减掉该减的
		std::map<std::vector<int>, int>::iterator numiter;
		std::vector<int> VectoFind(interactionDimension);
		for (int i = 0; i < AllItersInVec[pickOneCase].size(); ++i)
		{
			
			for (int j = 0; j < AllItersInVec[pickOneCase][i]->first.size(); ++j)
			{
				VectoFind[0] = AllItersInVec[pickOneCase][i]->first[j];
				VectoFind[1] = AllItersInVec[pickOneCase][i]->second[j];
				numiter = numOfAValueAppeared.find(VectoFind);
				if (numiter != numOfAValueAppeared.end())
				{
					numiter->second = numiter->second - 1;
					std::cout << "现在tempiter->second的值为" << numiter->second << std::endl;
					if (numiter->second == 0)
					{
						numOfAValueAppeared.erase(numiter);
						
					}
				}
			}
			uncover.erase(AllItersInVec[pickOneCase][i]);
		}
	}

}

void CombinatorialTest::PrintCoverArray()
{
	
	for (CoverArrayVector::const_iterator iter = CoverArray.begin(); iter != CoverArray.end(); iter++)
	{
		for (int i = 0; i < expressionLength; ++i)
		{
			std::cout << (*iter)[i] ;
		}
		std::cout << "\n";
	}
	/*int a = 4;
	PermutationAndCombination permutationAndcombination(a,20);
	do{
		for (int i = 0; i < a; ++i){
			std::cout << permutationAndcombination.number[i];
		}
		std::cout << std::endl;
	} while (permutationAndcombination++);*/
}