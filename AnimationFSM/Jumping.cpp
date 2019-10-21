#include <Jumping.h>
#include <Climbing.h>
#include "Falling.h"

#include <string>

void Jumping::falling(PlayerFSM* a)
{
	std::cout << "Jumping -> Falling" << std::endl;
	a->setCurrent(new Falling());
	delete this;
}

void Jumping::climbing(PlayerFSM* a)
{
	std::cout << "Jumping -> Climbing" << std::endl;
	a->setCurrent(new Climbing());
	delete this;
}