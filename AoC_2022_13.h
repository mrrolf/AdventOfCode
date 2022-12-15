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

class Advent_2022_13 {
public:

	struct Clump;
	struct Variant {
		Variant() : num (-1) , clump(nullptr) {}
		Variant(int i) : num( i ), clump( nullptr ) {}
		Variant(Clump* c) : num( -1 ), clump( c ) {}

		bool IsInt() const { return num != -1; }
		bool IsClump() const { return clump != nullptr; }

		int num;
		Clump* clump;
	};

	struct Clump {
		std::vector<Variant> values;
		Clump* parent = nullptr;
		bool marker = false;
	};


	static int Part1( const char *input );
	static int Part2( const char *input );
	static void Print( const Clump* c, bool root = true );
	static Clump* ParseClump( const char* input );
	static int Compare( const Clump* c1, const Clump* c2 );

	static void Calculate();
};

