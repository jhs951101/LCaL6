#include "defaultgate.h"

defaultGate::defaultGate(void)
{
	setInput(0, 0);
}

defaultGate::~defaultGate(void)
{
	
}

void defaultGate::gateOperation(void)
{
	
}

void defaultGate::setInput(unsigned short x, unsigned short y)
{
	inputX = x;
	inputY = y;

	gateOperation();
}

unsigned short defaultGate::getOutput(void)
{
	return result;
}