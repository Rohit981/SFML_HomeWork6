// We need to include our header file to implement the function prototypes of our Game class
#include "Game.h"
#include<iostream>

// Since we are in our private .cpp file, it's fine to use a namespace here
using namespace gm;
using namespace sf;
using namespace std;

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() : window(VideoMode(GameWidth, GameHeight), "Game"), clock(), deltaTime(0)
{
	Setup();
	// Set our fps to 60
	window.setFramerateLimit(60);
}

void Game::run() {
	// This is our game loop!
	// All input, logic, and rendering should be handled here
	while (window.isOpen())
	{
		// Every frame we...
		// Keep track of the delta time for smoother movement
		deltaTime = clock.restart().asSeconds();

		// Handle input first...
		handleInput();

		// Then update...
		update();

		// Then render...
		render();





	}
}

// Implements the handle input portion of our Game Loop Programming Pattern
void Game::handleInput()
{
	// Check for events from the window
	// E.g., is the window being closed?
	playerController->HandleInput(window);

}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update()
{
	
	paddle->update(window, deltaTime);

	if (gameUI->GetPlayerLive() > 0)
	{
		if (playerController->IsLeftClicked == false )
		{
			ball->setPosition(Vector2f(paddle->getPosition().x + paddle->getSize().x / 2 + 10, paddle->getPosition().y - paddle->getSize().y / 2 - 5));

		}
		else
		{
			ball->update(window, deltaTime);

			ResetBall();

		
		}

		CollisionCheck();

	}
	else
	{
		
		soundManager->PlayGameOverSFX();

	}



	gameUI->Update(window, deltaTime);


}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render()
{
	// This clears the window at the beginning of every frame
	window.clear();

	// Draw our GameObjects
	paddle->render(window, deltaTime);

	ball->render(window, deltaTime);


	/*paddingTop->render(window, deltaTime);
	paddingLeft->render(window, deltaTime);
	paddingRight->render(window, deltaTime);*/


	gameUI->render(window, deltaTime);




	// Display the window buffer for this frame
	window.display();
}

void Game::Setup()
{
	//Initializing all the GameObjects
	paddle = new Paddle(Vector2f(290, 580), Vector2f(100, 30));
	ball = new Ball(Vector2f(290, 660), Vector2f(20, 20));
	paddingTop = new Paddle(Vector2f(10, 0), Vector2f(640, 2));
	//paddingBottom = new Paddle(Vector2f(50, 620), Vector2f(550, 20));
	paddingLeft = new Paddle(Vector2f(0, 0), Vector2f(2, 640));
	paddingRight = new Paddle(Vector2f(636, 0), Vector2f(2, 640));

	//Initializing the Controllers
	playerController = new PlayerController(paddle);

	gameUI = new UI(ball);
	soundManager = new SoundManager();


}

//Collision check function and setting the reflection vector of the ball when it collides with paddles
// 
// set direction is in which direction the ball will go after colliding with the paddles
//rebound variable is used for the bottom as the ball was not bouncing when it was hitting the pad
void Game::CollisionCheck()
{
	// If the ball collides with box1
	if (paddle->collide(FloatRect(ball->getPosition().x, ball->getPosition().y, ball->getSize().x, ball->getSize().y)))
	{

		ball->reflectionDir = Vector2f(-1, 1);
		ball->rebound = 0;
		ball->setDirection(-1);

		ball->Bounce(ball->getPosition(), paddle->getPosition(), paddle->getSize(), 5);



		soundManager->PlayPaddleSFX();



	}

	//if ball collides with top padding
	if (paddingTop->collide(FloatRect(ball->getPosition().x, ball->getPosition().y, ball->getSize().x, ball->getSize().y)))
	{
		ball->reflectionDir = Vector2f(-1, 1);
		ball->rebound = 0;

		ball->setDirection(1);


		ball->Bounce(ball->getPosition(), paddingTop->getPosition(), paddingTop->getSize(), 0);

		soundManager->PlayWallSFX();

	}



	if (paddingLeft->collide(FloatRect(ball->getPosition().x, ball->getPosition().y, ball->getSize().x, ball->getSize().y)))
	{
		ball->reflectionDir = Vector2f(1, -1);
		ball->rebound = 0;

		ball->Bounce(ball->getPosition(), paddingLeft->getPosition(), paddingLeft->getSize(), 0);
		 
		soundManager->PlayWallSFX();




	}


	if (paddingRight->collide(FloatRect(ball->getPosition().x, ball->getPosition().y, ball->getSize().x, ball->getSize().y)))
	{
		ball->reflectionDir = Vector2f(-1, 1);
		ball->rebound = 0;

		ball->Bounce(ball->getPosition(), paddingRight->getPosition(), paddingRight->getSize(), 0);
		
		soundManager->PlayWallSFX();

	}




}

void Game::ResetBall()
{
	if (ball->getPosition().y > window.getSize().x - ball->getSize().x)
	{
		ball->ResetTimer += deltaTime;

		soundManager->PlayScoreSFX();

	}

	if (ball->ResetTimer >= 1.5f)
	{
		
		playerController->IsLeftClicked = false;

		ball->ResetTimer = 0;

	}
}



// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game()
{

}