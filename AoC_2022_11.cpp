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
#include <inttypes.h>

#include "MD5.h"
#include "Utils.h"

#include "AoC_2022_11.h"

Advent_2022_11::Monkeys Advent_2022_11::monkeys;
int Advent_2022_11::part = 1;
uint64_t Advent_2022_11::Monkey::lCD = 1;

uint64_t Advent_2022_11::Monkey::NewValue( uint64_t item ) {
	switch( op )
	{
	case Advent_2022_11::Monkey::NONE:
		break;
	case Advent_2022_11::Monkey::ADD:
		return item + opArg;
	case Advent_2022_11::Monkey::MULT:
		return item * opArg;
	case Advent_2022_11::Monkey::SQUARE:
		return item * item;
	};

	printf( "Shouldn't get here\n" );
	return 0;
}

bool Advent_2022_11::Monkey::PassesTest( uint64_t item) {
	return ( item % testArg ) == 0;
}

void Advent_2022_11::Monkey::DoTurn() {
	for( auto i : items ) {

		uint64_t val = NewValue( i );

		if( Advent_2022_11::part == 1 )
			val = val / 3;

		int newMokeyIndex = falseMonkey;
		if( PassesTest( val ) ) {
			newMokeyIndex = trueMonkey;
		}

		monkeys[newMokeyIndex]->GiveItem( val );

		inspectionCount++;
	}

	items.clear();
}

void Advent_2022_11::Monkey::GiveItem( uint64_t item ) {
	items.push_back( item % lCD );
}

void Advent_2022_11::PopulateMonkeys() {
	const char* input = Utils::ReadInput( "2022_11.txt" );
	int len = (int)strlen( input );
	int pos = 0;
	while( pos < len )
	{
		char buff[512];
		Utils::GetNextLine( input, pos, buff );
		// should be Monkey
		if( strstr( buff, "Monkey" ) == buff ) {
			vector<string> tokens;
			Utils::Tokenize( buff, tokens );

			int monkeyIndex = atoi( tokens[1].c_str() );
			Monkey* monkey = new Monkey();

			// starting items
			Utils::GetNextLine( input, pos, buff );
			Utils::Tokenize( buff, tokens );
			for( int i = 2; i < tokens.size(); i++ ) {
				monkey->items.push_back( atoi( tokens[i].c_str() ) );
			}

			// Operation
			Utils::GetNextLine( input, pos, buff );
			Utils::Tokenize( buff, tokens );
			if( tokens[4][0] == '+' ) {
				monkey->op = Monkey::ADD;
				monkey->opArg = atoi( tokens[5].c_str() );
			}
			else if( tokens[4][0] == '*' ) {
				if( tokens[5] == "old" ) {
					monkey->op = Monkey::SQUARE;
					monkey->opArg = 0;
				}
				else {
					monkey->op = Monkey::MULT;
					monkey->opArg = atoi( tokens[5].c_str() );
				}
			}

			// Test
			Utils::GetNextLine( input, pos, buff );
			Utils::Tokenize( buff, tokens );
			if( tokens[1] == "divisible" ) {
				monkey->testArg = atoi( tokens[3].c_str() );
			}

			// True Monkey
			Utils::GetNextLine( input, pos, buff );
			Utils::Tokenize( buff, tokens );
			monkey->trueMonkey = atoi( tokens[5].c_str() );


			// False Monkey
			Utils::GetNextLine( input, pos, buff );
			Utils::Tokenize( buff, tokens );
			monkey->falseMonkey = atoi( tokens[5].c_str() );

			monkeys.insert( make_pair( monkeyIndex, monkey ) );

			// update LCD
			Monkey::lCD *= monkey->testArg;
		}
	}
}

void Advent_2022_11::DoRound() {
	for( auto m : monkeys ) {
		m.second->DoTurn();
	}
}

void Advent_2022_11::Calculate() {
	PopulateMonkeys();

	part = 2;

	int numRounds = part == 1 ? 20 : 10000;
	while( numRounds-- > 0 ) {
		DoRound();
	}

	vector<uint64_t> scores;
	for( auto m : monkeys )
		scores.push_back( m.second->inspectionCount );

	sort( scores.begin(), scores.end() );
	auto iter = scores.rbegin();

	uint64_t answer = (*iter++) * (*iter);
	printf( "Advent_2022_11    part %d  - %" PRId64 "\n", part, answer );
}
