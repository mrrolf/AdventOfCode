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

class Advent_2022_03 {
public:
	static uint64_t GetLetterRank( char c );

	static int Part1( const char* input );

	static int Part2( const char* input );

	static void Calculate();
};

