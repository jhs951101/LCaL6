#include "encoder(h).h"
#include "or.h"
#include "and.h"
#include "not.h"
#include "defaultgate.h"
#include <iostream>
#include <string>

using namespace std;

void  Multiplexer::SetInput(string Str, string selectStr){  // input과 selection을 클래스 변수에 저장함
	
	for(int i=0; i<4; i++)
		input[i] = Str.at(i) - 48;

	for(int i=0; i<2; i++)
		select[i] = selectStr.at(i) - 48;

	this->Calculating();

}

void  Multiplexer::Calculating(){  // input과 selection을 이용해 값을 추출함

	gate_AND AND;
	gate_OR OR;
	gate_NOT NOT;  // AND, OR, NOT 게이트 사용
	unsigned short value1, value2, value3, value4;  // value1,2,3,4: 4개의 and게이트의 값이 각 저장됨

	unsigned short not_s0, not_s1;  // not_s0, not_s1 : selection의 not 값을 저장

	NOT.setInput(select[0]);
	not_s0 = NOT.getOutput();

	NOT.setInput(select[1]);
	not_s1 = NOT.getOutput();

	AND.setInput(select[0], select[1]);
	AND.setInput( AND.getOutput(), input[3] );
	value4 = AND.getOutput();  // 맨 아래에 있는 and게이트 값을 저장

	AND.setInput( not_s0, select[1]);
	AND.setInput( AND.getOutput(), input[2] );
	value3 = AND.getOutput();  // 아래에서 두번째에 있는 and게이트 값을 저장

	AND.setInput( not_s1, select[0]);
	AND.setInput( AND.getOutput(), input[1] );
	value2 = AND.getOutput();  // 아래에서 세번째에 있는 and게이트 값을 저장

	AND.setInput(not_s0, not_s1);
	AND.setInput( AND.getOutput(), input[0] );
	value1 = AND.getOutput();  // 맨 위에 있는 and게이트 값을 저장

	OR.setInput(value1, value2);
	OR.setInput( OR.getOutput(), value3 );
	OR.setInput( OR.getOutput(), value4 );
	output = OR.getOutput();  // 각 and게이트 값을 계산해 결과를 저장함

}

void  Multiplexer::Print(){  // 계산된 값을 출력함

	cout << "Result: " << output << endl;

}