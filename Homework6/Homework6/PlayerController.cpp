#include "PlayerController.h"
#include<iostream>

using namespace gm;
using namespace sf;
using namespace std;

PlayerController::PlayerController(Paddle* playerPaddle)
{
	this->playerPaddle = playerPaddle;
}


PlayerController::~PlayerController()
{

}

void PlayerController::HandleInput(sf::RenderWindow& window)
{
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();

		
		// Handle mouse input to move paddle
		if (Mouse::getPosition(window).x <= (window.getSize().x - playerPaddle->getSize().x) && Mouse::getPosition(window).x >= 0)
		{
			
			playerPaddle->setPosition(Vector2f(Mouse::getPosition(window).x, playerPaddle->getPosition().y));
			

		}

		

		//Move the ball with mouse left click
		if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left && IsLeftClicked == false) 
		{
			IsLeftClicked = true;
		}

		/*if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
		{
			IsLeftClicked = false;
		}*/
			


	}
}
