#include "defaultgate.h"

#pragma once

class gate_OR : public defaultGate
{
public:
	gate_OR(void);
	~gate_OR(void);

	virtual void gateOperation();
};