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

class Advent_2022_09 {
public:

	struct IntPos{
		int x;
		int y;
	};

	struct Rope {
		static constexpr const int NumKnots = 10;
		IntPos knots[NumKnots];
		Rope();
		void MarkTail();
		int KnotAtPos( int x, int y );
	};

	typedef std::set<std::pair<int, int>> VisitedGrid;
	static VisitedGrid visted;

	static void UpdateRope( int dX, int dY, Rope& rope );

	static void DoMove( char direction, int steps, Rope& rope );

	static void Calculate();
};

