#pragma once

#include <string>

using namespace std;

class Demultiplexer
{
public:
	void SetInput(string str);
	void Calculating();
	void Print();

private:
	unsigned short E, B, A;  // e, b, a
	unsigned short output[4];
};