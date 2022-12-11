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

#include "AoC_2022_08.h"




Advent_2022_08::Grid::Grid(const char* fileName) {
	const char* input = Utils::ReadInput("2022_08.txt");
	int len = (int)strlen(input);
	int pos = 0;
	while (pos < len) {
		char buff[512];
		Utils::GetNextLine(input, pos, buff);
		SizeX = (int)strlen(buff);
		data.push_back(std::string(buff));
	}
	SizeY = (int)data.size();
}


int Advent_2022_08::Grid::Get(int x, int y) {
	return data[y][x] - '0';
}

int Advent_2022_08::Grid::GetIncreasingCount( int startX, int startY, int dX, int dY ) {
	int x = startX;
	int y = startY;


	int count = 0;
	int curr = -1;

	while( x >= 0 && y >= 0 && x < SizeX && y < SizeY ) {
		int d = Get( x, y );
		if( d > curr ) {
			curr = d;
			count++;
			visible.insert( std::make_pair( x, y ) );
		}
		x += dX;
		y += dY;
	}
	return count;
}

int Advent_2022_08::Grid::GetSeeCount( int startX, int startY, int dX, int dY ) {
	int count = 0;
	int curr = -1;
	int startingHeight = Get( startX, startY );
	int x = startX + dX;
	int y = startY + dY;
	while( x >= 0 && y >= 0 && x < SizeX && y < SizeY ) {
		int d = Get( x, y );
		count++;

		if( d >= startingHeight )
			break;
		x += dX;
		y += dY;
	}
	return count;
}

int Advent_2022_08::Grid::GetBestScore() {

	int bestScore = 0;
	for( int x = 0; x < SizeX; x++ ) {
		for( int y = 0; y < SizeX; y++ ) {

			if( x == 2 && y == 3 )
				printf( "debug" );

			int score = GetSeeCount( x, y, 1, 0 );
			score *= GetSeeCount( x, y, -1, 0 );
			score *= GetSeeCount( x, y, 0, 1 );
			score *= GetSeeCount( x, y, 0, -1 );

			bestScore = std::max( score, bestScore );
		}
	}

	return bestScore;
}


void Advent_2022_08::Calculate() {
	Advent_2022_08::Grid grid( "2022_08.txt" );

	for( int i = 0; i < grid.SizeX; i++ ) {
		grid.GetIncreasingCount( i, 0, 0, 1 );
		grid.GetIncreasingCount( i, grid.SizeY - 1, 0, -1 );
	}
	for( int i = 0; i < grid.SizeY; i++ ) {
		grid.GetIncreasingCount( 0, i, 1, 0 );
		grid.GetIncreasingCount( grid.SizeX - 1, i, -1, 0 );
	}

	int answer = (int)grid.visible.size();
	int bestScore = grid.GetBestScore();
	printf( "Advent_2022_08    %d    %d", answer, bestScore );
}

