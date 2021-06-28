#include "nand.h"

gate_NAND::gate_NAND(void)
{
	setInput(0, 0);
}

gate_NAND::~gate_NAND(void)
{
	
}

void gate_NAND::gateOperation(void)
{
	if(inputX == 1 && inputY == 1)
		result = 0;
	else
		result = 1;
}