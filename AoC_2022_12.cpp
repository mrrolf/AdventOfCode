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

#include "AoC_2022_12.h"

using namespace std;

int Advent_2022_12::Index( int width, int x, int y ) {
	// width +1 to account for \n
	int index = x + ( y * ( width) );
	return index;
}

void Advent_2022_12::PopulateFromInput( Graph* graph, GNode*& start, GNode*& end ) {
	char* input = Utils::ReadInput( "2022_12.txt" );
	int len = (int)strlen( input );
	int pos = 0;

	// Get info on the grid
	int width = 0;
	int height = 0;
	int totalSize = 0;
	int currPos = 0;
	for( int i = 0; i < len; i++ )
	{
		if( !Utils::IsSpaceChar( input[i] ) )
		{
			input[currPos++] = input[i];
		}
		if( (input[i] == '\n' || input[i] == '\r') && width == 0 )
			width = i;
	}
	totalSize = currPos;
	height = totalSize / ( width );


	GNode** nodes = new GNode*[totalSize];
	for( int y = 0; y < height; y++ ) {
		for( int x = 0; x < width; x++ ) {
			int i = Index( width, x, y );
			nodes[i] = new GNode( Coord(x,y, input[i]) );
			graph->nodes.push_back( nodes[i] );
		}
	}

	auto fn = [] (int width, int height, int nx, int ny, char currHeight, const char* input, GNode** nodes, GNode* node ) {
		if( nx >= 0 && nx < width && ny >= 0 && ny < height ) {
			char nextVal = input[Index( width, nx, ny )];
			if( nextVal == 'S' )
				nextVal = 'a';
			if( nextVal == 'E' )
				nextVal = 'z';

			if( nextVal >= ( currHeight - 1 ) )
				node->AddConnection( nodes[Index( width, nx, ny )], 1 );
		}
	};

	for( int y = 0; y < height; y++ ) {
		for( int x = 0; x < width; x++ ) {
			int index = Index( width, x, y );
			GNode* node = nodes[index];
			char currHeight = input[index];

			if( input[index] == 'S' )
			{
				end = node;
				currHeight = 'a';
			}
			else if( input[index] == 'E' ) {
				start = node;
				currHeight = 'z';
			}

			fn( width, height, x + 0, y - 1, currHeight, input, nodes, node );
			fn( width, height, x + 0, y + 1, currHeight, input, nodes, node );
			fn( width, height, x - 1, y + 0, currHeight, input, nodes, node );
			fn( width, height, x + 1, y + 0, currHeight, input, nodes, node );
		}
	}

	delete[] nodes;
}

void Advent_2022_12::Calculate() {
	Graph* graph = new Graph();
	GNode* start = nullptr;
	GNode* end = nullptr;

	PopulateFromInput( graph, start, end );

	auto fn = []( const GraphNodeBase* node ) -> bool {
		const GNode* gNode = static_cast<const GNode*>( node );
		return gNode->val.val == 'a';
	};

	auto path = Utils::FindShortestPath( graph, start, fn );

	int answer = (int)path.cost;
	printf( "Advent_2022_12    %d\n", answer );
}
