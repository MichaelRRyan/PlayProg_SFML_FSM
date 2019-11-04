#include <Climbing.h>
#include <Jumping.h>
#include <Idle.h>
#include <Falling.h>

#include <string>

void Climbing::handleInput(PlayerFSM* a, AnimatedSprite* t_animatedSprite)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		t_animatedSprite->changeAnimation(Animation::Jumping);
		jumping(a);
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		t_animatedSprite->changeAnimation(Animation::Falling);
		falling(a);
	}
}

void Climbing::update(PlayerFSM* a, AnimatedSprite* t_animatedSprite)
{
	if (m_clock.getElapsedTime().asSeconds() > 2.0f)
	{
		t_animatedSprite->changeAnimation(Animation::Idle);
		idle(a);
	}
}

void Climbing::idle(PlayerFSM* a)
{
	std::cout << "Climbing -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
void Climbing::jumping(PlayerFSM* a)
{
	std::cout << "Climbing -> Jump" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}

void Climbing::falling(PlayerFSM* a)
{
	std::cout << "Climbing -> Falling" << std::endl;
	a->setCurrent(new Falling());
	delete this;
}
