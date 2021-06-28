#include "or.h"

gate_OR::gate_OR(void)
{
	setInput(0, 0);
}

gate_OR::~gate_OR(void)
{
	
}

void gate_OR::gateOperation(void)
{
	if(inputX == 1 || inputY == 1)
		result = 1;
	else
		result = 0;
}