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

class Advent_2022_08 {
public:

	class Grid {
	public:
		Grid( const char* fileName );
		int Get( int x, int y );
		int GetIncreasingCount( int startX, int startY, int dX, int dY );
		int GetSeeCount( int startX, int startY, int dX, int dY );
		int GetBestScore();

		int SizeX;
		int SizeY;
		std::vector<std::string> data;
		std::set<std::pair<int, int>> visible;
	};
	
	static void Calculate();
};
