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

class Advent_2015_01 {
public:
	static void Calculate1();
	static void Calculate2();
};

class Advent_2015_02 {
public:
	static int GetNextNumber( int& pos, size_t len );
	static void EatNonNumeric( int& pos, size_t len );
	static void Calculate1();
};

class Advent_2015_03 {
	static constexpr const char* input = R"(^^<<v<<v><v^^<><>^^<v<v^>>^^^><^>v^>v><><><<vv^^<^>^^<v^>v>v^v>>>^<>v<^<v^><^>>>>><<v>>^>>^>v^>><<^>v>v<>^v^v^vvv><>^^>v><v<><>^><^^<vv^v<v>^v>>^v^>v><>v^<vv>^><<v^>vv^<<>v>>><<<>>^<vv<^<>^^vv>>>^><<<<vv^v^>>><><^>v<>^>v<v^v<^vv><^v^><<<<>^<>v>^v>v<v<v<<>v<^<<<v>>>>>^^v>vv^^<>^<>^^^^<^^^v<v^^>v<^^v^^>v>^v^^^^>><<v<>v<>^v^<v<>><>^^><<^^<^^>vv<>v^<^v<vv<<<>^>^^>^<>v^^vv<>>v><<<>vvv<>v<>><^<^v<>^vv>^^v<v<v><^<>>vv<^>>^>>vv^v<vv^vv<^<<>>^v^<>^>>>>vv>^^>v>vv>v><^vv^<<v>^<<^^<v<v>vv<v^^<>^^v>^>>v><^<<vv<<v^vv^^^v>>v<<v^><vv^><vv<^vv<<vv^v<<^v<^^v>><<v^>>^^<>v>><<v<>>^^<v>>^^>>vvv^><<<<<^<^vv<^<><v<<>^^^<<<^>^^^<v<<vv>vv<>^<>v<^v>^<<<v<v<v>>^v<>>v<<^<<v<<>^<<<><><>^>>>>^>v^v<<v<v<<>>vv<^vvv^^^^<vv>vv>^v^^v^<v^v><^vv<^vv>v<^>vv<>>^>^><vv<><^>v>^v>vvv<>^>^v<><>vv>><^v^<><><v>>v^v^><^<^>vv>v<^>vvv>v<<<<<^<v<<vv<^^^<<>>^v<vv<^<>v>^<v<>><><>^<<v>v^>^<vv>><><>>^>^>><^<v>^^>^^>^^v^^<^v^^>v^^>>><<><v<v<<v^vv<><><>^<v>^<<^^v^>v>><>^^^><^vvv<^^^^^v><<><v<^^v><><>>^>vv<vvvv<<>>><v<^^^^v<<^><v>^vv<v^^v^vv<^^>^^<v>><<v^>v<^^>^<^<v<^^v>^<<v>^>>>^v<>v<^^^>vvv^v<<^><>>><vvv^<^^^<^>>v>>><v>^^vvv^vvv<^^^^v^v^<vv^<v>^<<^>v^v^<<><>><^v><v<><<>><<<>^v>v<>^<v^v>^vv>>^<>v^^<<v><^v>>v<>>^v^^>><^>v^<^v^^>><>v^>^v^v<<<v^<v^^v<^>v<><>vv>>>>^>v<>v<<<>^^>vv^v<><v^<>^<<<<>>^^>^v<v^v<<><>^v<>>^v^<<^<^>>>^vv<><v<^^<>v^>>v<^^v<v>>>^>><<><<<>><vv<v>>^v>><^<v><vv>^vv<v<>>><>v^><>vv<^^v^^^v<>><^vvv<<^<>v>>>v>><v><>>><>><v^><v^v<v>^v>v<v>>^^<^>^>v><>vv>^v><<>>>>>>>^<<^vv^^vvvv<^^><<<v<<>vvv<>^><<v<v^v^<<v>v<>>^<vv^<v<v>^<<^^vv>v>^<vv<<>v<v^<>v>>^v^^vvvv>^^>>v^v^^><<^>v>>^^>^<^^<>v<v>vv^vv>v<v>>^v<><^vv^<vv<v^^^v<^v^>>^v>>>^^<^<^>^v^>^>>>^v>^>^^^>>^<>v^^<>^v<<^^>^^<vv<>v<^v^>><^v^>^<>>^vv^vv^>v^<vvvvvv^>><^^<^v<^<v^<<^^<<v^<^>><>v><^v^v^^^v>v^<>^<<v<^^vvv<v>^^>^v^^<><vv^v^>v^<<>>vv<>>>>v>v<>^>>>v<>^^><v<v^^^<>^<^><>^><<v>><>^<<>>><<^<vvv<^><v>>^vv^v>><v<>vv^<<^^<<><v><<^<v<vv<<^v^vv>v^>>>v<<<<v<<>v>^vv<^v><v<v>v<^>^^vv>v><v>><<v<<v^v>>><>^<>><><<^<<^v^v<<v>v>v<v<^^>vv<^v^^^<v^<<<v<>v^><^v>^<^<v>>^<<<v>>v^<><>>^v<>vvv<vvvvv<^^><^>><^^>^>^v^vv<^><<^v>><^^v>^v<>^>vvvv><^>^<<v^^vv<v^^<><>v>^>>^<^<<<^v^^^>^>>^>><><<^>v^^<v>>v<<<<vvv<vvvv^<^<v^^<>^>vvv^<vv^v^v>^<<><v><^v^v^^^>^^>^vv<>v>>v^>vv^vv>v<^v^^>>^v^v<>>^^><<v<<>><>>>^>^<>^^v^^><^<>><<^<vv^^^^^>>vv^<v^<^>>>>v<<><<^>vv>vvv>^<><>>>>vv><<v^v<^^^<<^^^vv^<v<><><<<<>><<v^<>v>v^><>v^v^^><>v>v>^^v<^v<>>^^^^^<v>><v^>^^<v>><v^^>v<^<^>>>^><^^>><<>>^><>^^^>v^^^>^^v^<>^^><^>>><><^>>v<v^>v<^><v<v^<>v<^v>v^<^vv^^><<<><><^v^<v<^^>v>v^>>^^vv^<v>^v>^<^v<>^>^><^<v>^v><^<^<>v^^>^><>>><<v><<><>v<<^v^^<^><>^<><><v>v<^^<v<v>>^^<<>>^<v>><^><^<^>^^v<>v>>><><<>^>v><><<<<v^^^^v<>>^^^v>><<^v>^>>><vv^>>^vv<^<>>^<^^<^v>v<v<<<<<>^<<^<<<<<^<^>>^><<>><>v^v>^<^>v^<><vvv^>^v^v^v><^<v<>vv<<^<>^^^<>^v>^<v^^<v^v>v<>>^>v<<>v<>v^v>v<<<>>v>vv>>v<<>v<>v<^>^>^<v>>v>^>^^^<vv>v<<>>><v>^vvv^^>^^<^vv^^^^>v>^v^>v^^v^>>^v>^vv>^^v^<<<<>^<><^<^<<^^>v^^^v<>>vvv<v>>vv><v<v>^<^v>>^v<vv^<<v<vv><^^v^v>v<>^v<<<^^v^^^<^v>v^v^v>><vvv<<>v<>^v>vv^v>vv<<^v<v>^v>v>><^v<v<>v>>>><<<><vv><>^v^<^vvv>v<>><^v>^>><v>vv<><><>v><>>><^>vv>>^<>v^>>^><<<^><<>^v^>>><><>vv>^<>^>^v^^><^>>><<>v^<^vv>^<^vv>><v<>vv<v><><<^><>v<^^<^>vv^^^^vv<<v><>vv<><v>v<>>>>^><v><>^<><>v<>><<>^^vvv>^^^<><>>vvv^v>><>vv<vv>^^^v^<<>^^v<><<^^v<>^^>^<^^v>>v^v^^>>v>>>^<<^<>^>^^v>>>><vv<<>^v<<vv><<^^vv><^>vv<>>v<v>v^>v>>v^<vv<<<v><v^>vvv^^>vv^<<v>v^>>v^<>>><><<^^<^v>^>>>v>v>^v<>vv><vv<vvv<<v>v>^v<<<>><<><><>v^>>>v^>v^>>vv^^<v>^<>>><^>v^<>^^><v>v<><<<><v^v<<<v<v^>v^v>^>v<^<>v>v^^>>v>vv^v<>>^^^^<>v^>>>>>>>><v<^<<vvv<^v^>^v<^<<>>><<<^<<^>^>v^<>^<<<>v>><^vv^>^>^>>>^<vv><v^^^<v^<v<><v^vvv<>v<vvv^vv<<<v^<^<^vvvv^<<vv<^v><<>^>^<v^v^<^>v^><>>v^>v^>^>>v<>vv^v<<>^^>>vv<>vv>>^v<^vv>^v>v<v^vvv^<<^><>v^<><vv><>v^^><<<><>^>^v^<>><vv<^>v^v>v<>><v<<^>^<vv<^v>^<<v><^<^^vv^<>><v^>^vv^<>>^^^^v>v><^^^v^<<<>^<^<<>><>>v<<^v^>><><v^>>^vv^v>vv>>>>>>^^<<>v^>v^v>^^>>><vv^^^v>^v>>^^^<>><>v^<<<v<vv^^<v^<<<>v>v^^^<vv<>>^v>^v<^<<><>vv>^^^<^^vv<v<<vv>^^>vv>v<<^>^vv><^><v>^^^^v<<vv>v^<<^^>>^^vvvv^v^>vv>>v^<v>vvv<>>^><>>v^^>>^<>>vvvv^>><v^v<^^<^vv>>v<<^<<^><v^^><v^>v^>><<<v>v>v^>^v<v^vv<^^^v<^<vvvvv<<vvv>><>v<v<v<<^v<><<>vv>><v>><^>>^^v>^>><>vv^><<>>vv<<<^<^^>^<<^>>>><v<^v<<<>>v>vv<^>^v><>>v<v^v<>v^vvvv>v^>>v><<^<v>^^v>>vv^^>v>^v>^v^^>^<^vv<v<<^>vv<<^>>^<<^^>>^<^>v^><^vv>^^v><v^>>><>v^v>^v<^><<<>vv><v>v<><>>v^<>^^>^<>^<<^>>vv^><^<v<^^vvv>>v^>>v^>v>vv><>>v<^>><<<v<<vv><v<v<v>v<v>vv^vvv^vv^>^>v><vv<v^^<>>>>vv^>^<>v<^>^<^v>vv<^<<>>^<^<vv><^^<>^<<v^v^>v<<><v>v>><^v<<^vvv>v>v<<^^<^^>v<vv<v<v^v>^^^>^>vv<v<<^^v^<v<^>^^^vv>v<>>>vv>><><^><><<<vvv<<^^v^<v^<<^>>vv>vv^v^>>><v><<v^v>>v>>vv>^^vvv^>^^>^>^>^v<<^vv^>vvv^^vv><^>^v^>^><>v<^^vv<v><v^<><^<>><v>^^v^v>v^vv<>><^v>^<^v>^<>^v>>>><<vv^^^vv^>>><vv^v>>v><^v^vv><<^v<<>^^<v><^v>vvv<><^^><<^v><>^<^v<^^<^vvvv^^>>>>vv>v>>>v<v^><<<<v>>v^><v>>vv^v<vv<>vv<>vvv>>>><>>><>^v<v^v><vvv<<v^^v^v<>>><>>^vv<<v<><<vv<v^>^^vv><^v^v<v^vvv^v>v^^^vv>^><^vvv<<>^vvv^<v<v^v>>>>^<<<><<<<<^v<^^>>>>^>^<v^^^v<vvv<vv^<>v<<<^<^>>v^<v><<><<^^vvv^>v<>>^^>v>^v>>v<v><v>>>>^<^<^>v^v<vv<>^>><>^<<^vvv^^<>^<vvv<>v^>^^<<^>^vv><vvv>>v^v^>v><v>^<^^<>^>^>>>^^vvv^<<>v^<<>><>v<^<^>v^>^vv><v<^<<<^v>^>>^<^v^<<<<^v^><v^v>v^><<v<><<v^<<^<<v<<v><v><><^^^^>v>^^<v>>v<vvv<<<>><>>^><<><^<>>^^>vv<^><^v^><vvv>>>vvv<<vv^<^^^<^>^<>>^>>^v^<^^v>^<v<<>^^v<^vv^><vvv>>^v><<^<v^<><><>>^>vv<<>^^^v^^<v<>><>>vv>v^>vvv^^v<vv<^<^>>^>>^>>v^<<<v^>v^<^v^vv^><^<^v<<v<<>v>^v^<<<v^vv<v<<>^^<v>>>^<v<^>^^v<v>>>><vv<^^<<>><<v<v>^^v^>>^^>>^v^<^v>v^v^v^v^>v^vv<><>^^<>^><^^^<<<^<v>v<<>^<^^^^^v^<^<<^^>^vv<>v^>><>>^>v>v<>^>v<v^>>><>^<><v>>>^>^>>v^><v<>v><^vv^>v<<v>v<><<vv<<v>^><^<v^>v<<v^v<<><v><>v<v><>^^<v<>><<>v>vv<<v>^v<v>vv><><>vv^<<>^>^<^>>>^v>v<^v^^^vv<>>>^<<^>>><<^^v^>v^<^v>vvv>v^^vv>^^>>v<>^<<>^<><^^v^>><>^>v>>^^^<<^^v<>^^>^<>^>><^>^vvv><^>^<^>^>>vv<^>>^v>>^<>>^^>>>v^<v>>v<<v<^>>v^^vv>v><^v^^><vv^v<^>v<<>v^^<><>^>vvv><^^^>^v^>v>>^vvv<^vv>^^>^>>v<>><<^v<<v^>^><>vv^<<^^vv><v>>^<^><^<v>^v<v>^<<>^v^^>v^>>^^^<^vv>v^>>>vv<<>v>>>^>v^^<v^v^^v^>>v<v<<v>^<<>>vv<<^v>v<<vv<<^<^v<^<><^^>v>>v>v^>><vv<^v<^>^>>v>^><<^<<>^v<v>>><^^<^<<<v^^>^>vv<<>^<>^<v^<<^v>vv>^^^v<^v><v<<<<<vv>vv>^^^^>v>v><<^<<<^vv><^<<<><v>><v^v>v<<v^^<v^>v>^v^v^<^<^vv>vvv<^^v<>v<<<<>v<v^<vvv^^^<<^<^<<>^<<><<<>v<^>^^v<^^v^>vv>vvv>v><v^^<<>>^><^>>v<<vv>v<<^^^v<<^v^^><><<<><<>v>^<<>v<<<^v>><v^v<^v<v^vv>v>><<^<><^v^^v<v>^>^>vvvv<<><<>>^<vv>^^><v<>v>v<v^^>^><>>><^><<><<<^<>v^><vv^^^^>>^v^>v^<>>v>^^><^<^v^<v^>>v>^vvv<>>v<v^v><>^vvvv<v^<<v^<<^^vv>><<<<<<v><<<v<v^v^^<v^^<>v<<<<^v<<><<v^<^><v<vv<v^v^<v^^vv<v^v<<<>^<<>vv<v<^>^<<><vv<<vv<v<^<^<>><^^<<>>>vv>>>>>>^v<v<>>v^v^^<v^<<<<>><<^v^^^<>^<vv>>>><>v^v^vvv^>>v>><v^v<<<^v>>^^<<^^vv><<<^^^<<<v><^^>>>>vvv^v<^>^^>v<^<><vv<v<>v>>>^vv<<^<v>^v^>^>^v>v>v^v^>v<<v>><>><v^^<<^>>>><<^v^<>^v<vv><>vvv^>v>v<v<v^>^<><><>^>>><v<<<v^vv><>^>^^<<v^>>v^^>^<v>><>><>v^v^^v>>>>vv>>^v<<^v^<>^>v^^>^^<<vvvvvvv>^<v^<<^<<>><<<^^^v^^^^v<^<>v<^^<>vv^^v^<>^<<^>>v>v<<<^^^^vvv^<^<><>v<<v^<^<>>><<><<<v<v<v><vv>^^<vv<<vv<<<v<^>^^vv<v<>><<>>>^v<<>^>>>v^>v>^^<>^<vv<><^>v>^>>>><>^^>v^^v>^vv^^v^><<<>>v<>v<vv<vv^v^v<^v^<^^><<<><vv^^>^<^<<>v>>>>^<<v>v<v>vv<^><^<v><<^>v>>v><<v<<^v^<>>^>>>^v^v>v^^vv^>^<^^>>^><^vv^^vv^<>>^^^^<^^><><v<>>^>>^><vv^>^vvv<^<<v^^<<<>^><>>>^^<><v<v<><<v^^^^^<^<^<<>><<>>>>^<<>>>^<^v^>><<^>>>^<<v>^>><>^<v>^<><v>^v^^vv<><^>vv^^v^<^^^v^vvv^>><>>v<<vv<>>^<^vvv<<^^><vvv^^<v<>vv^^<<>><v>><^^vvv<<<^>^<><^>vv^><^<<>vv<<v>>vv>v>v^<vv><vv><<>^^^^v^^^^<v>^<<^><><^^v^>v>^>><^><<>v^<v>>>^vvv>>^<^<>^^v^vv^^v><<vv^<>>>v<<<>v>^<>v<<>v^>^<<><<><v<v<v<>v^>v<><^^>^<^v^^><^>vv>^>vv<v<^v>vv>^^><<>vv^>^v<<^<<^<<>v<v<^<v>v>>^><v^^v^v>>>><v^v^<<<vv<<^^<>>v^v<^v>v>^^^v<v><v^^^vv<>v^v<^<>v><><v^<>>vv>v><>v>^v<><<<<<<v<>>v^vv<<<<v<<v><^<>^>><>^^vv>^<^<<>vv>>vv<vvv>><><v<>><^<v>^><^<<v>><v><v>^<v>><>v^^^^v<v^^v<>^^vv<>v<>v>^vv^><v^<<^<>^<>^^^>v^>>>v><<^>>v<^v<>^^<v<><v^v<v>v<><v<vv><<>v<^<^>v<>v^>v>^^<<<^^vv^<><<<>>v>^^<>v>>>><v<v<^^^v<v<v^><<>v^v<>v>><<<<v^<><^<<^>^<vvv<v^^v>>v^vv^><^v^^<>^^><<v^>>vv>^<v^vv<^^v<>>vvv<^v^>>^<v<v>>^>^^<<^>^>^v><>>^<^^v>^>>^^<><>>>^^>^^vvv>v<^^<>v^v^^<v<<^<v^v^<<>v^v<v<<v<>>><<^^^>>v>^vv>^>^^v<>^^<>v^^<><v<v<vvv^<vv<<>v^><<><v<>vv<<^vvvv><<<v>v>v^>v^<>v^>^<v<vvv^>^<>^>^^v<>><<<><v<^^>^v<v>^^v^v<<<^v^<>^<>v>^^>v<v<v>v>^^<<<><<^>v<v<^vv^v><^^<<vv>^<<v><>^>>>>><v^v<<<^>^v^v<<v<>vvv<<>v>v>>^v^v^>><<<<>v^<v<><<>>>^>>^>><<v>)";

	typedef std::pair<int, int> Coordinate;

public:
	static void Calculate1() {
		std::set<Coordinate> houseMap;
		int lat = 0;
		int lon = 0;

		Coordinate zeroCoord = std::make_pair(lat, lon);
		houseMap.insert(zeroCoord);
		size_t len = strlen(input);
		for (int i = 0; i < len; i++) {
			switch (input[i])
			{
			case '^': lat++; break;
			case 'v': lat--; break;
			case '<': lon++; break;
			case '>': lon--; break;
			default: break;
			}

			Coordinate c = std::make_pair(lat, lon);
			houseMap.insert(c);
			//if (houseMap.find(c) == houseMap.end()) {
			//	houseMap.insert(c);
			//}
		}

		printf("Advent_2015_03  %zd\n", houseMap.size());
	}
	static void Calculate2() {
		std::set<Coordinate> houseMap;
		int lat[2] = { 0 };
		int lon[2] = { 0 };

		Coordinate zeroCoord = std::make_pair(lat[0], lon[0]);
		houseMap.insert(zeroCoord);
		size_t len = strlen(input);
		int santa = 0;
		for (int i = 0; i < len; i++) {
			santa = i % 2;

			switch (input[i])
			{
			case '^': lat[santa]++; break;
			case 'v': lat[santa]--; break;
			case '<': lon[santa]++; break;
			case '>': lon[santa]--; break;
			default: break;
			}

			Coordinate c = std::make_pair(lat[santa], lon[santa]);
			houseMap.insert(c);
			//if (houseMap.find(c) == houseMap.end()) {
			//	houseMap.insert(c);
			//}
		}

		printf("Advent_2015_03  %zd\n", houseMap.size());
	}
};

class Advent_2015_04 {
public:
	static constexpr const char* input = "iwrupvqb";
	

	static void Calculate1()
	{
		uint32_t partOneAnswer = 0;
		uint32_t partTwoAnswer = 0;
		uint32_t suffix = 0;
		do {
			std::string toTest = input + std::to_string(suffix);
			std::string hashedString = md5(toTest);
			if (hashedString[0] == '0' &&
				hashedString[1] == '0' &&
				hashedString[2] == '0' &&
				hashedString[3] == '0' &&
				hashedString[4] == '0' )
			{
				if(partOneAnswer == 0)
					partOneAnswer = suffix;

				if (hashedString[5] == '0')
				{
					partTwoAnswer = suffix;
					break;
				}
			}
			suffix++;
		} while (true);

		printf("Advent_2015_04  %d   %d\n", partOneAnswer, partTwoAnswer);
	}
};

class Advent_2015_05 {
public:

	static bool IsGood(const char* str) {
		size_t len = strlen(str);
		for (int i = 0; i < len - 1; i++) {
			if ((str[i] == 'a' && str[i + 1] == 'b') ||
				(str[i] == 'c' && str[i + 1] == 'd') ||
				(str[i] == 'p' && str[i + 1] == 'q') ||
				(str[i] == 'x' && str[i + 1] == 'y'))
				return false;
		}

		int numVowels = 0;
		int numRepeats = 0;
		for (int i = 0; i < len; i++) {
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
				numVowels++;
			if (str[i] == str[i + 1])
				numRepeats++;
		}

		return numVowels >= 3 && numRepeats >= 1;
	}

	static bool IsBetter(const char* str) {
		size_t len = strlen(str);

		bool hasRepeatOneSpace = false;
		for (int i = 0; i < len-2; i++) {
			int j = i + 2;
			if (str[i] == str[j]) {
				hasRepeatOneSpace = true;
				break;
			}
		}
		if (!hasRepeatOneSpace)
			return false;

		for (int i = 0; i < len-2; i++) {
			for (int j = i+2; j < len; j++) {
				if (str[i] == str[j] &&
					str[i + 1] == str[j + 1]) {
					return true;
				}
			}
		}
		return false;
	}

	static void GetNextString(const char* input, int& pos, char* buff)
	{
		size_t len = strlen(input);
		if (pos >= len)
			return;

		// skip to next alphaNumeric
		while (pos < len && !isalnum(input[pos])) {
			pos++;
		}

		int i = 0;
		// skip to next alphaNumeric
		while (pos < len && isalnum(input[pos])) {
			buff[i++] = input[pos++];
		}
		buff[i] = '\0';
	}

	static void Calculate1()
	{
		const char* input = Utils::ReadInput("2015_05_1.txt");

		int numOfGoodStrings = 0;
		int pos = 0;
		size_t len = strlen(input);
		char buff[64];
		while (pos < len)
		{
			GetNextString(input, pos, buff);
			if (IsGood(buff))
				numOfGoodStrings++;
		}
		printf("Advent_2015_05_1 %d\n", numOfGoodStrings);
	}
	static void Calculate2()
	{
		const char* input = Utils::ReadInput("2015_05_1.txt");
		// const char* input = "qjhvhtzxzqqjkmpb\nxxyxx\nuurcxstgmygtbstg\nieodomkazucvgmuy";

		int numOfGoodStrings = 0;
		int pos = 0;
		size_t len = strlen(input);
		char buff[64];
		while (pos < len)
		{
			GetNextString(input, pos, buff);
			if (IsBetter(buff))
				numOfGoodStrings++;
		}
		printf("Advent_2015_05_2 %d\n", numOfGoodStrings);
	}
};

class Advent_2015_06 {
public:
	
	static constexpr int LIGHT_SIZE = 1000;
	static int lights[LIGHT_SIZE][LIGHT_SIZE];
	static int CountOn() {
		int num = 0;
		for (int x = 0; x < LIGHT_SIZE; x++) {
			for (int y = 0; y < LIGHT_SIZE; y++) {
				num += lights[x][y];
			}
		}
		return num;
	}
	static void TurnOn(int x1, int y1, int x2, int y2) {
		for (int x = x1; x <= x2; x++) {
			for (int y = y1; y <= y2; y++) {
				lights[x][y]++;
			}
		}
	}
	static void TurnOff(int x1, int y1, int x2, int y2) {
		for (int x = x1; x <= x2; x++) {
			for (int y = y1; y <= y2; y++) {
				lights[x][y] = std::max(0, lights[x][y]-1);
			}
		}
	}
	static void Toggle(int x1, int y1, int x2, int y2) {
		for (int x = x1; x <= x2; x++) {
			for (int y = y1; y <= y2; y++) {
				lights[x][y] += 2;
			}
		}
	}
	static void GetCoordinates(const char* buff, int& x1, int& y1, int& x2, int& y2) {
		size_t len = strlen(buff);
		int pos = 0;
		while (pos < len && !std::isdigit(buff[pos])) { pos++; }
		x1 = atoi(buff + pos);
		while (pos < len && std::isdigit(buff[pos])) { pos++; }
		while (pos < len && !std::isdigit(buff[pos])) { pos++; }
		y1 = atoi(buff + pos);
		while (pos < len && std::isdigit(buff[pos])) { pos++; }
		while (pos < len && !std::isdigit(buff[pos])) { pos++; }
		x2 = atoi(buff + pos);
		while (pos < len && std::isdigit(buff[pos])) { pos++; }
		while (pos < len && !std::isdigit(buff[pos])) { pos++; }
		y2 = atoi(buff + pos);

	}

	static void Calculate1()
	{
		const char* input = Utils::ReadInput("2015_06.txt");

		int pos = 0;
		size_t len = strlen(input);
		while (pos < len) {
			char buff[128] = { '\0' };
			Utils::GetNextLine(input, pos, buff);

			int function = -1;
			if (strstr(buff, "turn on") != 0) {
				function = 0;
			}
			else if (strstr(buff, "turn off") != 0) {
				function = 1;
			}
			else if (strstr(buff, "toggle") != 0) {
				function = 2;
			}
			else {
				printf("Don't know what to do with line: %s\n", buff);
				continue;
			}
			int x1, y1, x2, y2;
			GetCoordinates(buff, x1, y1, x2, y2);

			switch (function) {
			case 0: TurnOn(x1, y1, x2, y2); break;
			case 1: TurnOff(x1, y1, x2, y2); break;
			case 2: Toggle(x1, y1, x2, y2); break;
			}

		}

		int numOn = CountOn();
		printf("Advent_2015_06  %d\n", numOn);
	}
};
int Advent_2015_06::lights[LIGHT_SIZE][LIGHT_SIZE] = {0,0};

class Advent_2015_07 {
	enum Ops {
		None = 0,
		SET,
		SETVAL,
		AND,
		OR,
		LSHIFT,
		RSHIFT,
		NOT,
	};

	struct WireOp
	{
		WireOp() {
			op = None;
			arg = 0;
			input1 = "";
			input2 = "";
		}

		Ops op;
		int arg;
		std::string input1;
		std::string input2;
	};

public:
	static void PushOp(std::vector<std::string>& tokens, std::map<std::string, WireOp>& opMap) {
		if (tokens[0] == "NOT")
		{
			WireOp op;
			op.op = NOT;
			op.input1 = tokens[1];
			opMap.insert(std::make_pair(tokens[3], op));
		}
		else if (tokens[1] == "->")
		{
			WireOp op;
			if (std::isalpha(tokens[0][0])) {
				op.op = SET;
				op.input1 = tokens[0];
			}
			else {
				op.op = SETVAL;
				op.arg = atoi(tokens[0].c_str());
			}
			opMap.insert(std::make_pair(tokens[2], op));
		}
		else if (tokens[1] == "AND")
		{
			WireOp op;
			op.op = AND;
			op.input1 = tokens[0];
			op.input2 = tokens[2];
			opMap.insert(std::make_pair(tokens[4], op));
		}
		else if (tokens[1] == "OR")
		{
			WireOp op;
			op.op = OR;
			op.input1 = tokens[0];
			op.input2 = tokens[2];
			opMap.insert(std::make_pair(tokens[4], op));
		}
		else if (tokens[1] == "LSHIFT")
		{
			WireOp op;
			op.op = LSHIFT;
			op.input1 = tokens[0];
			op.arg = atoi(tokens[2].c_str());
			opMap.insert(std::make_pair(tokens[4], op));
		}
		else if (tokens[1] == "RSHIFT")
		{
			WireOp op;
			op.op = RSHIFT;
			op.input1 = tokens[0];
			op.arg = atoi(tokens[2].c_str());
			opMap.insert(std::make_pair(tokens[4], op));
		}
		else {
			printf("Unknown op!\n");
		}
	}

	static uint16_t Resolve(const std::string& signal, 
		std::map<std::string, WireOp>& opMap,
		std::map<std::string, uint16_t>& memory) {
		if (signal == "") {
			printf("debug");
		}
		if (!isalpha(signal[0]) )
		{
			return std::stoi(signal);
		}

		auto memIter = memory.find(signal);
		if (memIter != memory.end())
			return memIter->second;

		auto iter = opMap.find(signal);
		const WireOp& op = iter->second;
		uint16_t retunVal = 0;
		if (op.op == SETVAL) {
			retunVal = op.arg;
		}
		if (op.op == SET) {
			retunVal = Resolve(op.input1, opMap, memory);
		}
		else if (op.op == AND) {
			int a = Resolve(op.input1, opMap, memory);
			int b = Resolve(op.input2, opMap, memory);
			retunVal = a & b;
		}
		else if (op.op == OR) {
			int a = Resolve(op.input1, opMap, memory);
			int b = Resolve(op.input2, opMap, memory);
			retunVal = a | b;
		}
		else if (op.op == NOT) {
			int a = Resolve(op.input1, opMap, memory);
			retunVal = ~a;
		}
		else if (op.op == RSHIFT) {
			int a = Resolve(op.input1, opMap, memory);
			retunVal = a >> op.arg;
		}
		else if (op.op == LSHIFT) {
			int a = Resolve(op.input1, opMap, memory);
			retunVal = a << op.arg;
		}
		else {
			printf("Invalid Op\n");
		}

		memory[signal] = retunVal;
		return retunVal;

	}

	static void Calculate1() {
		const char* input = Utils::ReadInput("2015_07.txt");
		size_t len = strlen(input);
		
		std::map<std::string, WireOp> opMap;
		std::map<std::string, uint16_t> signals;

		int pos = 0;
		while (pos < len) {
			char buff[128] = { '\0' };
			Utils::GetNextLine(input, pos, buff);

			std::vector<std::string> tokens;
			Utils::Tokenize(buff, " ", tokens);
			PushOp(tokens, opMap);
		};

		std::map<std::string, uint16_t> memory;
		uint16_t firstValue = Resolve("a", opMap, memory);
		memory.clear();
		memory["b"] = firstValue;
		uint16_t secondValue = Resolve("a", opMap, memory);


		printf("Advent_2015_07    %d   %d\n", firstValue, secondValue);

	}
};

class Advent_2015_08 {
public:

	static int GetDecodedLen(const char* line)
	{
		int retVal = 0;
		uint32_t lineLen = (uint32_t)strlen(line);
		for (uint32_t i = 1; i < lineLen - 1; i++) {
			if (line[i] != '\\') {
				retVal++;
			}
			else
			{
				i++;
				if (line[i] == 'x') {
					i += 2;
				}
				else if (line[i] == '\\' || line[i] == '\"') {
				}
				else {
					printf("Unregcognized escape code\n");
				}
				retVal++;
			}
		}
		return retVal;
	}

	static int GetEncodedLen(const char* line)
	{
		uint32_t lineLen = (uint32_t)strlen(line);
		uint32_t totalLen = lineLen + 2;
		for (uint32_t i = 0; i < lineLen; i++) {
			if (line[i] == '\\' || line[i] == '\"') {
				totalLen++;
			}
		}
		return totalLen;
	}

	static void Calculate() {
		const char* input = Utils::ReadInput("2015_08.txt");

		size_t len = strlen(input);
		int pos = 0;

		uint32_t totalLen = 0;
		uint32_t decryptLen = 0;
		uint32_t encryptLen = 0;
		while (pos < len) {
			char buff[256] = { 0 };
			Utils::GetNextLine(input, pos, buff);
			uint32_t lineLen = (uint32_t)strlen(buff);
			totalLen += lineLen;

			decryptLen += GetDecodedLen(buff);
			encryptLen += GetEncodedLen(buff);
		}

		int part1 = totalLen - decryptLen;
		int part2 = encryptLen - totalLen;
		printf("Advent_2015_08  %d    %d", part1, part2);
	}
};

class Advent_2015_09 {
public:

	typedef std::map<std::string, std::map<std::string, int>> GraphMap;
	typedef std::vector<std::string> DestList;

	static void AddGraphData(std::string& src, std::string& dst, int dist, GraphMap& graph){
		if (graph.find(src) == graph.end()) {
			graph.insert(std::make_pair(src, std::map<std::string, int>()));
		}
		if (graph.find(dst) == graph.end()) {
			graph.insert(std::make_pair(dst, std::map<std::string, int>()));
		}
		graph[src].insert(std::make_pair(dst, dist));
		graph[dst].insert(std::make_pair(src, dist));
	}

	static void BuildMap(GraphMap& graph) {
		const char* input = Utils::ReadInput("2015_09.txt");
		size_t len = strlen(input);
		int pos = 0;
		while (pos < len)
		{
			char buff[256];
			Utils::GetNextLine(input, pos, buff);
			std::vector<std::string> tokens;
			Utils::Tokenize(buff, " ", tokens);

			int distance = atoi(tokens[4].c_str());
			AddGraphData(tokens[0], tokens[2], distance, graph);
		}
	}

	static DestList CreateDestList(GraphMap& graph) {
		DestList list;
		for (auto kvp : graph) {
			list.push_back(kvp.first);
		}
		return list;
	}

	static int FindShortestPath(const std::string& src, GraphMap& graph, DestList& destList, int currDist) {
		int smallestDist = INT_MAX;

		if (destList.empty())
			return currDist;

		for (std::string dest : destList) {
			DestList newList = DestList(destList);

			// remove the dest from the new list
			auto iter = newList.begin();
			for (; iter != newList.end(); ++iter) {
				if (*iter == dest) {
					newList.erase(iter);
					break;
				}
			}

			int newDist = currDist;
			if (!src.empty()) {
				newDist += graph[src][dest];
			}
			newDist = FindShortestPath(dest, graph, newList, newDist);

			smallestDist = std::min(smallestDist, newDist);
		}

		return smallestDist;
	}

	static int FindLongestPath(const std::string& src, GraphMap& graph, DestList& destList, int currDist) {
		int longestDist = 0;

		if (destList.empty())
			return currDist;

		for (std::string dest : destList) {
			DestList newList = DestList(destList);

			// remove the dest from the new list
			auto iter = newList.begin();
			for (; iter != newList.end(); ++iter) {
				if (*iter == dest) {
					newList.erase(iter);
					break;
				}
			}

			int newDist = currDist;
			if (!src.empty()) {
				newDist += graph[src][dest];
			}
			newDist = FindLongestPath(dest, graph, newList, newDist);

			longestDist = std::max(longestDist, newDist);
		}

		return longestDist;
	}

	static void Calculate()
	{
		GraphMap graph;
		BuildMap(graph);

		DestList destinations = CreateDestList(graph);

		int smallestPath = FindShortestPath("", graph, destinations, 0);
		int longestPath = FindLongestPath("", graph, destinations, 0);

		printf("Advent_2015_09   %d    %d\n", smallestPath, longestPath);
	}
};

class Advent_2015_10 {
public:

	static int HowManyConsecutive(const char* data) {
		int i = 1;
		while (data[0] == data[i]){
			i++;
		}

		return i;
	}

	static std::string LookAndSay(const std::string& number) {
		std::string newNumber;
		
		for (int i = 0; i < number.size(); ) {
			int consec = HowManyConsecutive(number.c_str() + i);
			newNumber.append(std::to_string(consec));
			newNumber.append(number.c_str() + i,1 );
			i += consec;
		}

		return newNumber;
	}

	static void Calculate() {
		std::string input = "3113322113";
		// std::string input = "1";

		std::string number = input;
		int iterations = 50;
		for (int i = 0; i < iterations; i++) {
			number = LookAndSay(number);
		}

		int finalVal = (int)number.size();
		printf("Advent_2015_10   %d\n", finalVal);
	}
};

class Advent_2015_11 {
public:

	static bool IsValidPassword(const std::string& pw) {
		int len = (int)pw.size();

		// no i,l,o
		for (int i = 0; i < len; i++) {
			if (pw[i] == 'i' ||
				pw[i] == 'l' ||
				pw[i] == 'o') {
				return false;
			}
		}

		bool consecutive = false;
		for (int i = 0; i < len-2; i++) {
			if (pw[i] + 1 == pw[i + 1] &&
				pw[i] + 2 == pw[i + 2]) {
				consecutive = true;
				break;
			}
		}
		if (!consecutive)
			return false;

		char firstDouble = '\0';
		bool doubles = false;
		for (int i = 0; i < len - 1; i++) {
			if (pw[i] == pw[i + 1]) {
				if (firstDouble == '\0') {
					firstDouble = pw[i];
				}
				else if (pw[i] != firstDouble ){
					doubles = true;
					break;
				}
			}
		}

		return doubles;
	}

	static void GetNextPassword(std::string& pw) {
		int idx = (int)pw.size() - 1;
		
		bool validIncrease = true;
		while (validIncrease) {
			if (pw[idx] != 'z') {
				pw[idx] = pw[idx] + 1;
				break;
			}
			else {
				pw[idx] = 'a';
				idx--;
				if (idx < 0)
					break;
			}
		}
	}

	static void Calculate() {
		std::string oldPassword = "hxbxwxba";

		std::string newPassword = oldPassword;

		GetNextPassword(newPassword);
		while( !IsValidPassword(newPassword))
		{
			GetNextPassword(newPassword);
		}
		std::string anotherPassword = newPassword;
		GetNextPassword(anotherPassword);
		while (!IsValidPassword(anotherPassword))
		{
			GetNextPassword(anotherPassword);
		}

		printf("Advent_2015_11   %s  %s\n", newPassword.c_str(), anotherPassword.c_str());
	}
};

class Advent_2015_12 {
public:

	static int sRedCount;

	static void Calculate1() {
		const char* input = Utils::ReadInput("2015_012.txt");

		size_t len = strlen(input);
		int sum = 0;
		int pos = 0;
		while (pos < len)
		{
			if (input[pos] == ':' || input[pos] == ',' || input[pos] == '[') {
				pos++;
				if (Utils::IsInteger(input, pos)) {
					sum += Utils::GetNextBoolAndAdvance(input, pos);
				}
			}
			else {
				pos++;
			}
		}

		printf("Advent_2015_12    %d\n", sum);
	}

	static bool IsRedString(const char* input, int pos) {
		return	input[pos+0] == 'r' &&
				input[pos+1] == 'e' &&
				input[pos+2] == 'd';
	}

	static int32_t ReadObject(const char* input, int& pos, const int len)
	{
		int count = 0;
		bool isRed = false;
		bool inArray = false;

		while (pos < len)
		{
			char c = input[pos];

			// new object
			if (c == '{') {
				pos++;
				count += ReadObject(input, pos, len);
			}
			else if (c == '}') {
				pos++;
				if (isRed)
					return 0;
				else
					return count;
			}
			else if (c == '\"') {
				// start of quote.  run to the end of the quote
				// const char* str = input + (pos+1);
				pos++;
				bool redToken = IsRedString(input, pos);
				if (redToken)
				{
					sRedCount++;
					isRed |= (redToken && !inArray);
				}
				while (input[pos] != '\"') pos++;
				pos++;
			}
			else if (c == '[' )
			{
				pos++;
				inArray = true;
			}
			else if (c == ']')
			{
				pos++;
				inArray = false;
			}
			else if (c == ',' || c == ':' || c == '\n' || c == '\r' || c == '\t')
			{
				pos++;
			}
			else {
				int val = atoi(input + pos);
				count += val;
				while (Utils::IsInteger(input, pos)) pos++;
			}
		}

		return count;
	}

	static void Calculate2() {
		const char* input = Utils::ReadInput("2015_012.txt");

		int len = (int)strlen(input);
		int pos = 0;
		int32_t sum = ReadObject(input, pos, len);


		printf("Advent_2015_12    %d\n", sum);
	}
};
int Advent_2015_12::sRedCount = 0;

class Advent_2015_13 {
public:

	typedef std::map <std::string,std::map<std::string, int>> SeatingMap;


	static void ManuallyAddToMap(SeatingMap& map, std::string name, int score) {
		std::vector<std::string> names;
		for (auto kvp : map) {
			names.push_back(kvp.first);
		}

		map.insert(std::make_pair(name, std::map<std::string, int>()));
		for (auto p : names) {
			map[name].insert(std::make_pair(p, score));
			map[p].insert(std::make_pair(name, 0));
		}
	}

	static void PopulateMap(SeatingMap& map)
	{
		const char* input = Utils::ReadInput("2015_013.txt");
		
		size_t len = strlen(input);
		int pos = 0;
		while (pos < len) {
			char buff[512] = { '\0' };
			Utils::GetNextLine(input, pos, buff);
			std::vector<std::string> tokens;
			Utils::Tokenize(buff, " ", tokens);

			std::string person = tokens[0];
			std::string neighbor = tokens[tokens.size()-1];
			neighbor = neighbor.substr(0, neighbor.size() - 1);
			int score = atoi( tokens[3].c_str() );
			if (tokens[2] == "lose") {
				score *= -1;
			}

			if (map.find(tokens[0]) == map.end()) {
				map.insert(std::make_pair(tokens[0], std::map<std::string, int>()));
			}
			map[person][neighbor] = score;
		}
	}

	static int CalculateHappines(std::vector<std::string>& seats, SeatingMap& map) {
		int score = 0;
		for (int i = 0; i < seats.size(); i++) {
			int left = (int) (i - 1 + seats.size()) % seats.size();
			int right = (i + 1) % seats.size();

			std::string& person = seats[i];
			std::string& leftPerson = seats[left];
			std::string& rightPerson = seats[right];
			score += map[person][leftPerson];
			score += map[person][rightPerson];
		}
		return score;
	}

	static int GetBestScore(std::vector<std::string>& seats, std::set<std::string>& remaining, SeatingMap& map) {

		if (seats.size() == map.size()) {
			return CalculateHappines(seats, map);
		}

		int bestScore = 0;
		for ( auto person : remaining) {
			std::set<std::string> newRemaining(remaining);
			auto iter = newRemaining.find(person);
			newRemaining.erase(iter);

			seats.push_back(person);
			int score = GetBestScore(seats, newRemaining, map);
			seats.pop_back();

			if (score > bestScore) {
				bestScore = score;
			}
		}
		return bestScore;
	}

	static void Calculate1() {
		SeatingMap map;
		PopulateMap(map);

		std::set<std::string> remaining;
		for (auto kvp : map) {
			remaining.insert(kvp.first);
		}
		std::vector<std::string> seats;
		int happiness = GetBestScore(seats, remaining, map);
		printf("Advent_2015_13_1   %d\n", happiness);
	}

	static void Calculate2() {
		SeatingMap map;
		PopulateMap(map);
		ManuallyAddToMap(map, "self", 0);

		std::set<std::string> remaining;
		for (auto kvp : map) {
			remaining.insert(kvp.first);
		}
		std::vector<std::string> seats;
		int happiness = GetBestScore(seats, remaining, map);
		printf("Advent_2015_13_2   %d\n", happiness);
	}
};

class Advent_2015_14 {
public:

	struct Info {
		Info(const std::string& n, int s, int t, int r) {
			name = n;
			speed = s;
			time = t;
			restTime = r;
		}
		std::string name;
		int speed;
		int time;
		int restTime;
	};

	typedef std::vector<Info> DeerData;
	typedef std::vector<int> PointList;

	static void PopulateData(DeerData& data) {
		const char* input = Utils::ReadInput("2015_014.txt");

		size_t len = strlen(input);
		int pos = 0;
		while (pos < len) {
			char buff[512] = { '\0' };
			Utils::GetNextLine(input, pos, buff);
			std::vector<std::string> tokens;
			Utils::Tokenize(buff, " ", tokens);

			std::string name = tokens[0];
			int speed = atoi(tokens[3].c_str());
			int time = atoi(tokens[6].c_str());
			int restTime = atoi(tokens[13].c_str());

			data.push_back(Info(name, speed, time, restTime));
		}
	}

	static int GetDistAtTime(const Info& info, int time) {
		int cycleTime = info.time + info.restTime;
		int cycleDist = info.speed * info.time;

		int totalDist = 0;
		int numCycles = time / cycleTime;
		totalDist += numCycles * cycleDist;

		int timeLeftOver = time % cycleTime;
		if (timeLeftOver > info.time) {
			totalDist += cycleDist;
		}
		else {
			totalDist += info.speed * timeLeftOver;
		}

		return totalDist;
	}

	static void AssignPointsAtTime(DeerData& data, PointList& points, int time) {

		std::vector<int> distances;
		for (auto d : data) {
			int dist = GetDistAtTime(d, time);
			distances.push_back(dist);
		}

		int best = 0;
		for (auto p : distances) {
			best = std::max(best, p);
		}

		for (int i = 0; i < points.size(); i++) {
			if (distances[i] == best)
				points[i]++;
		}
	}

	static void Calculate() {
		DeerData data;
		PopulateData(data);

		static const int TIME = 2503;

		std::vector<int> points;
		for (int i = 0; i < data.size(); i++)
			points.push_back(0);

		for (int i = 1; i <= TIME; i++) {
			AssignPointsAtTime(data, points, i);
		}

		int best = 0;
		for (auto iter : points)
			best = std::max(best, iter);

		printf("Advent_2015_14   %d\n", best);
	}
};

class Advent_2015_15 {
public:

	struct Info {
		Info(int c, int d, int f, int t, int ca) {
			cap = c;
			dur = d;
			flav = f;
			tex = t;
			cal = ca;
		}
		int cap = 0;
		int dur = 0;
		int flav = 0;
		int tex = 0;
		int cal = 0;
	};

	typedef std::vector<Info> DataList;

	static int StaticMax;

	static int GetScore(DataList& data, std::vector<int> counts) {
		int a = 0;
		int b = 0;
		int c = 0;
		int d = 0;
		int calorie = 0;

		for (int i = 0; i < data.size(); i++) {
			int count = counts[i];
			a += (data[i].cap  * count);
			b += (data[i].dur  * count);
			c += (data[i].flav * count);
			d += (data[i].tex  * count);
			calorie += (data[i].cal * count);
		}

		if (calorie != 500)
			return 0;

		a = std::max(0, a);
		b = std::max(0, b);
		c = std::max(0, c);
		d = std::max(0, d);

		int score = a * b * c * d;
		if (score > StaticMax) {
			StaticMax = score;
			for (auto i : counts)
				printf("%d ", i);
			printf("     %d\n", score);
		}

		return score;
	}

	static int GetMaxSore(DataList& data, std::vector<int>& counts, int countLeft ) {
		if (counts.size() == data.size()) {
			return GetScore(data, counts);
		}

		if (counts.size() == data.size() - 1)
		{
			counts.push_back(countLeft);
			int score = GetMaxSore(data, counts, 0);
			counts.pop_back();
			return score;
		}

		int best = 0;
		for (int i = 1; i <= countLeft; i++) {
			counts.push_back(i);
			int score = GetMaxSore(data, counts, countLeft - i);
			counts.pop_back();
			best = std::max(best, score);
		}

		return best;
	}

	static void Calculate() {
//Frosting:		capacity  4, durability -2, flavor  0, texture 0, calories 5
//Candy :		capacity  0, durability  5, flavor -1, texture 0, calories 8
//Butterscotch :capacity -1, durability  0, flavor  5, texture 0, calories 6
//Sugar :		capacity  0, durability  0, flavor -2, texture 2, calories 1

		//DataList data = { Info(-1, -2, 6, 3, 8),
		//				  Info(2, 3, -2, -1, 3) };

		DataList data = {	Info( 4,	 -2,	  0,	 0,		 5),
							Info( 0,	  5,	 -1,	 0,		 8),
							Info(-1,	  0,	  5,	 0,		 6),
							Info( 0,	  0,	 -2,	 2,		 1) };

		StaticMax = 0;
		int maxCalories = 100;
		std::vector<int> counts;
		int score = GetMaxSore(data, counts, maxCalories);
		printf("Advent_2015_15   %d\n", score);
	}
};
int Advent_2015_15::StaticMax = 0;

class Advent_2015_16 {
public:
	
	struct Info {
		bool IsMatch(const Info& rhs) {
#define EQUAL( value ) if (rhs.value >= 0 && rhs.value != value)
#define GREATER( value ) if (rhs.value >= 0 && rhs.value < value)
#define LESS( value ) if (rhs.value >= 0 && rhs.value > value)
			EQUAL(children)
				return false;
			GREATER(cats)
				return false;
			EQUAL(samoyeds)
				return false;
			LESS(pomeranians)
				return false;
			EQUAL(akitas)
				return false;
			EQUAL(vizslas)
				return false;
			LESS(goldfish)
				return false;
			GREATER(trees)
				return false;
			EQUAL(cars)
				return false;
			EQUAL(perfumes)
				return false;
#undef CHECK
		}
		void AddCount(const std::string& name, int val) {
			if (name == "children")
				children = val;
			else if (name == "cats")
				cats = val;
			else if (name == "samoyeds")
				samoyeds = val;
			else if (name == "pomeranians")
				pomeranians = val;
			else if (name == "akitas")
				akitas = val;
			else if (name == "vizslas")
				vizslas = val;
			else if (name == "goldfish")
				goldfish = val;
			else if (name == "trees")
				trees = val;
			else if (name == "cars")
				cars = val;
			else if (name == "perfumes")
				perfumes = val;
		}

		int children = -1;
		int cats = -1;
		int samoyeds = -1;
		int pomeranians = -1;
		int akitas = -1;
		int vizslas = -1;
		int goldfish = -1;
		int trees = -1;
		int cars = -1;
		int perfumes = -1;
	};

	typedef std::vector<Info> InfoList;

	static void Populate(InfoList& list)
	{
		const char* input = Utils::ReadInput("2015_016.txt");

		size_t len = strlen(input);
		int pos = 0;
		while (pos < len) {
			char buff[512] = { '\0' };
			Utils::GetNextLine(input, pos, buff);
			std::vector<std::string> tokens;
			Utils::Tokenize(buff, " ", tokens);

			std::string prop1 = tokens[2].substr(0, tokens[2].size()-1);
			int count1 = atoi(tokens[3].c_str());

			std::string prop2 = tokens[4].substr(0, tokens[4].size() - 1);
			int count2 = atoi(tokens[5].c_str());

			std::string prop3 = tokens[6].substr(0, tokens[6].size() - 1);
			int count3 = atoi(tokens[7].c_str());

			Info newInfo;
			newInfo.AddCount(prop1, count1);
			newInfo.AddCount(prop2, count2);
			newInfo.AddCount(prop3, count3);

			list.push_back(newInfo);
		}
	}

	static void Calculate() {
		Info key;
		key.children = 3;
		key.cats = 7;
		key.samoyeds = 2;
		key.pomeranians = 3;
		key.akitas = 0;
		key.vizslas = 0;
		key.goldfish = 5;
		key.trees = 3;
		key.cars = 2;
		key.perfumes = 1;

		InfoList list;
		list.push_back(key);

		Populate(list);
		int match = -1;
		for (int i = 1; i < list.size(); i++) {
			if (list[0].IsMatch(list[i])) {
				match = i;
				break;
			}
		}

		printf("Advent_2015_16   %d\n", match);
	}
};

class Advent_2015_17 {
public:

	typedef std::map<int, int> FullList;
	typedef std::vector<int> ContainerList;

	static void PrintList(const ContainerList& list) {
		printf("[");
		for (auto i : list) {
			printf("%d  ", i);
		}
		printf("]\n");
	}

	static void Populate(ContainerList& list) {
		const char* input = Utils::ReadInput("2015_017.txt");

		size_t len = strlen(input);
		int pos = 0;
		while (pos < len) {
			char buff[512] = { '\0' };
			Utils::GetNextLine(input, pos, buff);
			list.push_back(atoi(buff));
		}
	}

	static int NumberOfValidConfigs(ContainerList& list, int index, int remaining, ContainerList full, FullList& win) {
		int num = 0;

		if (remaining == 0)
			return 0;
		if (index == list.size())
			return 0;
		if (index == list.size() - 1) {
			if (list[index] == remaining) {
				full.push_back(list[index]);
				PrintList(full);
				win[(int)full.size()]++;
				full.pop_back();
				return 1;
			} else {
				return 0;
			}
		}

		int nc = NumberOfValidConfigs(list, index + 1, remaining, full, win);
		if (nc > 0) {
			num += nc;
		}

		if (remaining > list[index]) {
			full.push_back(list[index]);
			nc = NumberOfValidConfigs(list, index + 1, remaining - list[index], full, win);
			if (nc > 0) {
				num += nc;
			}
			full.pop_back();
		}
		else if (remaining == list[index]) {
			full.push_back(list[index]);
			PrintList(full);
			win[(int)full.size()]++;
			full.pop_back();
			num++;
		}

		return num;
	}

	static void Calculate() {

		ContainerList list;
		Populate(list);
		int totalLiquid = 150;

		//ContainerList list = { 20, 15, 10 , 5 , 5};
		//int totalLiquid = 25;

		ContainerList full;

		FullList winning;
		for (auto i : list)
			winning[i] = 0;

		int count = NumberOfValidConfigs(list, 0, totalLiquid, full, winning);
		printf("Advent_2015_17    %d\n", count);
	}
};

class Advent_2015_18 {
public:

	static int GSize;
	struct Grid {
		void Init(int size) {
			GSize = size;
			uint32_t numElements = GSize * GSize;
			count = (int*)malloc(numElements * sizeof(int));
			memset(count, 0, numElements * sizeof(int));
			val = (bool*)malloc(numElements * sizeof(bool));
			memset(val, 0, numElements * sizeof(bool));
		}
		void ClearCount() {
			for (int i = 0; i < GSize; i++) {
				for (int j = 0; j < GSize; j++) {
					count[i * GSize + j] = 0;
				}
			}
		}
		void Print() {
			static const bool PrintCount = true;
			for (int i = 0; i < GSize; i++) {
				char* buff = (char*)_malloca(sizeof(char)*(GSize+1));
				memset(buff, '\0', sizeof(char) * (GSize+1));
				for (int j = 0; j < GSize; j++) {
					buff[j] = val[i*GSize + j] ? '#' : '.';
				}
				printf("%s", buff);

				if (PrintCount) {
					printf("\t\t");
					for (int j = 0; j < GSize; j++) {
						_itoa_s(count[i * GSize + j], buff + j, 2, 10);
					}
					printf("%s", buff);
				}
				printf("\n");
			}
		}
		void SetCorners() {
			Val(0		, 0) = true;
			Val(GSize-1	, 0) = true;
			Val(0		, GSize-1) = true;
			Val(GSize-1	, GSize-1) = true;
		}
		inline bool& Val(int x, int y) { return val[(x * GSize) + y]; }
		inline int& Count(int x, int y) { return count[(x * GSize) + y]; }

	private:
		int* count = nullptr;
		bool* val = nullptr;
	};

	static void MarkSurrounding(Grid& g, int x, int y) {
		if (!g.Val(x,y))
			return;

		// left
		if (x > 0) {
			if (y > 0)			g.Count(x - 1, y - 1)++;
								g.Count(x - 1, y    )++;
			if (y + 1 < GSize)	g.Count(x - 1, y + 1)++;
		}
		// middle
		{
			if (y > 0)			g.Count(x    , y - 1)++;
			if (y + 1 < GSize)	g.Count(x    , y + 1)++;
		}
		// right
		if (x + 1 < GSize) {
			if (y > 0)			g.Count(x + 1, y - 1)++;
								g.Count(x + 1, y    )++;
			if (y + 1 < GSize)	g.Count(x + 1, y + 1)++;
		}
	}

	static void DoCount(Grid& g) {
		g.ClearCount();

		for (int x = 0; x < GSize; x++) {
			for (int y = 0; y < GSize; y++) {
				MarkSurrounding(g, x, y);
			}
		}
	}

	static void SetNewVal(Grid& g) {
		for (int x = 0; x < GSize; x++) {
			for (int y = 0; y < GSize; y++) {
				if (g.Val(x,y)) {
					if (g.Count(x,y) != 2 && g.Count(x,y) != 3)
					{
						g.Val(x,y) = false;
					}
				}
				else {
					if (g.Count(x,y) == 3)
					{
						g.Val(x,y) = true;
					}
				}			
			}
		}
		g.SetCorners();
	}

	static int CountOn(Grid& g) {
		int count = 0;
		for (int x = 0; x < GSize; x++) {
			for (int y = 0; y < GSize; y++) {
				if (g.Val(x, y) != false) count++;
			}
		}
		return count;
	}

	static void Populate(Grid& g, bool test) {
		const char* input = nullptr;
		if (test)
			input = Utils::ReadInput("2015_018_test.txt");
		else
			input = Utils::ReadInput("2015_018.txt");

		size_t len = strlen(input);
		char temp[1024];
		int tempPos = 0;
		Utils::GetNextLine(input, tempPos, temp);
		int lineLen = (int)strlen(temp);
		g.Init(lineLen);


		int pos = 0;
		int line = 0;
		while (pos < len) {
			char buff[512] = { '\0' };
			Utils::GetNextLine(input, pos, buff);

			if (strlen(buff) != GSize) {
				printf("badInput!\n");
			}

			for (int i = 0; i < GSize; i++) {
				g.Val(line, i) = buff[i] == '#';
			}
			line++;
		}

		g.SetCorners();
	}

	static void Calculate() {
		bool test = false;

		Grid g;
		Populate(g, test);

		int frames = test ? 5 : 100;

		// get initial count
		DoCount(g);
		printf("\n    -+= Step %d =+-\n", 0);
		g.Print();

		for (int i = 0; i < frames; i++) {
			SetNewVal(g);
			DoCount(g);
			printf("\n    -+= Step %d =+-\n", i+1);
			g.Print();
		}

		int finalCount = CountOn(g);
		printf("Advent_2015_18    %d\n", finalCount);

	}
};
int Advent_2015_18::GSize = 0;

class Advent_2015_19 {
public:

	typedef std::map<std::string, std::unordered_set<std::string>> CMap;

	static void FindAllCombos(CMap& cmap, const char* input, 
		std::unordered_set<std::string>& results, int maxLen) {
		int len = (int)strlen(input);
		for (int i = 0; i < len; i++) {
			for (const auto& kvp : cmap) {
				if (strstr(input + i, kvp.first.c_str()) == input + i)
				{
					AddResult(input, i, kvp.first, kvp.second, results, maxLen);
				}
			}
		}
	}

	static int TryMake(int depth, int currStep, const char* goal, int goalLen,
		std::string& elements, CMap& cmap, std::unordered_set<std::string>& badPaths) {

		currStep++;

		int minSteps = INT_MAX;

		std::unordered_set<std::string> results;
		FindAllCombos(cmap, elements.c_str(), results, goalLen);

		if (results.size() == 0)
		{
			badPaths.insert(elements);
			return INT_MAX;
		}

		int progress = 0;
		int totalProgress = (int)results.size();
		for (auto r : results) {
			if (depth < 3) {
				for (int d = 0; d < depth; d++)
					printf(".");
				printf(" %d \\ %d\n", progress , totalProgress);
			}

			if (r.size() == goalLen)
			{
				if (r._Equal(goal)) {
					return currStep;
				}
			}

			if (badPaths.find(r) != badPaths.end())
				continue;

			int stepsTaken = TryMake(depth + 1, currStep, goal, goalLen, r, cmap, badPaths);
			if (stepsTaken < minSteps) {
				minSteps = stepsTaken;
			}

			progress++;
		}
		// all recursive calls failed, add the element to the badPath
		if (minSteps == INT_MAX) {
			badPaths.insert(elements);
		}

		return minSteps;
	}

	static void PopulateMap(CMap& cmap) {
		const char* input = Utils::ReadInput("2015_19_2.txt");

		size_t len = strlen(input);
		int pos = 0;
		while (pos < len) {
			char buff[512] = { '\0' };
			Utils::GetNextLine(input, pos, buff);
			std::vector<std::string> tokens;
			Utils::Tokenize(buff, " ", tokens);

			if (cmap.find(tokens[0]) == cmap.end()) {
				cmap.insert(std::make_pair(tokens[0], std::unordered_set<std::string>()));
			}
			cmap[tokens[0]].insert(tokens[2]);
		}
	}

	static void ReverseMap(CMap& cmap) {
		CMap nmap;

		for (auto kvp : cmap) {
			for (auto e : kvp.second) {
				if (nmap.find(e) == nmap.end()) {
					nmap.insert(std::make_pair(e, std::unordered_set<std::string>()));
				}
				nmap[e].insert(kvp.first);
			}
		}

		cmap = nmap;
	}

	static void AddResult(const char* input, int index, const std::string& subStr, 
		const std::unordered_set<std::string>& replacements, 
		std::unordered_set<std::string>& results, int maxLen = INT_MAX) {

		std::string strInput = input;
		for (auto i : replacements) {
			std::string newStr = strInput.substr(0, index);
			newStr.append(i);
			newStr.append(strInput.substr(index + (int)subStr.length()));

			//if (newStr.size() <= maxLen) 
			{
				results.insert(newStr);
			}
		}
	}

	static void Calculate() {
		const char* input = Utils::ReadInput("2015_19_1.txt");

		std::unordered_set<std::string> results;

		CMap cmap;
		PopulateMap(cmap);

		FindAllCombos(cmap, input, results, (int)strlen(input));
		int result1 = (int)results.size();


		ReverseMap(cmap);
		std::string startingSet = input;
		std::unordered_set<std::string> badPaths;
		int result2 = TryMake(0, 0, "e", 1, startingSet, cmap, badPaths);

		printf("Advent_2015_19    %d   %d\n", result1, result2);
	}
};

class Advent_2015_20 {
public:

	static void Calculate() {


		int goal = 36000000;
		int house = 0;
		int numAtHouse = 0;
		while (numAtHouse < goal) {
			house++;
			numAtHouse = 0;
			for (int i = 1; i <= house; i++) {
				if (house % i == 0 && house / i < 50 )
					numAtHouse += i * 11;
			}
			//printf("house %d   :  %d\n", house, numAtHouse);
		}

		printf("solution: %d\n", house);

	}
};

class Advent_2015_21 {
public:

	struct Mod {
		Mod(int g, int d, int s) {
			gold = g;
			shield = s;
			damage = d;
		}
		int gold = 0;
		int shield = 0;
		int damage = 0;
	};

	struct AllMods {
	public:
		std::vector<Mod> weapons;
		std::vector<Mod> armor;
		std::vector<Mod> ring;
	};

	struct Loadout {
		Loadout(int w, int r1, int r2, int s) {
			weapon = w;
			ring1 = r1;
			ring2 = r2;
			armor = s;
		}
		int GetCost(AllMods& mods)
		{
			int cost = 0;
			if (weapon >= 0)
				cost += mods.weapons[weapon].gold;
			if (armor >= 0)
				cost += mods.armor[armor].gold;
			if (ring1 >= 0)
				cost += mods.ring[ring1].gold;
			if (ring2 >= 0)
				cost += mods.ring[ring2].gold;

			return cost;
		}
		void Print(AllMods& mods) {
			printf("%d - %d : %d : %d : %d\n", GetCost(mods), weapon, armor, ring1, ring2);
			printf("     %d : %d : %d\n", mods.weapons[weapon].gold , mods.weapons[weapon].damage, mods.weapons[weapon].shield);
			printf("     %d : %d : %d\n", mods.armor[armor].gold, mods.armor[armor].damage, mods.armor[armor].shield);
			printf("     %d : %d : %d\n", mods.ring[ring1].gold, mods.ring[ring1].damage, mods.ring[ring1].shield);
			printf("     %d : %d : %d\n", mods.ring[ring2].gold, mods.ring[ring2].damage, mods.ring[ring2].shield);

		}

		int	weapon = -1;
		int ring1 = -1;
		int ring2 = -1;
		int armor = -1;
	};

	struct Player {
	public:
		Player(int h, int d, int s) {
			hp = h;
			damage = d;
			shield = s;
		}
		bool IsDead() const { return hp <= 0; }
		void Attack(Player& o) {
			int d = damage - o.shield;
			d = std::max(d, 1);
			o.hp -= d;
		}
		void Apply(Mod& m) {
			damage += m.damage;
			shield += m.shield;
		}
		void Apply(Loadout l, AllMods& mods) {
			if (l.weapon >= 0)
				Apply(mods.weapons[l.weapon]);
			if (l.armor >= 0)
				Apply(mods.armor[l.armor]);
			if (l.ring1 >= 0)
				Apply(mods.ring[l.ring1]);
			if (l.ring2 >= 0)
				Apply(mods.ring[l.ring2]);
		}

		int hp;
		int damage;
		int shield;
	};

	static void InitMods(AllMods& m) {

//Weapons:    Cost  Damage  Armor
//	Dagger        8     4       0
//	Shortsword   10     5       0
//	Warhammer    25     6       0
//	Longsword    40     7       0
//	Greataxe     74     8       0
		m.weapons.push_back(Mod(8,  4, 0));
		m.weapons.push_back(Mod(10, 5, 0));
		m.weapons.push_back(Mod(25, 6, 0));
		m.weapons.push_back(Mod(40, 7, 0));
		m.weapons.push_back(Mod(74, 8, 0));


//	Armor : Cost  Damage  Armor
//	Leather      13     0       1
//	Chainmail    31     0       2
//	Splintmail   53     0       3
//	Bandedmail   75     0       4
//	Platemail   102     0       5
		m.armor.push_back(Mod(0,  0, 0));
		m.armor.push_back(Mod(13, 0, 1));
		m.armor.push_back(Mod(31, 0, 2));
		m.armor.push_back(Mod(53, 0, 3));
		m.armor.push_back(Mod(75, 0, 4));
		m.armor.push_back(Mod(102,0, 5));


//	Rings : Cost  Damage  Armor
//	Damage + 1    25     1       0
//	Damage + 2    50     2       0
//	Damage + 3   100     3       0
//	Defense + 1   20     0       1
//	Defense + 2   40     0       2
//	Defense + 3   80     0       3
		m.ring.push_back(Mod(0,  0, 0));
		m.ring.push_back(Mod(0,  0, 0));
		m.ring.push_back(Mod(25, 1, 0));
		m.ring.push_back(Mod(50, 2, 0));
		m.ring.push_back(Mod(100,3, 0));
		m.ring.push_back(Mod(20, 0, 1));
		m.ring.push_back(Mod(40, 0, 2));
		m.ring.push_back(Mod(80, 0, 3));
	}

	static bool Simulate(Player p, Player e) {
		while (true) {
			p.Attack(e);
			if (e.IsDead())
				return true;

			e.Attack(p);
			if (p.IsDead())
				return false;
		}

		return false;
	}

	static int FindCheapLoadout(Player startingPlayer, Player e, AllMods& mods) {

		int best = 0;

		for (int w = 0; w < mods.weapons.size(); w++) {
			for (int r1 = 0; r1 < mods.ring.size(); r1++) {
				for (int r2 = 0; r2 < mods.ring.size(); r2++) {
					if (r1 == r2)
						continue;

					for (int s = 0; s < mods.armor.size(); s++) {
						Loadout l = Loadout(w, r1, r2, s);
						int cost = l.GetCost(mods);
						if (cost < best)
							continue;

						Player p = startingPlayer;
						p.Apply(l, mods);
						if (!Simulate(p, e)) {
							l.Print(mods);
							best = cost;
						}
					}

				}

			}

		}
		return best;
	}

	static void Calculate() {

		Player enemy  = Player(109, 8, 2);
		Player player = Player(100, 0, 0);

		AllMods store;
		InitMods(store);

		int cheapest = FindCheapLoadout(player, enemy, store);

 		printf("Advent_2015_21     %d\n", cheapest);

	}
};

class Advent_2015_22 {
public:

	typedef uint64_t StateHash;

	enum SpellType {
		Missile,
		Drain,
		Shield,
		Poison,
		Recharge,
		None,
	};

	struct Player {
	public:
		Player(int h, int d, int m) {
			hp = h;
			damage = d;
			mana = m;
			shield = 0;
		}
		bool IsDead() const { return hp <= 0; }
		void Attack(Player& o) {
			int d = damage - o.shield;
			d = std::max(d, 1);
			o.hp -= d;
		}

		int hp;
		int damage;
		int shield;
		int mana;
	};

	struct  Spell
	{
	public:
		Spell() {
			type = None;
			damage = -1;
			shield = -1;
			heal = -1;
			mana = -1;
			cost = -1;
			time = -1;
		}
		Spell(const Spell& rhs) {
			type	= rhs.type	;
			damage	= rhs.damage;	
			shield	= rhs.shield;	
			heal	= rhs.heal	;
			mana	= rhs.mana	;
			cost	= rhs.cost	;
			time	= rhs.time	;
		}
		Spell(SpellType t, int c, int d, int s, int h, int m, int tme) {
			type = t;
			damage = d;
			shield = s;
			heal = h;
			mana = m;
			cost = c;
			time = tme;
		}
		void Cast(Player& self, Player& other) const {

			self.mana -= cost;

			switch (type)
			{
			case Advent_2015_22::Missile:
				other.hp -= damage;
				break;
			case Advent_2015_22::Drain:
				self.hp  += heal;
				other.hp -= damage;
				break;
			case Advent_2015_22::Shield:
				self.shield += shield;
				break;
			case Advent_2015_22::Poison:
				break;
			case Advent_2015_22::Recharge:
				break;
			default:
				break;
			}
		}
		void Tick(Player& self, Player& other) const {
			switch (type)
			{
			case Advent_2015_22::Missile:
				break;
			case Advent_2015_22::Drain:
				break;
			case Advent_2015_22::Shield:
				break;
			case Advent_2015_22::Poison:
				other.hp -= damage;
				break;
			case Advent_2015_22::Recharge:
				self.mana += mana;
				break;
			default:
				break;
			}
		}
		void Remove(Player& self) const {
			switch (type)
			{
			case Advent_2015_22::Missile:
				break;
			case Advent_2015_22::Drain:
				break;
			case Advent_2015_22::Shield:
				self.shield -= shield;
				break;
			case Advent_2015_22::Poison:
				break;
			case Advent_2015_22::Recharge:
				break;
			default:
				break;
			}

		}

		SpellType type;
		int damage = 0;
		int shield = 0;
		int heal = 0;
		int mana = 0;
		int cost = 0;
		int time = 0;
	};

	typedef std::map < SpellType, std::string> SpellNameLookup;
	typedef std::vector<SpellType> SpellTypeList;
	typedef std::unordered_map<SpellType, Spell> SpellList;
	struct ActiveSpells {
		ActiveSpells() {
			spell[0] = 0;
			spell[1] = 0;
			spell[2] = 0;
			spell[3] = 0;
			spell[4] = 0;
		}
		uint8_t spell[None];
	};
	typedef std::unordered_set<StateHash> StateHistory;

	static SpellList sSpellList;
	static SpellNameLookup sSpellNameLookup;
	static StateHistory sHistory;
	static bool sHardMode;

	static StateHash HashState(Player& p, Player& e, const ActiveSpells aSpells) {

		struct WState {
			uint32_t pHealth : 6;
			uint32_t pShield : 3;
			uint32_t pDamage : 3;
			uint32_t pMana	 : 9;
			uint32_t eHealth : 6;	// 37

			uint32_t s1Time  : 4;	
			uint32_t s2Time  : 4;	
			uint32_t s3Time  : 4;	
			uint32_t s4Time  : 4;	
			uint32_t s5Time  : 4;
		};

		union UnionState {
			WState state;
			uint64_t raw;
		} ;
		UnionState uState;

		uState.state.pHealth = p.hp;
		uState.state.pDamage = p.damage;
		uState.state.pMana = p.mana;
		uState.state.pShield = p.shield;
		uState.state.eHealth = e.hp;

		uState.state.s1Time = aSpells.spell[0];
		uState.state.s2Time = aSpells.spell[1];
		uState.state.s3Time = aSpells.spell[2];
		uState.state.s4Time = aSpells.spell[3];
		uState.state.s5Time = aSpells.spell[4];

		return uState.raw;
	}

	static void InitMods() {
		auto pair = std::make_pair<SpellType, Spell>(Missile, Spell(Missile, 53, 4, 0, 0, 0, 0));


		sSpellList.insert(pair);
		sSpellList.insert(std::make_pair( Drain,   Spell(Drain,    73, 2, 0, 2,  0,  0)));
		sSpellList.insert(std::make_pair( Shield,  Spell(Shield,  113, 0, 7, 0,  0,  6)));
		sSpellList.insert(std::make_pair( Poison,  Spell(Poison,  173, 3, 0, 0,  0,  6)));
		sSpellList.insert(std::make_pair( Recharge,Spell(Recharge,229, 0, 0, 0, 101, 5)));

		sSpellNameLookup[Missile] = "Missile";
		sSpellNameLookup[Drain] = "Drain";
		sSpellNameLookup[Shield] = "Shield";
		sSpellNameLookup[Poison] = "Poison";
		sSpellNameLookup[Recharge] = "Recharge";
		sSpellNameLookup[None] = "None";
	}

	static void TickActiveSpells(Player& p, Player& e, ActiveSpells& spells) {
		for (int i = 0; i < None; i++) {
			if (spells.spell[i] > 0)
			{
				sSpellList[(SpellType)i].Tick(p, e);
				spells.spell[i]--;

				if(spells.spell[i] == 0 ) {
					sSpellList[(SpellType)i].Remove(p);
				}
			}
		}
	}

	static void DebugPrint(int depth, SpellType sType) {
		//while (depth-- > 0) {
		//	printf("  .");
		//}
		//printf("%s\n", sSpellNameLookup[sType].c_str());
	}

	static int Simulate(ActiveSpells active, 
		Player startPlayer, Player startEnemy, int runningManaCost, SpellTypeList& spellPath, int depth) {

		// don't calculate again
		StateHash currHash = HashState(startPlayer, startEnemy, active);
		if (sHistory.find(currHash) != sHistory.end())
			return INT_MAX;
		sHistory.insert(currHash);

		// hardmode
		if (sHardMode) {
			startPlayer.hp--;
			if (startPlayer.IsDead())
				return INT_MAX;
		}

		// Apply all the active spells
		TickActiveSpells(startPlayer, startEnemy, active);
		if (startEnemy.IsDead())
		{
			return runningManaCost;
		}


		// Simulation still going.  Pick another spell and continue
		int best = INT_MAX;
		SpellTypeList bestPath;

		if (active.spell[0] > 0 && 
			active.spell[1] > 0 &&
			active.spell[2] > 0 &&
			active.spell[3] > 0 &&
			active.spell[4] > 0 )
		{
			Player p = startPlayer;
			Player e = startEnemy;

			// Apply magic
			TickActiveSpells(p, e, active);
			if (e.IsDead())
			{
				return runningManaCost;
			}

			// enemy attack
			e.Attack(p);
			if (p.IsDead())
				return INT_MAX;

			// only thing to do is to not cast another spell, and take another turn
			SpellTypeList newPath = spellPath;
			newPath.push_back(None);
			DebugPrint(depth, None);
			best = Simulate(active, p, e, runningManaCost, newPath, depth+1);
			return best;
		} else {
			for (const auto& kvp : sSpellList) {
				const Spell& spell = kvp.second;
				Player p = startPlayer;
				Player e = startEnemy;

				// spell already active
				if (active.spell[spell.type] > 0)
					continue;

				SpellTypeList newSpellPath = spellPath;
				int newRunningCost = runningManaCost;

				// add to the active list 
				ActiveSpells newActive = active;

				if (spell.cost < p.mana) {
					spell.Cast(p, e);
					newActive.spell[spell.type] = sSpellList[(spell.type)].time;
					newRunningCost += spell.cost;
					newSpellPath.push_back(spell.type);
				}
				else {
					continue;
				}

				if (e.IsDead())
				{
					if (newRunningCost < best) {
						best = newRunningCost;
						bestPath = newSpellPath;
					}
				}


				// EnemyTurn
				// Apply magic
				TickActiveSpells(p, e, newActive);
				if (e.IsDead()) {
					if (newRunningCost < best) {
						best = newRunningCost;
						bestPath = newSpellPath;
					}
				}

				// enemy attack
				e.Attack(p);
				if (p.IsDead())
					continue;


				// Next Player turn
				DebugPrint(depth, spell.type);
				int spentMana = Simulate(newActive, p, e, newRunningCost, newSpellPath, depth + 1);
				if (spentMana < best) {
					best = spentMana;
					bestPath = newSpellPath;

					//if (spentMana == 953)
					//	printf("debug\n");
				}
			}
		}

		if(best != INT_MAX)
			spellPath = bestPath;
		return best;
	}

	static int SimulateStart(Player startPlayer, Player startEnemy) {

		ActiveSpells activeSpells;
		SpellTypeList bestPath;
		int spentMana = Simulate(activeSpells, startPlayer, startEnemy, 0, bestPath, 0);

		Replay(bestPath, startPlayer, startEnemy);

		return spentMana;
	}

	static void ReplayPrint(Player& p, Player& e, SpellType newSpell) {
		printf("player - hp:%d  shield:%d  mana:%d     Boss - hp:%d       Cast %s\n",
			p.hp, p.shield, p.mana, e.hp, sSpellNameLookup[newSpell].c_str());
	}

	static void ReplayPrint(Player& p, Player& e) {
		printf("player - hp:%d  shield:%d  mana:%d     Boss - hp:%d       Boss attcks: %d\n",
			p.hp, p.shield, p.mana, e.hp, e.damage);
	}

	static void Replay(const SpellTypeList replayList, Player p, Player e) {

		ActiveSpells activeSpells;

		int turn = 0;
		while (true) {
			SpellType spellType = None;
			if (replayList.size() > turn) {
				spellType = replayList[turn];
			}
			turn++;

			if (sHardMode) {
				p.hp--;
				if (p.IsDead())
				{
					printf("Fuck\n");
				}
			}

			TickActiveSpells(p, e, activeSpells);
			if (e.IsDead()) {
				printf("The boss is dead!\n");
				break;
			}

			Spell newSpell = sSpellList[spellType];

			if (newSpell.cost < p.mana) {
				newSpell.Cast(p, e);
				activeSpells.spell[newSpell.type] = sSpellList[(newSpell.type)].time;
			}
			ReplayPrint(p, e, spellType);
			if (e.IsDead()) {
				printf("The boss is dead!\n");
				break;
			}

			// EnemyTurn
			// Apply magic
			TickActiveSpells(p, e, activeSpells);
			if (e.IsDead()) {
				printf("The boss is dead!\n");
				break;
			}

			// enemy attack
			e.Attack(p);
			ReplayPrint(p, e);

			if (p.IsDead())
			{
				// shouldn't get here!!
				printf("Fuck\n");
			}
		};

		printf("end of replay\n");

	}

	static void Calculate()
	{
		Player enemy = Player(55, 8, 0);
		Player player = Player(50, 0, 500);

		// Player enemy = Player(14, 8, 0);
		// Player player = Player(10, 0, 250);

		// Player enemy = Player(45, 8, 0);
		// Player player = Player(40, 0, 500);

		InitMods();

		int lowestCost = SimulateStart(player, enemy);

		printf("Advent_2015_22    %d\n", lowestCost);

	}
};
Advent_2015_22::SpellNameLookup Advent_2015_22::sSpellNameLookup;
Advent_2015_22::SpellList Advent_2015_22::sSpellList;
Advent_2015_22::StateHistory Advent_2015_22::sHistory;
bool Advent_2015_22::sHardMode = true;

class Advent_2015_23 {
public:

	enum IType {
		Half,
		Triple,
		Increment,
		Jump,
		JumpEven,
		Jumpone,
	};

	class Instruction {
	public:
		IType		type;
		std::string	reg;
		int32_t		arg;

		uint32_t Run(uint32_t ip) {
			if (type == Half) {
				uint64_t val = sRegisters[reg];
				val /= 2;
				sRegisters[reg] = val;
				ip++;
			}
			else if (type == Triple) {
				uint64_t val = sRegisters[reg];
				val *= 3;
				sRegisters[reg] = val;
				ip++;
			}
			else if (type == Increment) {
				uint64_t val = sRegisters[reg];
				val++;
				sRegisters[reg] = val;
				ip++;
			}
			else if (type == Jump) {
				ip += arg;
			}
			else if (type == JumpEven) {
				uint64_t val = sRegisters[reg];
				if (val % 2 == 0) {
					ip += (uint32_t)arg;
				}
				else {
					ip++;
				}
			}
			else if (type == Jumpone) {
				uint64_t val = sRegisters[reg];
				if (val == 1) {
					ip += (uint32_t)arg;
				}
				else {
					ip++;
				}
			}

			return ip;
		}

	};

	typedef std::map<std::string, uint64_t> Registers;
	typedef std::vector<Instruction> InstList;
	static InstList sInst;
	static Registers sRegisters;

	static Instruction ParseTokens(std::vector<std::string> tokens) {
		Instruction inst;
		if (tokens[0]._Equal("hlf")) {
			inst.type = Half;
			inst.reg = tokens[1];
		}
		else if (tokens[0]._Equal("tpl")) {
			inst.type = Triple;
			inst.reg = tokens[1];
		}
		else if (tokens[0]._Equal("inc")) {
			inst.type = Increment;
			inst.reg = tokens[1];
		}
		else if (tokens[0]._Equal("jmp")) {
			inst.type = Jump;
			inst.arg = atoi(tokens[1].c_str());
		}
		else if (tokens[0]._Equal("jie")) {
			inst.type = JumpEven;
			inst.reg = tokens[1].substr(0, tokens[1].size()-1);
			inst.arg = atoi(tokens[2].c_str());
		}
		else if (tokens[0]._Equal("jio")) {
			inst.type = Jumpone;
			inst.reg = tokens[1].substr(0, tokens[1].size() - 1);
			inst.arg = atoi(tokens[2].c_str());
		}
		else {
			printf("Invalid input:   %s\n", tokens[0].c_str());
		}

		return inst;
	}

	static void ReadInput() {
		const char* input = Utils::ReadInput("2015_23.txt");
		int len = (int)strlen(input);
		int pos = 0;
		while (pos < len) {
			char buff[128];
			Utils::GetNextLine(input, pos, buff);

			std::vector<std::string> tokens;
			Utils::Tokenize(buff, " ", tokens);

			sInst.push_back(ParseTokens(tokens));
		}
	}

	static void Calculate() {
		ReadInput();

		sRegisters.insert(std::make_pair("a", 1));
		sRegisters.insert(std::make_pair("b", 0));

		uint32_t ip = 0;
		while (ip < sInst.size()) {
			ip = sInst[ip].Run(ip);
		}

		for (auto kvp : sRegisters) {
			printf("\t%s: %lld\n", kvp.first.c_str(), kvp.second);
		}

	}
};
Advent_2015_23::InstList Advent_2015_23::sInst;
Advent_2015_23::Registers Advent_2015_23::sRegisters;


class Advent_2015_24 {
public:
	struct SeatData{
		SeatData() : weight(0), bucket(0) {}
		SeatData(int w, int b) : weight(w), bucket(b) {}
		int weight;
		int bucket;
	};

	static int HashCompare(uint64_t a, uint64_t b) {
		int numBitsA = NumBitsSet(a);
		int numBitsB = NumBitsSet(b);
		if (numBitsA < numBitsB)
			return true;
		else if (numBitsB < numBitsA)
			return false;
		else
		{
			uint64_t QEA = GetQEValue(a);
			uint64_t QEB = GetQEValue(b);
			return QEA < QEB;
		}
	}

	typedef std::vector<int> InitList;
	typedef std::vector<SeatData> Assignments;
	typedef std::unordered_set<uint64_t> HashSet;
	typedef std::set<uint64_t, decltype(&HashCompare)> SortedHashSet;
	static InitList sInitList;
	static int sIdealWeight;
	static SortedHashSet sHashSet;
	static SortedHashSet sPossibleHash;
	static uint64_t sHashMask;

	static uint64_t Hash(Assignments& data, int bucket) {
		uint64_t hash = 0;
		for (uint64_t i = 0; i < data.size(); i++) {
			if (data[i].bucket == bucket) {
				hash |= 1ULL << i;
			}
		}
		return hash;
	}

	static void ParseInput() {
		InitList list;
		const char* input = Utils::ReadInput("2015_24.txt");
		int pos = 0;
		int len = (int)strlen(input);
		while (pos < len) {
			char buff[32];
			Utils::GetNextLine(input, pos, buff);
			int val = atoi(buff);
			list.push_back(val);
		}

		std::sort(list.begin(), list.end());

		InitList finalList;
		for (auto a = list.rbegin(); a != list.rend(); a++)
			finalList.push_back(*a);

		sInitList = finalList;
	}

	static uint64_t GetQEValue(Assignments& data, int bucket)
	{
		uint64_t val = 1;
		for (auto kvp : data) {
			if (kvp.bucket == bucket) {
				val *= kvp.weight;
			}
		}
		return val;
	}

	static uint64_t GetQEValue(uint64_t hash) {
		uint64_t total = 1;
		for (int i = 0; i < sizeof(uint64_t) * 8; i++)
		{
			if ((hash & sHashMask) == 0)
				break;

			if (hash & (1ULL << i))
				total *= sInitList[i];
		}
		return total;
	}

	static void PrintfQE(Assignments& data, int bucket) {
		uint32_t sum = 0;
		for (auto x : data) {
			if (x.bucket == bucket) {
				sum += x.weight;
				printf("%d  ", x.weight);
			}
		}
		printf("\t\t%llu\t%d\n", GetQEValue(data, bucket), sum);
	}

	static int CountNumberInBucket(Assignments& data, int bucket) {
		int count = 0;
		for (auto a : data) {
			if (a.bucket == bucket)
				count++;
		}
		return count;
	}

	static bool BuildHash(Assignments& data, int remaining, int currPos) {

		while (currPos < data.size()) {
			int pos = currPos++;

			// already taken
			if (data[pos].bucket != 0)
				continue;

			// no more possible values;
			if (data[pos].weight > remaining) {
				continue;
			}

			// have a match, return true;
			if (data[pos].weight == remaining) {
				data[pos].bucket = 1;

				uint64_t hash = Hash(data, 1);
				sHashSet.insert(hash);

				return true;
			}

			//  need to recurse to fill another seat
			Assignments assignment = data;
			assignment[pos].bucket = 1;
			BuildHash(assignment, remaining - assignment[pos].weight, pos + 1);
		}
		return false;
	}

	static bool AssignBucket(Assignments& data, int remaining, int currPos, int bucket) {

		int best = INT_MAX;
		Assignments bestData;

		while (currPos < data.size()) {
			int pos = currPos++;

			// already taken
			if (data[pos].bucket != 0)
				continue;

			// no more possible values;
			if (data[pos].weight > remaining) {
				break;
			}

			// have a match, return true;
			if (data[pos].weight == remaining) {
				data[pos].bucket = bucket;
				
				// see if the remaining values can be added
				uint64_t currHash = Hash(data, bucket);
				uint64_t otherHash = ~currHash & sHashMask;	// remaining values
				if (DoesHashFit(otherHash, currHash))
				{
					sPossibleHash.insert(currHash);
					return true;
				}
			}

			//  need to recurse to fill another seat
			Assignments assignment = data;
			assignment[pos].bucket = bucket;
			if (AssignBucket(assignment, remaining - assignment[pos].weight, pos + 1, bucket))
			{
				int count = CountNumberInBucket(assignment, bucket);
				if (count < best) {
					best = count;
					bestData = assignment;
				}
				if (count == best) {
					//if (count == 6)
					//	printf("debug\n");

					//PrintfQE(bestData, bucket);
					//PrintfQE(assignment, bucket);

					// we have a tie... get a lowest QE
					uint64_t bestQE = GetQEValue(bestData, bucket);
					uint64_t currQE = GetQEValue(assignment, bucket);
					if (currQE < bestQE) {
						bestData = assignment;
					}
				}
			}
		}

		if (best < INT_MAX) {
			data = bestData;
			return true;
		}
		else {
			return false;
		}
	}

	static uint64_t FindFirstFit() {
		for (auto a : sHashSet) {
			// see if the remaining values can be added
			uint64_t otherHash = ~a & sHashMask;	// remaining values
			if (DoesHashFit(otherHash, a))
			{
				// sHashSet is sorted, so the first acceptable solution is the best
				return a;
			}
		}
		return 0;
	}

	static uint64_t FindFirstFitSecondPart() {
		for (auto a : sHashSet) {
			for (auto b : sHashSet) {
				// a and b can't overlap
				if (((a & b) & sHashMask) != 0)
					continue;

				// see if the remaining values can be added
				uint64_t otherHash = ~(a|b) & sHashMask;	// remaining values
				if (DoesHashFit(otherHash, a))
				{
					// sHashSet is sorted, so the first acceptable solution is the best
					return a;
				}
			}
		}
		return 0;
	}

	static bool DoesHashFit(uint64_t hash, uint64_t exclude, int print = false) {
		for (auto a : sHashSet) {
			if (((a & hash) & sHashMask) == a &&
				(exclude & a) == 0)
			{
				if (print)
				{
					PrettyPrintHash(exclude);
					
					//PrintHash(hash);
					PrettyPrintHash(a);

					uint64_t other = (~a & hash) & sHashMask;
					PrettyPrintHash(other);
				}

				return true;
			}
		}
		return false;
	}

	static uint64_t SumOfHash(uint64_t hash) {
		uint64_t total = 0;
		for (int i = 0; i < sizeof(uint64_t) * 8; i++)
		{
			if (hash & (1ULL << i)) {
				total += sInitList[i];
			}
		}
		return total;
	}

	static void PrintHash(uint64_t hash) {
		for (int i = 0; i < sizeof(uint64_t) * 8; i++)
		{
			if ((sHashMask & (1ULL << i)) == 0)
				break;

			printf("%s", (hash & (1ULL << i)) != 0 ? "1" : "0");
		}
		printf("\t%llu\n", SumOfHash(hash));
	}

	static void PrettyPrintHash(uint64_t hash) {
		for (int i = 0; i < sizeof(uint64_t) * 8; i++)
		{
			if ((sHashMask & (1ULL << i)) == 0)
				break;

			if (hash & (1ULL << i)) {
				printf("%d  ", sInitList[i]);
			}
		}
		printf("\t%llu\n", SumOfHash(hash));
	}

	static int NumBitsSet(uint64_t hash) {
		int bits = 0;
		for (int i = 0; i < sizeof(uint64_t) * 8; i++)
		{
			if ((hash & sHashMask) == 0)
				break;

			if (hash & (1ULL << i))
				bits++;
		}
		return bits;
	}

	static void Calculate() {
		ParseInput();

		// get the ideal size
		int total = 0;
		for (auto a : sInitList)
			total += a;
		sIdealWeight = total / 4;

		// build hashMask;
		sHashMask = 0;
		for (uint64_t i = 0; i < sInitList.size(); i++)
			sHashMask |= 1ULL << i;

		Assignments data;
		for (auto a : sInitList)
			data.push_back(SeatData(a, 0));

		// actually just builds the hashSet
		BuildHash(data, sIdealWeight, 0);
		//uint64_t bestHash = FindFirstFit();
		uint64_t bestHash = FindFirstFitSecondPart();
		//BuildPossibleList();
		//// Reset Data
		//for (auto a : data)
		//	a.bucket = 0;
		//
		//AssignBucket(data, sIdealWeight, 0, 1);

		//uint64_t bestQE = ~(0ULL);
		//uint64_t bestHash = 0;
		//int bestNum = INT_MAX;
		//for (auto p : sPossibleHash) {
		//	int bits = NumBitsSet(p);
		//	if (bits < bestNum) {
		//		bestNum = bits;
		//		bestQE = GetQEValue(p);
		//		bestHash = p;
		//	}
		//	else if (bits == bestNum) {
		//		uint64_t qe = GetQEValue(p);
		//		if (qe < bestQE) {
		//			bestQE = qe;
		//			bestHash = p;
		//		}
		//	}
		//}

		//PrettyPrintHash(bestHash);

		uint64_t otherMask = (~bestHash) & sHashMask;
		for (auto a : sHashSet) {
			if ((a & otherMask) == a) {
				uint64_t third = (~a & otherMask) & sHashMask;

				PrintHash(bestHash);
				PrintHash(a);
				PrintHash(third);
				printf("\n");
				PrettyPrintHash(bestHash);
				PrettyPrintHash(a);
				PrettyPrintHash(third);


				break;
			}
		}
		// find other values

		printf("Advent_2015_24   %llu\n", GetQEValue(bestHash));
	}
};
Advent_2015_24::InitList Advent_2015_24::sInitList;
int Advent_2015_24::sIdealWeight = 0;
uint64_t Advent_2015_24::sHashMask;
Advent_2015_24::SortedHashSet Advent_2015_24::sHashSet(&HashCompare);
Advent_2015_24::SortedHashSet Advent_2015_24::sPossibleHash(&HashCompare);

class Advent_2015_25 {
public:

	static uint64_t getNum(uint32_t index) {
		uint64_t prevNum = 20151125;
		for (uint32_t i = 1; i < index; i++) {
			prevNum = calcNum(prevNum);
		}

		return prevNum;
	}

	static uint64_t calcNum(uint64_t prevNum) {
		uint64_t val = prevNum * 252533;
		return val % 33554393;
	}

	static uint32_t ToIndex(int row, int col) {
		row--;
		int columnStart = 0;
		for (int i = 0; i < col;)
		{
			columnStart += ++i;
		}

		uint32_t ret = columnStart;
		for (int i = 0; i < row;) {
			ret += col + i;

			i++;
		}


		return ret;
	}

	static void DebugPrint(int row, int col) {
		for (int i = 1; i < row+1; i++)
		{
			for (int j = 1; j < col+1; j++)
			{
				int val = ToIndex(i, j);
				printf("%llu\t", getNum(val));
			}
			printf("\n");
		}
	}

	static void Calculate() {
		// 3010, column 3019.

		uint32_t finalIndex = ToIndex(3010, 3019);
		uint64_t finalCode = getNum(finalIndex);
		printf("Advent_2015_25      %llu\n", finalCode);
	}
};

#pragma endregion

class Advent_2022_01 {
public:
	static uint32_t GetTopCalories(int num, std::set<uint32_t>& elves) {
		uint32_t ret = 0;

		auto iter = elves.rbegin();
		for (int i = 0; i < num; i++)
		{
			ret += *iter;
			iter++;
		}

		return ret;
	}

	static void Calculate()	{
		const char* input = Utils::ReadInput("2022_01.txt");

		int len = (int)strlen(input);
		int pos = 0;

		std::set<uint32_t> elves;
		uint32_t currCount = 0;
		while (pos < len) {
			char buff[64] = { '\0' };
			Utils::GetNextLine2(input, pos, buff);

			if (strlen(buff) == 0) {
				elves.insert(currCount);
				currCount = 0;
				continue;
			}

			currCount += atoi(buff);
		}
		elves.insert(currCount);

		uint32_t firstPart = GetTopCalories(1, elves);
		uint32_t secondPart = GetTopCalories(3, elves);
		printf("Advent_2022_01    %u    %u\n", firstPart, secondPart);


	}
};

class Advent_2022_02 {
public:
	static void Calculate()
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
};

class Advent_2022_03 {
public:
	static uint64_t GetLetterRank(char c) {
		uint64_t rank = 0;
		if (islower(c))
			rank = (c - 'a') + 1;
		else 
			rank = (c - 'A') + 27;
		return rank;
	}

	static int Part1(const char* input) {
		int totalLen = (int)strlen(input);
		int pos = 0;
		int totalScore = 0;
		while (pos < totalLen) {
			char buff[512];
			Utils::GetNextLine(input, pos, buff);

			int sackSize = (int)strlen(buff) / 2;
			uint64_t s1 = 0, s2 = 0;
			for (int i = 0; i < sackSize; i++) {
				s1 |= 1ULL << GetLetterRank(buff[i]);
				s2 |= 1ULL << GetLetterRank(buff[i + sackSize]);
			}

			uint64_t common = s1 & s2;
			for (int i = 0; i < sizeof(uint64_t) * 8; i++) {
				if ((common & (1ULL << i)) != 0) {
					totalScore += i;
					break;
				}
			}
		}
		return totalScore;
	}

	static int Part2(const char* input) {
		int totalLen = (int)strlen(input);
		int pos = 0;
		int totalScore = 0;
		while (pos < totalLen) {
			char buff1[512];
			char buff2[512];
			char buff3[512];
			Utils::GetNextLine(input, pos, buff1);
			Utils::GetNextLine(input, pos, buff2);
			Utils::GetNextLine(input, pos, buff3);

			uint64_t s1 = 0, s2 = 0, s3 = 0;;
			for (int i = 0; i < (int)strlen(buff1); i++)
				s1 |= 1ULL << GetLetterRank(buff1[i]);
			for (int i = 0; i < (int)strlen(buff2); i++)
				s2 |= 1ULL << GetLetterRank(buff2[i]);
			for (int i = 0; i < (int)strlen(buff3); i++)
				s3 |= 1ULL << GetLetterRank(buff3[i]);

			uint64_t common = s1 & s2 & s3;
			for (int i = 0; i < sizeof(uint64_t) * 8; i++) {
				if ((common & (1ULL << i)) != 0) {
					totalScore += i;
					break;
				}
			}
		}
		return totalScore;
	}

	static void Calculate()
	{
		const char* input = Utils::ReadInput("2022_03.txt");

		printf("Advent_2022_03   %d     %d\n", Part1(input), Part2(input) );
	}
};

class Advent_2022_04 {
public:
	static void Calculate()
	{
		const char* input = Utils::ReadInput("2022_04.txt");
		int len = (int)strlen(input);
		int pos = 0;
		int count1 = 0;
		int count2 = 0;
		while (pos < len) {
			char buff[32];
			Utils::GetNextLine(input, pos, buff);
			uint32_t min1, max1, min2, max2;

			int buffPos = 0;
			if (!Utils::GetNextUint(buff, buffPos, min1)) printf("Debug\n");
			if (!Utils::GetNextUint(buff, ++buffPos, max1)) printf("Debug\n");
			if (!Utils::GetNextUint(buff, ++buffPos, min2)) printf("Debug\n");
			if (!Utils::GetNextUint(buff, ++buffPos, max2)) printf("Debug\n");

			if ((min1 <= min2 && max1 >= max2) ||
				(min2 <= min1 && max2 >= max1))
				count1++;

			if ((min1 <= min2 && max1 >= min2) ||
				(min2 <= min1 && max2 >= min1))
				count2++;
		}


		int answer1 = count1;
		int answer2 = count2;
		printf("Advent_2022_04   %d     %d\n", answer1, answer2);
	}
};

class Advent_2022_05 {
public:
	static bool sPart2;

	struct MoveData {
		int num;
		int src;
		int dst;
	};

	typedef std::vector<char> Stack;
	typedef std::vector<Stack> Stacks;
	typedef std::vector<MoveData> Moves;

	static void InitNewStack(Stacks& stacks, const char* input) {
		stacks.push_back(Stack());
		Stack& stack = stacks[stacks.size() - 1];
		int len = (int)strlen(input);
		for (int i = 0; i < len; i++) {
			stack.push_back(input[i]);
		}
	}

	static void Print(Stacks& stacks) {
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

	static void Init(Stacks& stacks) {
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

	static void Move(Stacks& stacks, int num, int src, int dest) {
		// data is 1-based
		Stack& srcStack = stacks[src - 1];
		Stack& destStack = stacks[dest - 1];

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

	static void PopulateMoves(Moves& moves) {
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

			MoveData m;
			m.num = atoi(tokens[1].c_str());
			m.src = atoi(tokens[3].c_str());
			m.dst = atoi(tokens[5].c_str());

			moves.push_back(m);
		}
	}

	static std::string GetTopItems(Stacks& stacks) {
		std::string answer;

		for (auto stack : stacks) {
			char buff[2] = { '\0' };
			buff[0] = stack.back();
			answer.append(buff);
		}

		return answer;
	}

	static void Calculate() {
		Moves moves;
		PopulateMoves(moves);

		// Part 1
		sPart2 = false;
		Stacks stacks;
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
};
bool Advent_2022_05::sPart2 = false;

class Advent_2022_06 {
public:
	static bool ValidWindow(const char* input, int windowSize) {
		for (int i = 0; i < windowSize - 1; i++) {
			for (int j = i + 1; j < windowSize; j++) {
				if (input[i] == input[j]) {
					return false;
				}
			}
		}
		return true;
	}

	static void Calculate() {
		const char* input = Utils::ReadInput("2022_06.txt");
		int len = (int)strlen(input);
		int part2 = false;
		int windowSize = part2 ? 4 : 14;
		int pos = 0;

		int start = -1;
		while ((pos + windowSize) < len) {
			if (ValidWindow(input + pos, windowSize)) {
				start = pos + windowSize;
				break;
			}
			else {
				pos++;
			}
		}

		printf("Advent_2022_06   %d\n", start);
	}
};

class Advent_2022_07 {
public:

	class Directory {
	public:
		Directory(const std::string& n, Directory* p) : directSize(0), indirectSize(0), name(n), parent(p) {}
		void AddFile(const std::string& fileName, size_t size) {
			directSize += size;
		}
		void AddTryDir(const std::string& newName, Directory* parent) {
			auto iter = children.find(newName);
			// already exists
			if (iter != children.end())
				return;

			Directory* newChild = new Directory(newName, parent);
			children.insert(std::make_pair(newName, newChild));
		}
		Directory* GetChild(const std::string& dirName) {
			auto iter = children.find(dirName);
			return iter->second;
		}
		size_t CalculateIndirectSize() {
			indirectSize = directSize;
			for (auto c : children)
				indirectSize += c.second->CalculateIndirectSize();
			return indirectSize;
		}

		size_t directSize;
		size_t indirectSize;
		Directory* parent;
		std::map<std::string,Directory*> children;
		std::string name;
	};

	static Directory* rootDir;
	static Directory* cwd;

	static void PopulateDirs() {
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
					Directory* newDir = cwd->GetChild(newDirName);
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
	static size_t SumAtMost(Directory* dir, size_t maxSize) {
		size_t total = 0;
		if (dir->indirectSize <= maxSize)
			total += dir->indirectSize;

		for (auto c : dir->children) {
			total += SumAtMost(c.second, maxSize);
		}

		return total;
	}
	static size_t FindClosestTo(Directory* dir, size_t desiredSize) {
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

	static void Calculate() {
		rootDir = new Directory("/", nullptr);
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
};
Advent_2022_07::Directory* Advent_2022_07::rootDir = nullptr;
Advent_2022_07::Directory* Advent_2022_07::cwd = nullptr;

class Advent_2022_08 {
public:

	class Grid {
	public:
		Grid(const char* fileName) {
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
		int Get(int x, int y) {
			return data[y][x] - '0';
		}
		int GetIncreasingCount(int startX, int startY, int dX, int dY) {
			int x = startX;
			int y = startY;


			int count = 0;
			int curr = -1;

			while (x >= 0 && y >= 0 && x < SizeX && y < SizeY) {
				int d = Get(x, y);
				if (d > curr) {
					curr = d;
					count++;
					visible.insert(std::make_pair(x, y));
				}
				x += dX;
				y += dY;
			}
			return count;
		}
		int GetSeeCount(int startX, int startY, int dX, int dY) {
			int count = 0;
			int curr = -1;
			int startingHeight = Get(startX, startY);
			int x = startX + dX;
			int y = startY + dY;
			while (x >= 0 && y >= 0 && x < SizeX && y < SizeY) {
				int d = Get(x, y);
				count++;

				if (d >= startingHeight)
					break;
				x += dX;
				y += dY;
			}
			return count;
		}
		int GetBestScore() {

			int bestScore = 0;
			for (int x = 0; x < SizeX; x++) {
				for (int y = 0; y < SizeX; y++) {

					if (x == 2 && y == 3)
						printf("debug");

					int score = GetSeeCount(x, y, 1, 0);
					score *= GetSeeCount(x, y, -1, 0);
					score *= GetSeeCount(x, y, 0, 1);
					score *= GetSeeCount(x, y, 0, -1);

					bestScore = std::max(score, bestScore);
				}
			}

			return bestScore;
		}

		int SizeX;
		int SizeY;
		std::vector<std::string> data;
		std::set<std::pair<int, int>> visible;
	};


	static void Calculate() {
		Grid grid("2022_08.txt");

		for (int i = 0; i < grid.SizeX; i++) {
			grid.GetIncreasingCount(i, 0, 0, 1);
			grid.GetIncreasingCount(i, grid.SizeY-1, 0, -1);
		}
		for (int i = 0; i < grid.SizeY; i++) {
			grid.GetIncreasingCount(0, i, 1, 0);
			grid.GetIncreasingCount(grid.SizeX-1, i, -1, 0);
		}

		int answer = (int)grid.visible.size();
		int bestScore = grid.GetBestScore();
		printf("Advent_2022_08    %d    %d", answer, bestScore);
	}
};

class Advent_2022_09 {
public:

	struct IntPos{
		int x;
		int y;
	};
	struct Rope {
		static constexpr const int NumKnots = 10;
		IntPos knots[NumKnots];
		Rope() {
			for (int i = 0; i < NumKnots; i++) {
				knots[i].x = 0;
				knots[i].y = 0;
			}
		}
		void MarkTail() {
			visted.insert(std::make_pair(knots[NumKnots-1].x, knots[NumKnots - 1].y));
		}
		int KnotAtPos(int x, int y) {
			for (int i = 0; i < NumKnots; i++) {
				if (knots[i].x == x && knots[i].y == y)
					return i;
			}
			return -1;
		}
	};
	typedef std::set<std::pair<int, int>> VisitedGrid;
	static VisitedGrid visted;

	static void UpdateRope(int dX, int dY, Rope& rope) {
		rope.knots[0].x += dX;
		rope.knots[0].y += dY;

		for (int i = 0; i < rope.NumKnots - 1; i++) {
			IntPos& headPos = rope.knots[i];
			IntPos& tailPos = rope.knots[i+1];

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

	static void DoMove(char direction, int steps, Rope& rope) {
		int dX = 0;
		int dY = 0;
		switch (direction) {
			case 'U': dY = 1;  break;
			case 'D': dY = -1; break;
			case 'L': dX = -1;  break;
			case 'R': dX = 1; break;
		}

		while (steps-- > 0) {
			UpdateRope(dX, dY, rope);
		}
	}

	static void Calculate() {
		const char* input = Utils::ReadInput("2022_09.txt");
		int len = (int)strlen(input);
		int pos = 0;

		Rope rope;
		rope.MarkTail();

		while (pos < len) {
			char buff[32];
			Utils::GetNextLine(input, pos, buff);

			DoMove(buff[0], atoi(buff + 1), rope);
		}
		printf("Advent_2022_09   %zu\n", visted.size());
	}
};
Advent_2022_09::VisitedGrid Advent_2022_09::visted;


class Advent_2022_10 {
public:
	static void Calculate() {

	}
};

int main()
{
#pragma region 2015
	// Advent_2015_01::Calculate1();
	// Advent_2015_01::Calculate2();
	// Advent_2015_02::Calculate1();
	// Advent_2015_03::Calculate1();
	// Advent_2015_03::Calculate2();
	// Advent_2015_04::Calculate1();
	// Advent_2015_05::Calculate1();
	// Advent_2015_05::Calculate2();
	// Advent_2015_06::Calculate1();
	// Advent_2015_07::Calculate1();
	// Advent_2015_08::Calculate();
	// Advent_2015_09::Calculate();
	// Advent_2015_10::Calculate();
	// Advent_2015_11::Calculate();
	// Advent_2015_12::Calculate1();
	// Advent_2015_12::Calculate2();
	// Advent_2015_13::Calculate1();
	// Advent_2015_13::Calculate2();
	// Advent_2015_14::Calculate();
	// Advent_2015_15::Calculate();
	// Advent_2015_16::Calculate();
	// Advent_2015_17::Calculate();
	// Advent_2015_18::Calculate();
	// Advent_2015_19::Calculate();
	// Advent_2015_20::Calculate();
	// Advent_2015_21::Calculate();
	// Advent_2015_22::Calculate();
	// Advent_2015_23::Calculate();
	// Advent_2015_24::Calculate();
	// Advent_2015_25::Calculate();
#pragma endregion

	//Advent_2022_01::Calculate();
	//Advent_2022_02::Calculate();
	//Advent_2022_03::Calculate();
	//Advent_2022_04::Calculate();
	//Advent_2022_05::Calculate();
	//Advent_2022_06::Calculate();
	//Advent_2022_07::Calculate();
	//Advent_2022_08::Calculate();
	Advent_2022_09::Calculate();
	Advent_2022_10::Calculate();

	return 0;
}
