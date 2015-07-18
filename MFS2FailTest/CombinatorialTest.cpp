#include "stdafx.h"
#include <random>


CombinatorialTest::CombinatorialTest(const int expressionLength, const int interactionDimension,int initTestCasesNum) :
expressionLength(expressionLength),
interactionDimension(interactionDimension),
initTestCasesNum(initTestCasesNum)
{
}


CombinatorialTest::~CombinatorialTest()
{
}

void CombinatorialTest::InitUncover()
{
	
}
inline bool CombinatorialTest::UncoverIsNotNULL()
{
	return !uncover.empty();
}

void CombinatorialTest::AETG(const int candidateNum)
{

}