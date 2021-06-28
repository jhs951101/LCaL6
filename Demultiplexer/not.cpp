#include "not.h"

gate_NOT::gate_NOT(void)
{
	setInput(0);
}

gate_NOT::~gate_NOT(void)
{
	
}

void gate_NOT::gateOperation(void)  // problem
{
	if(inputX == 1)
		result = 0;
	else
		result = 1;
}

void gate_NOT::setInput(unsigned short x)
{
	inputX = x;
	inputY = 1;

	gateOperation();
}