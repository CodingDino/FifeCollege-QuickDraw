// Included Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
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

	// Timer functionality
	float signalTimeLowerLimit = 5.0f;
	float signalTimeUpperLimit = 10.0f;
	sf::Time timeTilSignal = sf::seconds(0.0f);
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
