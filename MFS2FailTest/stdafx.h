// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"
#include "FailTest.h"
#include "Binary.h"
#include "TraverseFolder.h"
#include "MFSToFailTest.h"
#include "RepRandom.h"
#include "FiltFiles.h"
#include "CombinatorialTest.h"
#include "PermutationAndCombination.h"
#include <stdio.h>
#include <time.h>
#include <tchar.h>
#include <vector>
#include <set>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <regex>
// TODO: reference additional headers your program requires here

template <typename T1,typename T2>
T2 convertTo(T1 a)
{
	T2 b;
	std::stringstream ss;
	ss << a;
	ss >> b;
	return b;
}