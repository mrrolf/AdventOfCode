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

#include "AoC_2022_02.h"



void Advent_2022_02::Calculate()
	{
	const char* input = Utils::ReadInput("2022_02.txt");
	int len = (int)strlen(input);
	int pos = 0, score1 = 0, score2 = 0;
	constexpr int diff = 'X' - 'A';
	while (pos < len) {
		char buff[8];
		Utils::GetNextLine(input, pos, buff);
		char opponent = buff[0];
		char self = buff[2];
		score1 += (self - 'W');		// what did we play
		score2 += (self - 'X') * 3;	// did we win
		score1 += (((self - diff) - opponent +4) % 3) * 3;
		score2 += (((opponent - 'A') + (self - 'Y') + 3) % 3) + 1;
	}
	printf("Advent_2022_02    %d    %d\n", score1, score2);
}