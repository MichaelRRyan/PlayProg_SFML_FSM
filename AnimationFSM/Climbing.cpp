#include <Climbing.h>
#include <Jumping.h>
#include <Idle.h>
#include <Falling.h>

#include <string>

void Climbing::handleInput(PlayerFSM* a, AnimatedSprite* t_animatedSprite)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		t_animatedSprite->changeAnimation(Animation::Jumping);
		jumping(a);
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		t_animatedSprite->changeAnimation(Animation::Falling);
		falling(a);
	}
}

void Climbing::update(PlayerFSM* a, AnimatedSprite* t_animatedSprite)
{
	if (m_clock.getElapsedTime().asSeconds() > 1.0f)
	{
		t_animatedSprite->changeAnimation(Animation::Idle);
		idle(a);
	}
}

void Climbing::idle(PlayerFSM* a)
{
	std::cout << "Climbing -> Idle" << std::endl;
	a->setCurrent(new Idle());
	a->setCurrentName("idle");
	delete this;
}
void Climbing::jumping(PlayerFSM* a)
{
	std::cout << "Climbing -> Jump" << std::endl;
	a->setCurrent(new Jumping());
	a->setCurrentName("jumping");
	delete this;
}

void Climbing::falling(PlayerFSM* a)
{
	std::cout << "Climbing -> Falling" << std::endl;
	a->setCurrent(new Falling());
	a->setCurrentName("falling");
	delete this;
}
