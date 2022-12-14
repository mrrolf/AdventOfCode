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

class Advent_2022_12 {
public:


	struct Coord {
		Coord( ) {
			x = -1;
			y = -1;
			val = '#';
		}

		Coord( int _x, int _y, char _v ) {
			x = _x;
			y = _y;
			val = _v;
		}

		int x = -1;
		int y = -1;
		char val;
	};

	typedef GraphNode<Coord> GNode;

	static void Calculate();
	static void PopulateFromInput( Graph* graph, GNode*& start, GNode*& end );
	static int Index( int width, int x, int y );
};

