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

using namespace std;

class Advent_2022_11 {
public:

	class Monkey {
	public:

		enum Operation {
			NONE = 0,
			ADD,
			MULT,
			SQUARE,
		};

		Monkey() : inspectionCount(0)
		{}

		void DoTurn();

		uint64_t NewValue( uint64_t item );
		bool PassesTest( uint64_t item);
		void GiveItem( uint64_t item );

		vector<uint64_t> items;
		Operation op;
		int opArg;
		int testArg;
		int trueMonkey;
		int falseMonkey;

		int inspectionCount;

		static uint64_t lCD;
	};


	static void PopulateMonkeys();
	static void DoRound();
	static void Calculate();


	typedef map<int,Monkey*> Monkeys;
	static Monkeys monkeys;
	static int part;
};

