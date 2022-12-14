#pragma  once

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


#pragma region ColorDefinitions

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#pragma endregion


class GraphNodeBase
{
public:

	void AddConnection( GraphNodeBase*  node, float cost );

	std::vector<GraphNodeBase*> connections;
	std::vector<float>	costs;
	mutable const GraphNodeBase* pathNode = nullptr;
};

template<class T>
class GraphNode : public GraphNodeBase {
public:
	T val;

	GraphNode() {}
	GraphNode( T v ) {
		val = v;
	}
};


class GraphPath {
public:

	typedef bool( IsEndFn )( const GraphNodeBase* );

	GraphPath() :cost( 0.0f ) {}

	void AddNode( const GraphNodeBase*  node );
	void Finalize();

	float cost;
	std::vector<const GraphNodeBase*> nodes;
};

class Graph
{
public:
	Graph() {}

	std::vector<GraphNodeBase*> nodes;
};


class Utils
{
public:
	static char* ReadInput( const char* fileName );
	static bool IsSpaceChar( char c );
	static void GetNextLine( const char* input, int& pos, char* buff );
	static void GetNextLine2(const char* input, int& pos, char* buff);
	static void Tokenize(char* input, std::vector<std::string>& tokens);
	static void Tokenize(char* input, const char* delim, std::vector<std::string>& tokens);
	static void SkipPastNumber(const char* input, int& pos);
	static bool IsInteger(const char* input, int pos);
	static int GetNextBoolAndAdvance(const char* input, int& pos);
	static bool GetNextUint(const char* input, int& pos, uint32_t& number);
	static char PeekNextChar(const char* input, int pos);
	static GraphPath FindShortestPath( Graph* graph, GraphNodeBase* start, GraphPath::IsEndFn* fn = nullptr);
};


