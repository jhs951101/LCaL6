#include "encoder(h).h"
#include "or.h"
#include "and.h"
#include "not.h"
#include "defaultgate.h"
#include <iostream>
#include <string>

using namespace std;

void  Multiplexer::SetInput(string Str, string selectStr){  // input�� selection�� Ŭ���� ������ ������
	
	for(int i=0; i<4; i++)
		input[i] = Str.at(i) - 48;

	for(int i=0; i<2; i++)
		select[i] = selectStr.at(i) - 48;

	this->Calculating();

}

void  Multiplexer::Calculating(){  // input�� selection�� �̿��� ���� ������

	gate_AND AND;
	gate_OR OR;
	gate_NOT NOT;  // AND, OR, NOT ����Ʈ ���
	unsigned short value1, value2, value3, value4;  // value1,2,3,4: 4���� and����Ʈ�� ���� �� �����

	unsigned short not_s0, not_s1;  // not_s0, not_s1 : selection�� not ���� ����

	NOT.setInput(select[0]);
	not_s0 = NOT.getOutput();

	NOT.setInput(select[1]);
	not_s1 = NOT.getOutput();

	AND.setInput(select[0], select[1]);
	AND.setInput( AND.getOutput(), input[3] );
	value4 = AND.getOutput();  // �� �Ʒ��� �ִ� and����Ʈ ���� ����

	AND.setInput( not_s0, select[1]);
	AND.setInput( AND.getOutput(), input[2] );
	value3 = AND.getOutput();  // �Ʒ����� �ι�°�� �ִ� and����Ʈ ���� ����

	AND.setInput( not_s1, select[0]);
	AND.setInput( AND.getOutput(), input[1] );
	value2 = AND.getOutput();  // �Ʒ����� ����°�� �ִ� and����Ʈ ���� ����

	AND.setInput(not_s0, not_s1);
	AND.setInput( AND.getOutput(), input[0] );
	value1 = AND.getOutput();  // �� ���� �ִ� and����Ʈ ���� ����

	OR.setInput(value1, value2);
	OR.setInput( OR.getOutput(), value3 );
	OR.setInput( OR.getOutput(), value4 );
	output = OR.getOutput();  // �� and����Ʈ ���� ����� ����� ������

}

void  Multiplexer::Print(){  // ���� ���� �����

	cout << "Result: " << output << endl;

}