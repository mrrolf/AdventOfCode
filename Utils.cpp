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
#include <float.h>

#include "Utils.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
char* Utils::ReadInput(const char* fileName) {
	string filePath = ".\\adventInput\\";
	filePath.append(fileName);

	FILE* fp = nullptr;
	fopen_s(&fp, filePath.c_str(), "rb");
	if (fp == nullptr)
		return nullptr;

	fseek(fp, 0L, SEEK_END);
	size_t fileSize = ftell(fp);
	rewind(fp);

	char* contents = (char* )malloc(fileSize + 1);
	fread((void*)contents, 1, fileSize, fp);
	fclose(fp);

	contents[fileSize] = '\0';
	return contents;
}


///////////////////////////////////////////////////////////////////////////////
bool Utils::IsSpaceChar(char c) {
	return c == '\t' || c == '\n' || c == ' ' || c == '\r';
}

///////////////////////////////////////////////////////////////////////////////
void Utils::GetNextLine(const char* input, int& pos, char* buff) {
	size_t len = strlen(input);
	if (pos >= len)
		return;

	// skip to next alphaNumeric
	while (pos < len && IsSpaceChar(input[pos])) {
		pos++;
	}

	int i = 0;
	// skip to next alphaNumeric

	while (pos < len && !(input[pos] == '\n' || input[pos] == '\r')) {
		buff[i++] = input[pos++];
	}

	buff[i] = '\0';
}

///////////////////////////////////////////////////////////////////////////////
void Utils::GetNextLine2(const char* input, int& pos, char* buff) {
	size_t len = strlen(input);
	if (pos >= len)
		return;

	int i = 0;
	while (pos < len && !(input[pos] == '\n' || input[pos] == '\r')) {
		buff[i++] = input[pos++];
	}

	if (input[pos] == '\r') pos++;
	if (input[pos] == '\n') pos++;

	buff[i] = '\0';
}

///////////////////////////////////////////////////////////////////////////////
void Utils::Tokenize(char* input, vector<string>& tokens) {
	tokens.clear();
	Tokenize(input, " ", tokens);
}

///////////////////////////////////////////////////////////////////////////////
void Utils::Tokenize(char* input, const char* delim, vector<string>& tokens) {
	char* context = nullptr;
	char* token = strtok_s(input, delim, &context);
	while (token != nullptr) {
		tokens.push_back(token);
		token = strtok_s(nullptr, delim, &context);
	} ;
}

///////////////////////////////////////////////////////////////////////////////
void Utils::SkipPastNumber(const char* input, int& pos) {
	while (Utils::IsInteger(input, pos)) pos++;
}

///////////////////////////////////////////////////////////////////////////////
bool Utils::IsInteger(const char* input, int pos) {
	return input[pos] == '-' || isdigit(input[pos]);
}

///////////////////////////////////////////////////////////////////////////////
int Utils::GetNextBoolAndAdvance(const char* input, int& pos) {
	int newNum = atoi(input + pos);
	Utils::SkipPastNumber(input, pos);
	return newNum;
}

///////////////////////////////////////////////////////////////////////////////
bool Utils::GetNextUint(const char* input, int& pos, uint32_t& number) {
	while (!isdigit(input[pos]) && input[pos] != '\0') pos++;
	if (input[pos] == '\0')
		return false;

	number = (uint32_t)atoi(input + pos);
	while (isdigit(input[pos]) && input[pos] != '\0') pos++;
	return true;
}

///////////////////////////////////////////////////////////////////////////////
char Utils::PeekNextChar(const char* input, int pos) {
	int peekPos = pos;
	while (input[peekPos] != '\0' && IsSpaceChar(input[peekPos])) peekPos++;
	return input[peekPos];
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void GraphNodeBase::AddConnection( GraphNodeBase*  node, float cost ) {
	connections.push_back( node );
	costs.push_back( cost );
}

///////////////////////////////////////////////////////////////////////////////
void GraphPath::AddNode( const GraphNodeBase*  node ) {
	nodes.push_back( node );
}

///////////////////////////////////////////////////////////////////////////////
void GraphPath::Finalize() {
	reverse( nodes.begin(), nodes.end() );
}

///////////////////////////////////////////////////////////////////////////////
GraphPath Utils::FindShortestPath( Graph* graph, GraphNodeBase* start, GraphPath::IsEndFn* endFn ) {
	if( !start || !endFn || !graph ) {
		return GraphPath();
	}

	// Init
	unordered_set<const GraphNodeBase*> visited;
	multimap<float, const GraphNodeBase*> notVisited;
	unordered_map<const GraphNodeBase*, float> notVisitedLookup;
	unordered_map<const GraphNodeBase*, const GraphNodeBase*> pathToNode;
	//for( const GraphNodeBase* node : graph->nodes ) {
	//	distToNode.insert( make_pair( node, FLT_MAX ) );
	//}
	const GraphNodeBase* currNode = start;

	pathToNode.insert( make_pair( currNode, nullptr ) );

	//distToNode[currNode] = 0.0f;
	float currCost = 0.0f;

	while( true )
	{
		// push the next connections onto the stack
		for( int i = 0; i < (int)( currNode->connections.size() ); i++ ) {
			const GraphNodeBase* possibleNode = currNode->connections[i];

			// if already visited, continue
			if( visited.find( possibleNode ) != visited.end() )
				continue;

			float newCost = currCost + currNode->costs[i];

			// add or update to unvisited set
			auto iter = notVisitedLookup.find( possibleNode );
			if( iter == notVisitedLookup.end() )
			{
				notVisitedLookup.insert( make_pair(possibleNode, newCost) );
				notVisited.insert( make_pair( newCost, possibleNode ) );
				pathToNode.insert( make_pair( possibleNode, currNode ) );
			}
			else
			{
				if( notVisitedLookup[possibleNode] > newCost ) {
					float oldCost = notVisitedLookup[possibleNode];
					auto mmIter = notVisited.find( oldCost );
					for( ; mmIter != notVisited.end(); mmIter++ )
					{
						if( mmIter->second == possibleNode )
							break;
					}
					notVisited.erase( mmIter );
					notVisited.insert( make_pair( newCost, possibleNode ) );

					pathToNode[possibleNode, currNode];
					notVisitedLookup[possibleNode] = newCost;
				}
			}
			//if( newCost > distToNode[possibleNode] )
			//	continue;
		}

		// we've exhausted our options, no path
		if( notVisited.size() == 0 ) {
			return GraphPath();
		}

		// pick the next node
		const GraphNodeBase* bestNextNode = notVisited.begin()->second;
		float bestNextNodeCost = notVisited.begin()->first;
		notVisited.erase( notVisited.begin() );

		//notVisitedLookup.erase( notVisitedLookup.find( bestNextNode ) );

		currNode = bestNextNode;
		currCost = bestNextNodeCost;


		// we're done!
		if( endFn( bestNextNode ) ) {
			GraphPath path;
			path.cost = currCost;

			const GraphNodeBase* n = bestNextNode;
			while( n != nullptr ) {
				path.AddNode( n );

				if( pathToNode.find( n ) == pathToNode.end() )
					break;

				n = pathToNode[n];
			}
			path.Finalize();

			return path;

		}
	}

	// now to backward through the nodes to get the path


	// not sure what happened
	return GraphPath();
}