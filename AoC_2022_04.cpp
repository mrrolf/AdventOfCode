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

#include "AoC_2022_04.h"

void Advent_2022_04::Calculate()
{
	const char* input = Utils::ReadInput( "2022_04.txt" );
	int len = (int)strlen( input );
	int pos = 0;
	int count1 = 0;
	int count2 = 0;
	while( pos < len ) {
		char buff[32];
		Utils::GetNextLine( input, pos, buff );
		uint32_t min1, max1, min2, max2;

		int buffPos = 0;
		if( !Utils::GetNextUint( buff, buffPos, min1 ) ) printf( "Debug\n" );
		if( !Utils::GetNextUint( buff, ++buffPos, max1 ) ) printf( "Debug\n" );
		if( !Utils::GetNextUint( buff, ++buffPos, min2 ) ) printf( "Debug\n" );
		if( !Utils::GetNextUint( buff, ++buffPos, max2 ) ) printf( "Debug\n" );

		if( ( min1 <= min2 && max1 >= max2 ) ||
			( min2 <= min1 && max2 >= max1 ) )
			count1++;

		if( ( min1 <= min2 && max1 >= min2 ) ||
			( min2 <= min1 && max2 >= min1 ) )
			count2++;
	}


	int answer1 = count1;
	int answer2 = count2;
	printf( "Advent_2022_04   %d     %d\n", answer1, answer2 );
}
