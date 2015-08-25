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
	//�����ʼ��CoverArray��ʹ�ó�ʼ��������initTestCasesNum��expressionLength�����ʼ����һ�������Ĳ�������
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
	//���һ�������ʼ����coverarray
	/*for (CoverArrayVector::const_iterator iter = CoverArray.begin(); iter != CoverArray.end(); iter++)
	{
		for (int i = 0; i < expressionLength; ++i)
		{
			std::cout << (*iter)[i];
		}
		std::cout << "\n";
	}*/

	//���³�ʼ��uncover��ʹ�ø�����interactionDimension����ʼ��������
	std::vector<std::vector<int>> someValuesOfVariablesVec;
	Binary binary(interactionDimension);   //ʹ��Binary������ɶ�һЩ����ȡֵ�ĸ�ֵ
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

	//���³�ʼ���м����numOfAValueAppeared����һ������f�Լ���ֵi��uncover�г��ֵĴ���
	int appearNum = CombinationNum(expressionLength - 1, interactionDimension - 1) * 2;//�����2����Ϊÿ����ϵ�ÿ������F����ȡֵΪ0��1���������
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
	//���¿�ʼɾ��uncover�к�numOfAValueAppeared�еĳ�ʼ�����Ѿ������˵�Ԫ�أ�����
	//����Ӧ��дһ�����󣬿��԰�ָ��������������ϸ��г�������Ϊkey�������Ǹ������map��Ϊvalue��������һ���ܵ�uncovermap
	PermutationAndCombination permutationAndcombination(interactionDimension, expressionLength);
	do{
		//std::vector<int> everyfacflag(expressionLength);
		//for (int i = 0; i < expressionLength; ++i)
		//{
		//	everyfacflag[i] = 0;
		//}//����������������һ��vector��ʹ��һ�������һ������������һ�Σ������ظ���
		std::vector<std::vector<int>> coppiedsomeValuesOfVariablesVec = someValuesOfVariablesVec;//�������ԣ������ֵ�����Ǹ��������
		std::vector<int> uncoverKey(interactionDimension);
		std::vector<std::vector<int>> value; //������������������ȡֵ��
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
					std::cout << "�ɹ��ҵ���Ҫ������uncover��" << std::endl;
					//ɾ���ɹ�����ȥ�м�����������Ӧ�Ĵ�������  ------------   ΪKeyȥnumOfAValueAppeared��
					std::vector<int> tempKey(2);
					for (int k = 0; k < uncoverKey.size(); ++k){

						tempKey[0] = uncoverKey[k];
						tempKey[1] = (*iter)[k];

						std::map<std::vector<int>, int>::iterator tempiter = numOfAValueAppeared.find(tempKey);
						if (tempiter != numOfAValueAppeared.end())
						{
							tempiter->second = tempiter->second - 1;
							std::cout << "����tempiter->second��ֵΪ" << tempiter->second << std::endl;
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

	//��һ�β���map��key�ܷ�ͨ��vector���ҵ������ǿ϶���
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
	//��ʼ��uncover���м����map
	InitUncover();
	srand((unsigned)time(NULL));//�����趨�����������
	rand();
	while (UncoverIsNotNULL())//�㷨�Ŀ�ʼ����
	{
		//���candidate�е����������ѡ��һ����Ϊ���õ�
		std::vector<std::vector<UncoverMap::iterator>> AllItersInVec(candidateNum);
		//���candidate�к�ѡ��ȡֵ������ѡ���ĵ�����������ȷ��ѡ���Ĳ�������
		std::vector<std::vector<int>> candidateTestCases(candidateNum);
		for (int i = 0; i < candidateNum;++i)//��ʼ��һ�������ѡ���Լ�
		{
			srand((unsigned)time(NULL));
			rand();
			std::vector<int> testcase(expressionLength);
			for (int j = 0; j < expressionLength; ++j)
			{
				testcase[j] = rand() % 2;//�����渳ֵ�����0��1���Է���
			}
			candidateTestCases[i]= testcase;
		}
		for (int M = 0; M < candidateNum; ++M)//ѡ��candidateNum����ѡ����������Ȼ��ѡ��һ����������
		{
			//��һ�����ҵ����ִ�������f�Լ�����ȡֵi
			std::map<std::vector<int>, int>::const_iterator iter = numOfAValueAppeared.begin();
			std::map<std::vector<int>, int>::const_iterator maxValueiter = iter;//�����ȸ�ֵ����++
			++iter;
			for (; iter != numOfAValueAppeared.end(); ++iter)
			{
				if (iter->second > maxValueiter->second){
					maxValueiter = iter;
				}

			}
			std::vector<int> pickedSubscripts; //��˳���¼�Ѿ���ѡ�е��±�
			pickedSubscripts.push_back(maxValueiter->first[0]);//����һ����ѡ�е��±����
			candidateTestCases[M][maxValueiter->first[0]] = maxValueiter->first[1];//����һ��ȷ����ȡֵ��λ�ô��
			std::vector<int> surplusSubscripts;//��¼������Щ�±�û�б�ѡ��
			for (int i = 0; i < expressionLength; ++i)//��ʼ�����ʣ���±�vector
			{
				if (i != maxValueiter->first[0])
				{
					surplusSubscripts.push_back(i);
				}
			}
			
			for (int i = 0; i < expressionLength - 1; ++i)
				/**���forѭ�������������飺
				�������һ���±꣬
				*/
			{
				
				int pickednum = rand() % surplusSubscripts.size();
				int pickedF = surplusSubscripts[pickednum];
				surplusSubscripts.erase(surplusSubscripts.begin() + pickednum);//�ں�ѡf��ȥ�����ѡ�е�
				//���������������ѡ�е��±�һһ��֮ǰ��ѡ�е��±����������ϣ�ѡ��һ�����ִ�������ȡֵ���
				for (int j = 0; j < pickedSubscripts.size(); ++j)
				{
					//���������е�������һ����ȡֵΪ0��ʱ���ָ��Uncover��ÿһ����ϵĵ���������һ����ȡֵΪ1�����
					std::vector<std::vector<std::map<std::vector<int>, std::vector<int>>::iterator>> readyToClearUncoverIters(3);
					//���ȣ�����һ��vector�����������±꣬�Դ�Ϊkeyȥuncover��Ѱ��
					std::vector<int> twoSubscripts(2);
					bool positionOfpickedSubscripts = 0;
					if (pickedF < pickedSubscripts[j])//�±���ҪС����ǰ����ں󣬲�Ȼ���Ҳ���
					{
						twoSubscripts[0] = pickedF;
						twoSubscripts[1] = pickedSubscripts[j];
						positionOfpickedSubscripts = 1;
					}
					else{
						twoSubscripts[0] = pickedSubscripts[j];
						twoSubscripts[1] = pickedF;
						
					}
					//��ʼѰ���������Ƿ����
					UncoverMap::iterator CombiOfF = uncover.find(twoSubscripts);
					if (CombiOfF != uncover.end())
					{
						//�������������ϵ�ȡֵ���ҳ��ҳ����������Ĳ�������Iterator��vector  readyToClearUncoverIters��
						for (int k = 0; k != uncover.count(twoSubscripts); ++k,++CombiOfF)
						{
							if (CombiOfF->second[positionOfpickedSubscripts] == candidateTestCases[M][pickedSubscripts[j]])
							{
								readyToClearUncoverIters[CombiOfF->second[!positionOfpickedSubscripts]].push_back(CombiOfF);
							}
						}
					}
					//readyToClearUncoverIters���Ѿ�����˵�ǰf��ȡֵΪ0��1���������uncover�ཻ��iter������Ҫ�ж�ȡ0����ȡ1
					if (readyToClearUncoverIters[0].size() > readyToClearUncoverIters[1].size())
					{
						///readyToClearUncoverIters[2] = readyToClearUncoverIters[0];//ȡ0
						
						for (int x = 0; x < readyToClearUncoverIters[0].size();++x)
						{
							AllItersInVec[M].push_back(readyToClearUncoverIters[0][x]);//�ѵ������������
						}
						candidateTestCases[M][twoSubscripts[!positionOfpickedSubscripts]] = 0;
					}
					else{
						//readyToClearUncoverIters[2] = readyToClearUncoverIters[1];//ȡ1
						for (int x = 0; x < readyToClearUncoverIters[1].size(); ++x)
						{
							AllItersInVec[M].push_back(readyToClearUncoverIters[1][x]);
						}
						candidateTestCases[M][twoSubscripts[!positionOfpickedSubscripts]] = 1;
					}
				}
				pickedSubscripts.push_back(pickedF);//�ð�ѡ�õ��±�Ž�ȥ׼����һ��ѭ����ѡ����һ��f��
			}//���ϴ���δ������⣬ȷ���õĵ�������Ҫ�Ž���һ�������Ա����ȷ��ɾ����ʱ��һ��ɾ����ȷ���õ�ȡֵҪ������������Ȼ֮��֪����һλ����ȡֵ�Ǽ�,�ѽ��
		}
		//������AllItersInVec��candidateTestCases��ѡ��ɾ�����úá�
		int pickOneCase = 0;
		for (int i = 1; i < candidateNum; ++i)
		{
			if (AllItersInVec[i].size()>AllItersInVec[pickOneCase].size())
			{
				pickOneCase = i;
			}
		}
		CoverArray.push_back(candidateTestCases[pickOneCase]);
		//����һ���������ü���
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
					std::cout << "����tempiter->second��ֵΪ" << numiter->second << std::endl;
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