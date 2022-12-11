#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <stack>
#include <malloc.h>

#include "MD5.h"
#include "Utils.h"

class Advent_2022_05 {
public:
	static bool sPart2;

	struct MoveData {
		int num;
		int src;
		int dst;
	};

	typedef std::vector<char> Stack;
	typedef std::vector<Stack> Stacks;
	typedef std::vector<MoveData> Moves;

	static void InitNewStack( Stacks& stacks, const char* input );

	static void Print( Stacks& stacks );

	static void Init( Stacks& stacks );

	static void Move( Stacks& stacks, int num, int src, int dest );

	static void PopulateMoves( Moves& moves );

	static std::string GetTopItems( Stacks& stacks );

	static void Calculate();
};

