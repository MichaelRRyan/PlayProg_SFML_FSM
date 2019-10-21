#ifndef JUMPING_H
#define JUMPING_H

#include <State.h>

class Jumping : public State
{
public:
	Jumping() {};
	~Jumping() {};
	void falling(PlayerFSM* a);
	void climbing(PlayerFSM* a);
};

#endif // !IDLE_H