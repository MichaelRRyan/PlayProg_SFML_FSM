#include <Idle.h>
#include <Jumping.h>
#include <Climbing.h>
#include "Walking.h"
#include "Falling.h"

#include <string>

void Idle::handleInput(PlayerFSM* a, AnimatedSprite* t_animatedSprite)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		t_animatedSprite->changeAnimation(Animation::Jumping);
		jumping(a);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		t_animatedSprite->changeAnimation(Animation::Climbing);
		climbing(a);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		t_animatedSprite->changeAnimation(Animation::Walking);
		walking(a);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		t_animatedSprite->changeAnimation(Animation::Falling);
		falling(a);
	}
}

void Idle::update(PlayerFSM* a, AnimatedSprite* t_animatedSprite)
{
}

void Idle::jumping(PlayerFSM* a)
{
	std::cout << "Idle -> Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}
void Idle::climbing(PlayerFSM* a)
{
	std::cout << "Idle -> Climbing" << std::endl;
	a->setCurrent(new Climbing());
	delete this;
}

void Idle::walking(PlayerFSM* a)
{
	std::cout << "Idle -> Walking" << std::endl;
	a->setCurrent(new Walking());
	delete this;
}

void Idle::falling(PlayerFSM* a)
{
	std::cout << "Idle -> Falling" << std::endl;
	a->setCurrent(new Falling());
	delete this;
}
