#ifndef JUMPING_H
#define JUMPING_H

#include <State.h>

class Jumping : public State
{
public:
	Jumping();
	~Jumping() {};
	void handleInput(PlayerFSM* a);
	void update(PlayerFSM* a);
	void falling(PlayerFSM* a);
	void climbing(PlayerFSM* a);
private:
	sf::Clock m_clock;
};

#endif // !IDLE_H