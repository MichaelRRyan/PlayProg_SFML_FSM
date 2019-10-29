#include <Idle.h>
#include <Jumping.h>
#include <Climbing.h>
#include "Walking.h"
#include "Falling.h"

#include <string>

void Idle::handleInput(PlayerFSM* a)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		jumping(a);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		climbing(a);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		walking(a);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		falling(a);
	}
}
void Idle::update(PlayerFSM* a)
{
	handleInput(a);
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
