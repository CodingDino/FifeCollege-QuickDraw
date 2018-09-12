// Included Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <cstdlib>
#include <ctime>
// end libraries

// Entry point for the program
int main()
{
	// --------------------------------------
	// Game Setup
	// --------------------------------------

	// Render Window creation
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Quick Draw",
		sf::Style::Titlebar | sf::Style::Close);

	// Seed our random number generation
	srand(time(NULL));

	// Timer functionality
	float signalTimeLowerLimit = 5.0f;
	float signalTimeUpperLimit = 10.0f;
	sf::Time timeTilSignal = sf::seconds(signalTimeLowerLimit);
	sf::Time timeSinceSignal = sf::seconds(0.0f);
	sf::Clock gameClock;

	// Create Button Sprite
	sf::Texture buttonTexture;
	buttonTexture.loadFromFile("graphics/button.png");
	sf::Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);
	buttonSprite.setPosition(
		gameWindow.getSize().x / 2 - buttonTexture.getSize().x / 2,
		gameWindow.getSize().y / 2 - buttonTexture.getSize().y / 2
	);

	// --------------------------------------
	// end game setup
	// --------------------------------------



	// --------------------------------------
	// Game Loop
	// --------------------------------------
	// Runs every frame until the game window is closed
	while (gameWindow.isOpen())
	{
		// --------------------------------------
		// Input
		// --------------------------------------

		sf::Event gameEvent;
		// Process events
		while (gameWindow.pollEvent(gameEvent))
		{
			// Check if the event is a mouse button pressed event
			if (gameEvent.type == sf::Event::MouseButtonPressed)
			{
				// Check if we clicked in the button
				if (buttonSprite.getGlobalBounds().contains(gameEvent.mouseButton.x, gameEvent.mouseButton.y))
				{
					// we did!
					int range = (int)(signalTimeUpperLimit - signalTimeLowerLimit);
					float signalSeconds = rand() % range + signalTimeLowerLimit;
					timeTilSignal = sf::seconds(signalSeconds);
				}
			}

			// Check if the event is the closed event
			if (gameEvent.type == sf::Event::Closed)
			{
				// Close the game window
				gameWindow.close();
			} // end Closed event

		} // end input polling while loop

		// --------------------------------------
		// end Input
		// --------------------------------------


		// --------------------------------------
		// Update
		// --------------------------------------

		sf::Time frameTime = gameClock.restart();

		// Update our signal timer
		timeTilSignal = timeTilSignal - frameTime;
		if (timeTilSignal.asSeconds() <= 0.0f)
		{
			// Signal is go!
			buttonSprite.setColor(sf::Color::Red);
		}

		// --------------------------------------
		// end Update
		// --------------------------------------



		// --------------------------------------
		// Draw
		// --------------------------------------

		// Clear the window to a single colour
		gameWindow.clear(sf::Color::Black);

		// Draw everything
		gameWindow.draw(buttonSprite);

		// Display the window contents on the screen
		gameWindow.display();

		// --------------------------------------
		// end Draw
		// --------------------------------------


	} // end of game while loop
	// --------------------------------------
	// end game loop
	// --------------------------------------


	// exit point for the program
	return 0;
} // end of main() function
