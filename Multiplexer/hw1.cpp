#include <iostream>
#include <string>
#include "encoder(h).h"
#include "and.h"
#include "or.h"
#include "not.h"

using namespace std;

int main(){

	string input;  // input: input���� ���� 4�ڸ��� ��
	string select;  // select: selection���� ���� 2�ڸ��� ��

	cout << "Input: 4 inputs, 2 selections : ";
	cin >> input >> select;  // 2���� ���� �Է¹���

	if(input.length() != 4 || select.length() != 2){  // �Է¹��� ���� �ڸ����� ���� ������ error
		cout << "Error: more or less dights" << endl;
		return 1;
	}

	for(int i=0; i<4; i++)
		if(input.at(i) != '0' && input.at(i) != '1'){  // 0,1 �̿��� ���� �Է����� ��� error (1)
			cout << "Error: unavailable vaule" << endl;
			return 1;
		}

	for(int i=0; i<2; i++)
		if(select.at(i) != '0' && select.at(i) != '1'){  // 0,1 �̿��� ���� �Է����� ��� error (2)
			cout << "Error: unavailable vaule" << endl;
			return 1;
		}

	Multiplexer M;  // M: Multiplexer
	M.SetInput(input, select);
	M.Print();

	return 0;
}