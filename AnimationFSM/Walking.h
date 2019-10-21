#ifndef WALKING_H
#define WALKING_H

#include "State.h"

class Walking : public State
{
public:
	Walking() {};
	~Walking() {};
	void jumping(PlayerFSM* a);
	void idle(PlayerFSM* a);
	void falling(PlayerFSM* a);
};

#endif // !WALKING_H