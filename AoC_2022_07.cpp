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

#include "AoC_2022_07.h"



Advent_2022_07::Directory* Advent_2022_07::rootDir = nullptr;
Advent_2022_07::Directory* Advent_2022_07::cwd = nullptr;

void Advent_2022_07::Directory::AddFile(const std::string& fileName, size_t size) {
	directSize += size;
}

void Advent_2022_07::Directory::AddTryDir(const std::string& newName, Advent_2022_07::Directory* parent) {
	auto iter = children.find(newName);
	// already exists
	if (iter != children.end())
		return;

	Advent_2022_07::Directory* newChild = new Advent_2022_07::Directory(newName, parent);
	children.insert(std::make_pair(newName, newChild));
}

Advent_2022_07::Directory* Advent_2022_07::Directory::GetChild(const std::string& dirName) {
	auto iter = children.find(dirName);
	return iter->second;
}

size_t Advent_2022_07::Directory::CalculateIndirectSize() {
	indirectSize = directSize;
	for (auto c : children)
		indirectSize += c.second->CalculateIndirectSize();
	return indirectSize;
}


void Advent_2022_07::PopulateDirs() {
	const char* input = Utils::ReadInput("2022_07.txt");
	int len = (int)strlen(input);
	int pos = 0;

	char buff[128];
	while (pos < len) {
		Utils::GetNextLine(input, pos, buff);
		std::vector<std::string> tokens;
		Utils::Tokenize(buff, tokens);

		if (tokens[1] == "cd")
		{
			std::string& newDirName = tokens[2];
			if (newDirName == "/") {
				cwd = rootDir;
			}
			else if (newDirName == "..") {
				cwd = cwd->parent;
			}
			else {
				Advent_2022_07::Directory* newDir = cwd->GetChild(newDirName);
				cwd = newDir;
			}
		}
		if (tokens[1] == "ls") {
			// need to peak at the next line
			char peekChar = Utils::PeekNextChar(input, pos);
			while (peekChar != '$' && pos < len )
			{
				Utils::GetNextLine(input, pos, buff);
				std::vector<std::string> tokens;
				Utils::Tokenize(buff, tokens);

				if (tokens[0] == "dir") {
					cwd->AddTryDir(tokens[1], cwd);
				}
				else {
					size_t fileSize = atoi(tokens[0].c_str());
					cwd->AddFile(tokens[1], fileSize);
				}
				peekChar = Utils::PeekNextChar(input, pos);
			}
		}
	}
}

size_t Advent_2022_07::SumAtMost( Advent_2022_07::Directory* dir, size_t maxSize) {
	size_t total = 0;
	if (dir->indirectSize <= maxSize)
		total += dir->indirectSize;

	for (auto c : dir->children) {
		total += SumAtMost(c.second, maxSize);
	}

	return total;
}

size_t Advent_2022_07::FindClosestTo( Advent_2022_07::Directory* dir, size_t desiredSize) {
	if (dir->indirectSize < desiredSize)
		return 0;

	size_t bestSize = dir->indirectSize;
	for (auto c : dir->children) {
		size_t s = FindClosestTo(c.second, desiredSize);
		if (s >= desiredSize)
			bestSize = std::min(bestSize, s);
	}
	return bestSize;
}

void Advent_2022_07::Calculate() {
	rootDir = new Advent_2022_07::Directory("/", nullptr);
	cwd = rootDir;
		
	PopulateDirs();
	cwd = rootDir;
	rootDir->CalculateIndirectSize();

	size_t part1 = SumAtMost(rootDir, 100000);

	size_t currFreeSpace = 70000000 - rootDir->indirectSize;
	size_t requiredSize = 30000000 - currFreeSpace;
	size_t part2 = FindClosestTo(rootDir, requiredSize);

	printf("Advent_2022_07    %zu     %zu\n", part1, part2);
}

