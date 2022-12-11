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

#include "AoC_2022_06.h"


bool Advent_2022_06::ValidWindow( const char* input, int windowSize ) {
	for( int i = 0; i < windowSize - 1; i++ ) {
		for( int j = i + 1; j < windowSize; j++ ) {
			if( input[i] == input[j] ) {
				return false;
			}
		}
	}
	return true;
}

void Advent_2022_06::Calculate() {
	const char* input = Utils::ReadInput( "2022_06.txt" );
	int len = (int)strlen( input );
	int part2 = false;
	int windowSize = part2 ? 4 : 14;
	int pos = 0;

	int start = -1;
	while( ( pos + windowSize ) < len ) {
		if( ValidWindow( input + pos, windowSize ) ) {
			start = pos + windowSize;
			break;
		}
		else {
			pos++;
		}
	}

	printf( "Advent_2022_06   %d\n", start );
}

