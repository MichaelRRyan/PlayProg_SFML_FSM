#include "Walking.h"
#include "Jumping.h"
#include "Idle.h"
#include "Falling.h"

void Walking::jumping(PlayerFSM* a)
{
	std::cout << "Walking -> Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}

void Walking::idle(PlayerFSM* a)
{
	std::cout << "Walking -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Walking::falling(PlayerFSM* a)
{
	std::cout << "Walking -> Falling" << std::endl;
	a->setCurrent(new Falling());
	delete this;
}
