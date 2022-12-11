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

class Advent_2022_07 {
public:

	class Directory {
	public:
		Directory( const std::string& n, Directory* p ) : directSize( 0 ), indirectSize( 0 ), name( n ), parent( p ) {}
		void AddFile( const std::string& fileName, size_t size );
		void AddTryDir( const std::string& newName, Directory* parent );
		Directory* GetChild( const std::string& dirName );
		size_t CalculateIndirectSize();

		size_t directSize;
		size_t indirectSize;
		Directory* parent;
		std::map<std::string,Directory*> children;
		std::string name;
	};

	static Directory* rootDir;
	static Directory* cwd;

	static void PopulateDirs();
	static size_t SumAtMost( Directory* dir, size_t maxSize );
	static size_t FindClosestTo( Directory* dir, size_t desiredSize );

	static void Calculate();
};

