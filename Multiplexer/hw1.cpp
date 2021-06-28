#include <iostream>
#include <string>
#include "encoder(h).h"
#include "and.h"
#include "or.h"
#include "not.h"

using namespace std;

int main(){

	string input;  // input: input으로 사용될 4자리의 값
	string select;  // select: selection으로 사용될 2자리의 값

	cout << "Input: 4 inputs, 2 selections : ";
	cin >> input >> select;  // 2개의 값을 입력받음

	if(input.length() != 4 || select.length() != 2){  // 입력받은 값이 자리수가 맞지 않으면 error
		cout << "Error: more or less dights" << endl;
		return 1;
	}

	for(int i=0; i<4; i++)
		if(input.at(i) != '0' && input.at(i) != '1'){  // 0,1 이외의 값을 입력했을 경우 error (1)
			cout << "Error: unavailable vaule" << endl;
			return 1;
		}

	for(int i=0; i<2; i++)
		if(select.at(i) != '0' && select.at(i) != '1'){  // 0,1 이외의 값을 입력했을 경우 error (2)
			cout << "Error: unavailable vaule" << endl;
			return 1;
		}

	Multiplexer M;  // M: Multiplexer
	M.SetInput(input, select);
	M.Print();

	return 0;
}