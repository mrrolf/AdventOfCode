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

#include "AoC_2022_01.h"


uint32_t Advent_2022_01::GetTopCalories(int num, std::set<uint32_t>& elves) {
	uint32_t ret = 0;

	auto iter = elves.rbegin();
	for( int i = 0; i < num; i++ )
	{
		ret += *iter;
		iter++;
	}

	return ret;
}

void Advent_2022_01::Calculate()	{
	const char* input = Utils::ReadInput( "2022_01.txt" );

	int len = (int)strlen( input );
	int pos = 0;

	std::set<uint32_t> elves;
	uint32_t currCount = 0;
	while( pos < len ) {
		char buff[64] = {'\0'};
		Utils::GetNextLine2( input, pos, buff );

		if( strlen( buff ) == 0 ) {
			elves.insert( currCount );
			currCount = 0;
			continue;
		}

		currCount += atoi( buff );
	}
	elves.insert( currCount );

	uint32_t firstPart = GetTopCalories( 1, elves );
	uint32_t secondPart = GetTopCalories( 3, elves );
	printf( "Advent_2022_01    %u    %u\n", firstPart, secondPart );


}

