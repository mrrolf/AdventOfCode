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

#include "AoC_2022_03.h"


uint64_t Advent_2022_03::GetLetterRank( char c ) {
	uint64_t rank = 0;
	if( islower( c ) )
		rank = ( c - 'a' ) + 1;
	else
		rank = ( c - 'A' ) + 27;
	return rank;
}

int Advent_2022_03::Part1( const char* input ) {
	int totalLen = (int)strlen( input );
	int pos = 0;
	int totalScore = 0;
	while( pos < totalLen ) {
		char buff[512];
		Utils::GetNextLine( input, pos, buff );

		int sackSize = (int)strlen( buff ) / 2;
		uint64_t s1 = 0, s2 = 0;
		for( int i = 0; i < sackSize; i++ ) {
			s1 |= 1ULL << GetLetterRank( buff[i] );
			s2 |= 1ULL << GetLetterRank( buff[i + sackSize] );
		}

		uint64_t common = s1 & s2;
		for( int i = 0; i < sizeof( uint64_t ) * 8; i++ ) {
			if( ( common & ( 1ULL << i ) ) != 0 ) {
				totalScore += i;
				break;
			}
		}
	}
	return totalScore;
}

int Advent_2022_03::Part2( const char* input ) {
	int totalLen = (int)strlen( input );
	int pos = 0;
	int totalScore = 0;
	while( pos < totalLen ) {
		char buff1[512];
		char buff2[512];
		char buff3[512];
		Utils::GetNextLine( input, pos, buff1 );
		Utils::GetNextLine( input, pos, buff2 );
		Utils::GetNextLine( input, pos, buff3 );

		uint64_t s1 = 0, s2 = 0, s3 = 0;;
		for( int i = 0; i < (int)strlen( buff1 ); i++ )
			s1 |= 1ULL << GetLetterRank( buff1[i] );
		for( int i = 0; i < (int)strlen( buff2 ); i++ )
			s2 |= 1ULL << GetLetterRank( buff2[i] );
		for( int i = 0; i < (int)strlen( buff3 ); i++ )
			s3 |= 1ULL << GetLetterRank( buff3[i] );

		uint64_t common = s1 & s2 & s3;
		for( int i = 0; i < sizeof( uint64_t ) * 8; i++ ) {
			if( ( common & ( 1ULL << i ) ) != 0 ) {
				totalScore += i;
				break;
			}
		}
	}
	return totalScore;
}

void Advent_2022_03::Calculate()
{
	const char* input = Utils::ReadInput( "2022_03.txt" );

	printf( "Advent_2022_03   %d     %d\n", Part1( input ), Part2( input ) );
}
