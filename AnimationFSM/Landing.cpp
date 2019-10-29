#include "Landing.h"
#include "Idle.h"

#include <string>

Landing::Landing()
{
	m_clock.restart();
}

void Landing::update(PlayerFSM* a)
{
	if (m_clock.getElapsedTime().asSeconds() > 1.0f) // Check if one second has elapsed since started landing
	{
		idle(a);
	}
}

void Landing::idle(PlayerFSM* a)
{
	std::cout << "Landing -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
