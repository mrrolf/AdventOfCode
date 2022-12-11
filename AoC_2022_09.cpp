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

#include "AoC_2022_09.h"

Advent_2022_09::VisitedGrid Advent_2022_09::visted;


Advent_2022_09::Rope::Rope(){
	for (int i = 0; i < Advent_2022_09::Rope::NumKnots; i++) 
	{
		knots[i].x = 0;
		knots[i].y = 0;
	}
}

void Advent_2022_09::Rope::MarkTail() {
	visted.insert(std::make_pair(knots[Advent_2022_09::Rope::NumKnots-1].x, knots[Advent_2022_09::Rope::NumKnots - 1].y));
}

int Advent_2022_09::Rope::KnotAtPos(int x, int y) {
	for (int i = 0; i < NumKnots; i++) {
		if (knots[i].x == x && knots[i].y == y)
			return i;
	}
	return -1;
}

void Advent_2022_09::UpdateRope(int dX, int dY, Advent_2022_09::Rope& rope) {
	rope.knots[0].x += dX;
	rope.knots[0].y += dY;

	for (int i = 0; i < rope.NumKnots - 1; i++) {
		Advent_2022_09::IntPos& headPos = rope.knots[i];
		Advent_2022_09::IntPos& tailPos = rope.knots[i+1];

		int deltaX = headPos.x - tailPos.x;
		int deltaY = headPos.y - tailPos.y;

		if (abs(deltaX) > 1) {
			tailPos.x += deltaX > 0 ? 1 : -1;
			tailPos.y += deltaY == 0 ? 0 : deltaY > 0 ? 1 : -1;
		}
		else if (abs(deltaY) > 1) {
			tailPos.x += deltaX == 0 ? 0 : deltaX > 0 ? 1 : -1;
			tailPos.y += deltaY > 0 ? 1 : -1;
		}
	}

	rope.MarkTail();
}

void Advent_2022_09::DoMove( char direction, int steps, Advent_2022_09::Rope& rope ) {
	int dX = 0;
	int dY = 0;
	switch( direction ) {
	case 'U': dY = 1;  break;
	case 'D': dY = -1; break;
	case 'L': dX = -1;  break;
	case 'R': dX = 1; break;
	}

	while( steps-- > 0 ) {
		UpdateRope( dX, dY, rope );
	}
}

void Advent_2022_09::Calculate() {
	const char* input = Utils::ReadInput( "2022_09.txt" );
	int len = (int)strlen( input );
	int pos = 0;

	Advent_2022_09::Rope rope;
	rope.MarkTail();

	while( pos < len ) {
		char buff[32];
		Utils::GetNextLine( input, pos, buff );

		DoMove( buff[0], atoi( buff + 1 ), rope );
	}
	printf( "Advent_2022_09   %zu\n", visted.size() );
}
