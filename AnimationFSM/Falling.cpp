#include "Falling.h"
#include "Landing.h"
#include "Jumping.h"

#include <string>

Falling::Falling()
{
	m_clock.restart();
}

void Falling::update(PlayerFSM* a, AnimatedSprite* t_animatedSprite)
{
	if (m_clock.getElapsedTime().asSeconds() > 2.0f) // Check if two seconds have passed since started jumping
	{
		t_animatedSprite->changeAnimation(Animation::Landing);
		landing(a);
	}
}

void Falling::landing(PlayerFSM* a)
{
	std::cout << "Falling -> Landing" << std::endl;
	a->setCurrent(new Landing());
	delete this;
}
