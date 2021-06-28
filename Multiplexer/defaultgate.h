#pragma once

class defaultGate
{
public:
	defaultGate(void);
	~defaultGate(void);

	virtual void gateOperation();

	void setInput(unsigned short x, unsigned short y);
	unsigned short getOutput(void);

protected:
	unsigned short inputX;
	unsigned short inputY;
	unsigned short result;
};