#include <iostream>
#include <Player.h>
#include <Idle.h>
#include <Debug.h>

Player::Player()
{
	m_state.setCurrent(new Idle());
	m_state.setPrevious(new Idle());
}

Player::Player(const AnimatedSprite& s) : m_animated_sprite(s)
{
	m_state.setCurrent(new Idle());
	m_state.setPrevious(new Idle());
}

Player::~Player() {}

AnimatedSprite& Player::getAnimatedSprite()
{
	int frame = m_animated_sprite.getCurrentFrame();
	m_animated_sprite.setTextureRect(m_animated_sprite.getFrame(frame));
	return m_animated_sprite;
}

void Player::handleInput()
{
	DEBUG_MSG("Handle Input");

	m_state.handleInput(&m_animated_sprite);
	m_state.update(&m_animated_sprite);

	//switch (in.getCurrent())
	//{
	//case Input::Action::IDLE:
	//	//std::cout << "Player Idling" << std::endl;
	//	m_state.idle();
	//	break;
	//case Input::Action::UP:
	//	//std::cout << "Player Up" << std::endl;
	//	m_state.jumping();
	//	m_state.falling();
	//	m_state.landing();
	//	break;
	//case Input::Action::LEFT:
	//	//std::cout << "Player Left" << std::endl;
	//	m_state.climbing();
	//	break;
	//case Input::Action::RIGHT:
	//	//std::cout << "Player Idling" << std::endl;
	//	m_state.walking();
	//	break;
	//case Input::Action::DOWN:
	//	//std::cout << "Player Idling" << std::endl;
	//	m_state.falling();
	//	m_state.landing();
	//	break;
	//default:
	//	break;
	//}
}

void Player::update()
{
	//std::cout << "Handle Update" << std::endl;
	m_animated_sprite.update();
}