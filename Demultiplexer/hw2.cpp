#include <iostream>
#include <string>
#include "H.h"

using namespace std;

int main(){

	string str;
	Demultiplexer D;

	cout << "Input tne value (E, B, A): ";
	cin >> str;

	D.SetInput(str);
	D.Print();

	return 0;
}