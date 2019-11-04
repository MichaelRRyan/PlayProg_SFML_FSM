#include "Walking.h"
#include "Jumping.h"
#include "Idle.h"
#include "Falling.h"

void Walking::handleInput(PlayerFSM* a, AnimatedSprite* t_animatedSprite)
{
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		t_animatedSprite->changeAnimation(Animation::Idle);
		idle(a);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		t_animatedSprite->changeAnimation(Animation::Jumping);
		jumping(a);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		t_animatedSprite->changeAnimation(Animation::Falling);
		falling(a);
	}
}

void Walking::update(PlayerFSM* a, AnimatedSprite* t_animatedSprite)
{
}

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
