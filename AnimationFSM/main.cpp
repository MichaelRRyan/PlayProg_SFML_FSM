#include <iostream>
#include <SFML/Graphics.hpp>
#include <AnimatedSprite.h>
#include <Player.h>
#include <Input.h>
#include <Debug.h>

using namespace std;

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("assets\\sprites.png")) {
		DEBUG_MSG("Failed to load file");
		return EXIT_FAILURE;
	}

	// Setup Players Default Animated Sprite
	AnimatedSprite animated_sprite(texture);

	// Idle
	animated_sprite.addFrame(sf::IntRect(3, 3, 84, 84));
	animated_sprite.addFrame(sf::IntRect(88, 3, 84, 84));
	animated_sprite.addFrame(sf::IntRect(173, 3, 84, 84));
	animated_sprite.addFrame(sf::IntRect(258, 3, 84, 84));
	animated_sprite.addFrame(sf::IntRect(343, 3, 84, 84));
	animated_sprite.addFrame(sf::IntRect(428, 3, 84, 84));

	// Jumping
	animated_sprite.addFrame(sf::IntRect(3, 88, 84, 84));
	animated_sprite.addFrame(sf::IntRect(88, 88, 84, 84));
	animated_sprite.addFrame(sf::IntRect(173, 88, 84, 84));
	animated_sprite.addFrame(sf::IntRect(258, 88, 84, 84));
	animated_sprite.addFrame(sf::IntRect(343, 88, 84, 84));
	animated_sprite.addFrame(sf::IntRect(428, 88, 84, 84));

	// Falling
	animated_sprite.addFrame(sf::IntRect(3, 173, 84, 84));
	animated_sprite.addFrame(sf::IntRect(88, 173, 84, 84));
	animated_sprite.addFrame(sf::IntRect(173, 173, 84, 84));
	animated_sprite.addFrame(sf::IntRect(258, 173, 84, 84));
	animated_sprite.addFrame(sf::IntRect(343, 173, 84, 84));
	animated_sprite.addFrame(sf::IntRect(428, 173, 84, 84));

	// Landing
	animated_sprite.addFrame(sf::IntRect(3, 258, 84, 84));
	animated_sprite.addFrame(sf::IntRect(88, 258, 84, 84));
	animated_sprite.addFrame(sf::IntRect(173, 258, 84, 84));
	animated_sprite.addFrame(sf::IntRect(258, 258, 84, 84));
	animated_sprite.addFrame(sf::IntRect(343, 258, 84, 84));
	animated_sprite.addFrame(sf::IntRect(428, 258, 84, 84));

	// Setup the Player
	Player player(animated_sprite);
	//Input input;
	
	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				// Close window : exit
				window.close();
				break;
			/*case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					input.setCurrent(Input::Action::LEFT);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					input.setCurrent(Input::Action::RIGHT);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					input.setCurrent(Input::Action::UP);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					input.setCurrent(Input::Action::DOWN);
				}
				break;
			default:
				input.setCurrent(Input::Action::IDLE);
				break;*/
			}
		}

		// Handle input to Player
		player.handleInput();

		// Update the Player
		player.update();

		// Clear screen
		window.clear();

		// Draw the Players Current Animated Sprite
		window.draw(player.getAnimatedSprite());

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
};