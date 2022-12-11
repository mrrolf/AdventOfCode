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

#include "AoC_2022_10.h"

using namespace std;

int Advent_2022_10::cycleCount = 0;
int Advent_2022_10::part1Sum = 0;
int Advent_2022_10::registerX = 1;
char Advent_2022_10::crt[240];

void Advent_2022_10::Cycle() {

	char toDisplay = '.';
	int toTest = cycleCount % 40;
	if( registerX >= ( toTest - 1 ) && registerX <= ( toTest + 1 ) )
		toDisplay = '#';
	crt[cycleCount] = toDisplay;

	cycleCount++;
	if( ( cycleCount - 20 ) % 40 == 0 ) {
		part1Sum += ( cycleCount * registerX );
	}
}

void Advent_2022_10::PrintCRT() {
	for( int y = 0; y < 6; y++ ) {
		for( int x = 0; x < 40; x++ ) {
			int pos = ( y * 40) + x;
			printf( "%c", crt[pos] );
		}
		printf( "\n" );
	}
}

void Advent_2022_10::Calculate() {

	const char* input = Utils::ReadInput( "2022_10.txt" );
	int len = (int)strlen( input );
	int pos = 0;


	int cycle = 0;

	while( pos < len ) {
		char buff[64];
		Utils::GetNextLine( input, pos, buff );

		vector<string> tokens;
		Utils::Tokenize( buff, tokens );

		if( tokens[0] == "noop" ) {
			Cycle();
		}
		else if( tokens[0] == "addx" ) {
			Cycle();
			Cycle();
			registerX += atoi( tokens[1].c_str() );
		}

	}
	PrintCRT();
	int part1 = part1Sum;
	printf( "Advent_2022_10    %d\n", part1 );
}
