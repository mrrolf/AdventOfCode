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

class Advent_2022_10 {
public:
	static void Cycle();
	static void Calculate();
	static void PrintCRT();

	static int cycleCount;
	static int part1Sum;
	static int registerX;

	static char crt[];
};

