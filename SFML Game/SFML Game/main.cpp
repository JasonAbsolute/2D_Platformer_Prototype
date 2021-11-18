#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Player.h"
using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "OpenGL", sf::Style::Close | sf::Style::Resize);
	//window.setVerticalSyncEnabled(true);
	//window.setFramerateLimit(60);
	window.setActive(true);
	
	
	sf::Texture playerTexture;
	playerTexture.loadFromFile("151264.png");


	//setting up animation
	Player player(&playerTexture, sf::Vector2u(9, 6), 0.1f, 100.0f);

	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();


		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type) {
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::Resized:
				std::cout << "New window width: " << evnt.size.width << "new window height :" << evnt.size.height << std::endl;
				printf("New window Width: %i New window Height %i\n", evnt.size.width, evnt.size.height);
				break;
			case sf::Event::TextEntered:
				if (evnt.text.unicode < 128) {
					printf("%c", evnt.text.unicode);

				}
			}
		}
		
		player.Update(deltaTime);

		window.clear(sf::Color(150, 150, 150));
		player.Draw(window);
		window.display();


	}

	return 0;
}