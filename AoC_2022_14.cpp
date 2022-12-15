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

#include "AoC_2022_14.h"

using namespace std;


Advent_2022_14::Map Advent_2022_14::map;

void Advent_2022_14::Map::ExpandBounds( int x, int y ) {
	height = max( height, y + 1 );
	minX = min( minX, x-1 );
	maxX = max( maxX, x+1 );
	width = ( maxX - minX ) + 1;
}

void Advent_2022_14::Map::Allocate() {
	blocks = new char*[height];
	for( int i = 0; i < height; i++ ) {
		blocks[i] = new char[width];
		memset( blocks[i], AIR, width );
	}
}

char Advent_2022_14::Map::Get( int x, int y ) {
	x = x - minX;
	return blocks[y][x];
}

void Advent_2022_14::Map::Set( int x, int y, char c ) {
	x = x - minX;
	blocks[y][x] = c;
}

void Advent_2022_14::Map::Print() {
	for( int y = 0; y < height; y++ ) {
		for( int x = 0; x < width; x++ ) {
			printf( "%c", blocks[y][x] );
		}
		printf( "\n" );
	}
	printf( "\n" );
}

void Advent_2022_14::Map::AddLine( const vector<pair<int, int>>& line ) {
	pair<int, int> start = *( line.begin() );

	Set( start.first, start.second, ROCK );

	for( int i = 1; i < line.size(); i++ )
	{
		pair<int, int> next = line[i];
		int len = 0;
		int dx = 0;
		if( abs( next.first - start.first ) > 0 ) {
			dx = ( next.first - start.first ) > 0 ? 1 : -1;
			len = abs( next.first - start.first );
		}
		int dy = 0;
		if( abs( next.second - start.second ) > 0 ) {
			dy = ( next.second - start.second ) > 0 ? 1 : -1;
			len = abs( next.second - start.second );
		}

		while( len > 0 ) {
			Set( start.first + ( dx*len ), start.second + ( dy*len ), ROCK );
			len--;
		}

		start = next;
	}
}

bool Advent_2022_14::Map::AddSand( int x, int y ) {

	while( (y+1) < height )
	{
		char c = Get( x, y+1 );
		if( c == AIR ) {
			// continue
			y++;
		}
		else if( Get( x-1, y + 1 ) == AIR ) {
			x--;
			y++;
		}
		else if( Get( x + 1, y + 1 ) == AIR ) {
			x++;
			y++;
		}
		else {
			// everything is blocked
			Set( x, y, SAND );
			if( y == 0 )
				return false;
			return true;
		}
	};

	return false;
}


void Advent_2022_14::PopulateMap() {
	const char* input = Utils::ReadInput( "2022_14.txt" );
	int pos = 0;
	int len = (int)strlen( input );

	vector < vector<pair<int, int>>> lines;

	while( pos < len ) {
		char buff[1024];
		Utils::GetNextLine( input, pos, buff );

		vector<string> tokens;
		Utils::Tokenize( buff, tokens );
		vector<pair<int, int>> line;
		// yes increment by 2 each iteration
		for( int i = 0; i < tokens.size(); i +=2 ) {
			int x = atoi( tokens[i].c_str() );
			int comma = 1;
			while( tokens[i][comma] != ',' ) comma++;
			int y = atoi( tokens[i].c_str() + (comma+1) );

			map.ExpandBounds( x, y );
			line.push_back( make_pair( x, y ) );
		}
		lines.push_back( line );
	}

	
	vector<pair<int, int>> floor;
	floor.push_back( make_pair( 500 - (map.height+1), map.height + 1 ) );
	floor.push_back( make_pair( 500 + (map.height+1), map.height + 1 ) );
	map.ExpandBounds( floor[0].first, floor[0].second );
	map.ExpandBounds( floor[1].first, floor[1].second );
	lines.push_back( floor );

	map.Allocate();

	for( auto line : lines ) {
		map.AddLine( line );
	}
	map.Set( 500, 0, Map::HOLE );
}

void Advent_2022_14::Calculate() {
	PopulateMap();
	map.Print();

	int grains = 1;
	while( map.AddSand( 500, 0 ) )
		grains++;

	map.Print();

	printf( "Advent_2022_14    %d\n", grains);
}
