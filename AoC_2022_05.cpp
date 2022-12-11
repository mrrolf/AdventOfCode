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

#include "AoC_2022_05.h"


bool Advent_2022_05::sPart2 = false;

void Advent_2022_05::InitNewStack( Advent_2022_05::Stacks& stacks, const char* input) {
	stacks.push_back( Advent_2022_05::Stack());
	Stack& stack = stacks[stacks.size() - 1];
	int len = (int)strlen(input);
	for (int i = 0; i < len; i++) {
		stack.push_back(input[i]);
	}
}

void Advent_2022_05::Print( Advent_2022_05::Stacks& stacks) {
	int height = 0;
	for (auto iter : stacks)
		height = std::max(height, (int)iter.size());

	int width = (int)stacks.size();
	for (int h = height; h >= 0; h--) {
		for (int w = 0; w < width; w++) {
			Stack& stack = stacks[w];
			if (stack.size() > h)
				printf("[%c] ", stack[h]);
			else 
				printf("    ");
		}
		printf("\n");
	}
	for (int w = 0; w < width; w++) {
		printf(" %d  ", w + 1);
	}
	printf("\n");
}

void Advent_2022_05::Init( Advent_2022_05::Stacks& stacks) {
	InitNewStack(stacks, "HTZD");
	InitNewStack(stacks, "QRWTGCS");
	InitNewStack(stacks, "PBFQNRCH");
	InitNewStack(stacks, "LCNFHZ");
	InitNewStack(stacks, "GLFQS");
	InitNewStack(stacks, "VPWZBRCS");
	InitNewStack(stacks, "ZFJ");
	InitNewStack(stacks, "DLVZRHQ");
	InitNewStack(stacks, "BHGNFZLD");
}

void Advent_2022_05::Move( Advent_2022_05::Stacks& stacks, int num, int src, int dest) {
	// data is 1-based
	Advent_2022_05::Stack& srcStack = stacks[src - 1];
	Advent_2022_05::Stack& destStack = stacks[dest - 1];

	if (!sPart2) {
		for (int i = 0; i < num; i++) {
			destStack.push_back(srcStack.back());
			srcStack.pop_back();
		}
	}
	else {
		size_t startIndex = srcStack.size() - num;
		destStack.insert(destStack.end(), srcStack.begin() + startIndex, srcStack.end());
		for (int i = 0; i < num; i++)
			srcStack.pop_back();
	}
}

void Advent_2022_05::PopulateMoves( Advent_2022_05::Moves& moves) {
	const char* input = Utils::ReadInput("2022_05.txt");
	int len = (int)strlen(input);
	int pos = 0;

	// read past the header
	while (pos < len) {
		char buff[256];
		Utils::GetNextLine2(input, pos, buff);
		if (strlen(buff) == 0)
			break;
	}

	while (pos < len) {
		char buff[256];
		Utils::GetNextLine2(input, pos, buff);
		std::vector<std::string> tokens;
		Utils::Tokenize(buff, tokens);

		Advent_2022_05::MoveData m;
		m.num = atoi(tokens[1].c_str());
		m.src = atoi(tokens[3].c_str());
		m.dst = atoi(tokens[5].c_str());

		moves.push_back(m);
	}
}

std::string Advent_2022_05::GetTopItems( Advent_2022_05::Stacks& stacks) {
	std::string answer;

	for (auto stack : stacks) {
		char buff[2] = { '\0' };
		buff[0] = stack.back();
		answer.append(buff);
	}

	return answer;
}

void Advent_2022_05::Calculate() {
	Advent_2022_05::Moves moves;
	PopulateMoves(moves);

	// Part 1
	sPart2 = false;
	Advent_2022_05::Stacks stacks;
	Init(stacks);

	for (auto iter : moves)
		Move(stacks, iter.num, iter.src, iter.dst);

	Print(stacks);
	auto answer1 = GetTopItems(stacks);

	// Part2
	sPart2 = true;
	stacks.clear();
	Init(stacks);

	for (auto iter : moves)
		Move(stacks, iter.num, iter.src, iter.dst);

	Print(stacks);
	auto answer2 = GetTopItems(stacks);

	printf("Advent_2022_05   %s    %s\n", answer1.c_str(), answer2.c_str());
}


