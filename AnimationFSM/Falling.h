#ifndef FALLING_H
#define FALLING_H

#include <State.h>

class Falling : public State
{
public:
	Falling() {};
	~Falling() {};
	void landing(PlayerFSM* a);
};

#endif // !FALLING_H