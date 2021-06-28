#include "H.h"
#include "nand.h"
#include "and.h"
#include "not.h"
#include "defaultgate.h"
#include <iostream>
#include <string>

using namespace std;

void Demultiplexer::SetInput(string input){
	E = input.at(0) - 48;
	B = input.at(1) - 48;
	A = input.at(2) - 48;

	this->Calculating();
}

void Demultiplexer::Calculating(){

	gate_AND AND;
	gate_NAND NAND;
	gate_NOT NOT;

	if(E == 1){
		for(int i=0; i<4; i++)
			output[i] = 1;

		return;
	}

	unsigned short value1, value2;

	NOT.setInput(E);
	unsigned short not_e = NOT.getOutput();

	NOT.setInput(A);
	value1 = NOT.getOutput();
	NOT.setInput(B);
	value2 = NOT.getOutput();

	AND.setInput(value1, value2);
	NAND.setInput( AND.getOutput(), not_e );
	output[0] = NAND.getOutput();

	NOT.setInput(B);
	AND.setInput( NOT.getOutput(), A );
	NAND.setInput( AND.getOutput(), not_e );
	output[1] = NAND.getOutput();

	NOT.setInput(A);
	AND.setInput( NOT.getOutput(), B );
	NAND.setInput( AND.getOutput(), not_e );
	output[2] = NAND.getOutput();

	AND.setInput(A, B);
	NAND.setInput( AND.getOutput(), not_e );
	output[3] = NAND.getOutput();

}

void Demultiplexer::Print(){

	cout << "Result: ";

	for(int i=3; i>=0; i--)
		cout << output[i];

	cout << endl;

}