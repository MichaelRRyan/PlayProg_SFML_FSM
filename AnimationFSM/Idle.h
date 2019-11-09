#ifndef IDLE_H
#define IDLE_H

#include <State.h>

class Idle : public State
{
public:
	Idle() {};
	~Idle() {};

	void handleInput(PlayerFSM* a, AnimatedSprite* t_animatedSprite, Input t_input);
	void update(PlayerFSM* a, AnimatedSprite* t_animatedSprite);

	void jumping(PlayerFSM* a);
	void climbing(PlayerFSM* a);
	void walking(PlayerFSM* a);
	void falling(PlayerFSM* a);
};

#endif // !IDLE_H