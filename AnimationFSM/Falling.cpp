#include "Falling.h"
#include "Landing.h"
#include "Jumping.h"

#include <string>

void Falling::landing(PlayerFSM* a)
{
	std::cout << "Falling -> Landing" << std::endl;
	a->setCurrent(new Landing());
	delete this;
}
