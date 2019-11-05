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

	// Add all the textures
	for (int row = 0; row < 6; row++)
	{
		for (int col = 0; col < 6; col++)
		{
			animated_sprite.addFrame(sf::IntRect(3 + (85 * col), 3 + (85 * row), 82, 82));
		}
	}

	// Setup the Player
	Player player(animated_sprite);
	Input input;

	player.setPosition({ 0.0f, 500.0f });
	
	// Start the game loop
	while (window.isOpen())
	{
		input.setAllFalse();

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
			case sf::Event::KeyPressed:
				if (sf::Keyboard::Left == event.key.code)
				{
					input.m_leftPressed = true;
				}
				break;
			}
		}

		// Get input
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			input.m_left = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			input.m_right = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			input.m_up = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			input.m_down = true;
		}

		// Handle input to Player
		player.handleInput(input);

		// Update the Player
		player.update();

		if (player.getPositon().x > 800)
		{
			player.setPosition({ -82.0f,player.getPositon().y });
		}
		else if (player.getPositon().x < -82)
		{
			player.setPosition({ 800,player.getPositon().y });
		}

		if (player.getPositon().y > 600 - 82)
		{
			player.setPosition({ player.getPositon().x, 600 - 82 });
		}
		else if (player.getPositon().y < 0)
		{
			player.setPosition({ player.getPositon().x, 0 });
		}

		// Clear screen
		window.clear(sf::Color::White);

		// Draw the Players Current Animated Sprite
		window.draw(player.getAnimatedSprite());

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
};