#include "defaultgate.h"

#pragma once

class gate_AND : public defaultGate
{
public:
	gate_AND(void);
	~gate_AND(void);

	virtual void gateOperation();
};