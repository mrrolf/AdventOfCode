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

#include "Utils.h"

///////////////////////////////////////////////////////////////////////////////
char* Utils::ReadInput(const char* fileName) {
	std::string filePath = ".\\adventInput\\";
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
void Utils::Tokenize(char* input, std::vector<std::string>& tokens) {
	Tokenize(input, " ", tokens);
}

///////////////////////////////////////////////////////////////////////////////
void Utils::Tokenize(char* input, const char* delim, std::vector<std::string>& tokens) {
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
	return input[pos] == '-' || std::isdigit(input[pos]);
}

///////////////////////////////////////////////////////////////////////////////
int Utils::GetNextBoolAndAdvance(const char* input, int& pos) {
	int newNum = atoi(input + pos);
	Utils::SkipPastNumber(input, pos);
	return newNum;
}

///////////////////////////////////////////////////////////////////////////////
bool Utils::GetNextUint(const char* input, int& pos, uint32_t& number) {
	while (!std::isdigit(input[pos]) && input[pos] != '\0') pos++;
	if (input[pos] == '\0')
		return false;

	number = (uint32_t)atoi(input + pos);
	while (std::isdigit(input[pos]) && input[pos] != '\0') pos++;
	return true;
}

///////////////////////////////////////////////////////////////////////////////
char Utils::PeekNextChar(const char* input, int pos) {
	int peekPos = pos;
	while (input[peekPos] != '\0' && IsSpaceChar(input[peekPos])) peekPos++;
	return input[peekPos];
}
