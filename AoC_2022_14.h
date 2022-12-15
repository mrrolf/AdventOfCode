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

class Advent_2022_14 {
public:

	class Map {
	public:

		char Get( int x, int y );
		void Set( int x, int y, char c);
		void ExpandBounds( int x, int y );
		void Allocate();
		void AddLine( const std::vector<std::pair<int, int>>& line );
		void Print();
		bool AddSand(int x, int y);

		int minX = INT_MAX;
		int maxX = INT_MIN;
		int height = 0;
		int width = 0;

		char** blocks = nullptr;

		static const char AIR = '.';
		static const char ROCK = '#';
		static const char SAND = 'O';
		static const char HOLE = '+';
	};

	static Map map;

	static void PopulateMap();
	static void Calculate();
};

