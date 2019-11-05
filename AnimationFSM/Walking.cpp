#include "Walking.h"
#include "Jumping.h"
#include "Idle.h"
#include "Falling.h"

void Walking::handleInput(PlayerFSM* a, AnimatedSprite* t_animatedSprite)
{
	if ((t_animatedSprite->getScale().x > 0 && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		|| (t_animatedSprite->getScale().x < 0 && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
	{
		t_animatedSprite->changeAnimation(Animation::Idle);
		idle(a);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
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
	a->setCurrentName("jumping");
	delete this;
}

void Walking::idle(PlayerFSM* a)
{
	std::cout << "Walking -> Idle" << std::endl;
	a->setCurrent(new Idle());
	a->setCurrentName("idle");
	delete this;
}

void Walking::falling(PlayerFSM* a)
{
	std::cout << "Walking -> Falling" << std::endl;
	a->setCurrent(new Falling());
	a->setCurrentName("falling");
	delete this;
}
