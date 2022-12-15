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

#include "AoC_2022_13.h"

using namespace std;

Advent_2022_13::Clump* Advent_2022_13::ParseClump( const char* input ) {
	Advent_2022_13::Clump* root = new Advent_2022_13::Clump();
	Advent_2022_13::Clump* curr = root;

	int len = (int)strlen( input );
	for( int i = 1; i < len; i++ ) {
		char c = input[i];
		if( c == '[' ) {
			// new clump
			Advent_2022_13::Clump* n = new Advent_2022_13::Clump();
			curr->values.push_back( Variant( n ) );
			n->parent = curr;
			curr = n;
		}
		else if( c == ']' ) {
			// back up one
			curr = curr->parent;
		}
		else if( isdigit( c ) ) {
			int number = atoi( input + i );
			curr->values.push_back( Variant( number ) );
			if( number > 9 )
				i++;
		}
	}
	return root;
}

int Advent_2022_13::Compare( const Advent_2022_13::Clump* c1, const Advent_2022_13::Clump* c2 ) {

	int i = 0;
	while( true )
	{
		// both ran out
		if( i >= c1->values.size() && i >= c2->values.size() )
			return 0;
		// left runs out
		if( i >= c1->values.size() )
			return 1;
		// right runs out
		if( i >= c2->values.size() )
			return -1;

		const Variant& v1 = c1->values[i];
		const Variant& v2 = c2->values[i];

		if( v1.IsInt() && v2.IsInt() ) {
			if( v1.num < v2.num )
				return 1;
			if( v1.num > v2.num )
				return -1;
		}

		else if( v1.IsClump() && v2.IsClump() ) {
			int result = Compare( v1.clump, v2.clump );
			if( result != 0 )
				return result;
		}

		else if( v1.IsInt() && v2.IsClump()) {
			Clump newC;
			newC.values.push_back( Variant( v1.num ) );
			int result = Compare( &newC, v2.clump );
			if( result != 0 )
				return result;
		}

		else if( v1.IsClump() && v2.IsInt()) {
			Clump newC;
			newC.values.push_back( Variant( v2.num ) );
			int result = Compare( v1.clump, &newC );
			if( result != 0 )
				return result;
		}
		else {
			printf( "Debug\n" );
		}


		i++;
	}
}

void Advent_2022_13::Print( const Advent_2022_13::Clump* c, bool root ) {
	printf( "[" );

	for( int i = 0; i < c->values.size(); i++ ) {
		const auto& v = c->values[i];
		if( v.IsInt() )
			printf( "%d", v.num );
		else
			Print( v.clump, false);

		if( (i + 1) < c->values.size() )
			printf( "," );
	}
	printf( "]" );
	if( root )
		printf( "\n" );
}

int Advent_2022_13::Part1(const char *input ) {
	int len = (int)strlen( input );
	int pos = 0;

	int sum = 0;
	int index = 1;
	while( pos < len ) {
		char buff1[1024];
		char buff2[1024];

		Utils::GetNextLine( input, pos, buff1 );
		Utils::GetNextLine( input, pos, buff2 );

		auto c1 = ParseClump( buff1 );
		auto c2 = ParseClump( buff2 );

		if( Compare( c1, c2 ) == 1 )
			sum += index;


		index++;
	}
	return sum;
}

int Advent_2022_13::Part2( const char *input ) {
	int len = (int)strlen( input );
	int pos = 0;

	int sum = 0;
	vector<const Clump*> clumps;

	while( pos < len ) {
		char buff[1024];
		Utils::GetNextLine( input, pos, buff );
		auto clump = ParseClump( buff );
		clumps.push_back( clump );
	}
	// add 2 static clumps
	auto* marker1 = ParseClump( "[[2]]" );
	marker1->marker = true;
	clumps.push_back( marker1 );

	auto* marker2 = ParseClump( "[[6]]" );
	marker2->marker = true;
	clumps.push_back( marker2 );

	// sort the clumps
	sort( clumps.begin(), clumps.end(),
		[]( const Clump*& c1, const Clump*& c2 ) -> bool
		{
			return Compare( c1, c2 ) > 0;
		} );

	// Find the index of the markers
	int pos1 = -1;
	int pos2 = -1;
	for( int i = 0; i < clumps.size(); i++ )
	{
		if( clumps[i]->marker ) {
			if( pos1 < 0 )
				pos1 = i + 1;
			else
				pos2 = i + 1;
		}
	}

	return pos1 * pos2;
}

void Advent_2022_13::Calculate() {
	const char* input = Utils::ReadInput( "2022_13.txt" );
	int part1 = Part1( input );
	int part2 = Part2( input );
	printf( "Advent_2022_13    %d    %d\n", part1, part2);
}
