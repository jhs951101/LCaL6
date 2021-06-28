#include "defaultgate.h"

#pragma once

class gate_NAND : public defaultGate
{
public:
	gate_NAND(void);
	~gate_NAND(void);

	virtual void gateOperation();
};