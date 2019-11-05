#include <iostream>
#include <Player.h>
#include <Idle.h>
#include <Debug.h>

Player::Player()
{
	m_state.setCurrent(new Idle());
	m_state.setPrevious(new Idle());
	m_animated_sprite.setOrigin(41.0f, 0.0);
}

Player::Player(const AnimatedSprite& s) : m_animated_sprite(s)
{
	m_state.setCurrent(new Idle());
	m_state.setPrevious(new Idle());
	m_animated_sprite.setOrigin(41.0f, 0.0);
}

Player::~Player() {}

AnimatedSprite& Player::getAnimatedSprite()
{
	int frame = m_animated_sprite.getCurrentFrame();
	m_animated_sprite.setTextureRect(m_animated_sprite.getFrame(frame));
	return m_animated_sprite;
}

void Player::handleInput(Input t_input)
{
	DEBUG_MSG("Handle Input");

	m_state.handleInput(&m_animated_sprite);

	if (m_clock.getElapsedTime().asSeconds() > 1.0f / 60.0f)
	{
		if (m_state.getCurrentName() == "walking")
		{
			if (m_animated_sprite.getScale().x > 0)
			{
				m_animated_sprite.move(3.0f, 0.0f);
			}
			else
			{
				m_animated_sprite.move(-3.0f, 0.0f);
			}
			
		}

		if (m_state.getCurrentName() == "falling")
		{
			m_animated_sprite.move(0.0f, 5.0f);
		}

		if (m_state.getCurrentName() == "jumping")
		{
			m_animated_sprite.move(0.0f, -5.0f);
		}

		if (m_state.getCurrentName() == "climbing")
		{
			m_animated_sprite.move(0.0f, -3.0f);
		}

		m_clock.restart();
	}
}

void Player::update()
{
	m_animated_sprite.update();
	m_state.update(&m_animated_sprite);
}

void Player::setPosition(sf::Vector2f t_position)
{
	m_animated_sprite.setPosition(t_position);
}

sf::Vector2f Player::getPositon()
{
	return m_animated_sprite.getPosition();
}
