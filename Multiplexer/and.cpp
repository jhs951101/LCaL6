#include "and.h"

gate_AND::gate_AND(void)
{
	setInput(0, 0);
}

gate_AND::~gate_AND(void)
{
	
}

void gate_AND::gateOperation(void)
{
	if(inputX == 1 && inputY == 1)
		result = 1;
	else
		result = 0;
}