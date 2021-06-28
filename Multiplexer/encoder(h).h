#pragma once

#include <string>

using namespace std;

class Multiplexer
{
public:
	void SetInput(string Str, string selectStr);
	void Calculating();
	void Print();

private:
	unsigned short output;
	unsigned short select[2];
	unsigned short input[4];
};