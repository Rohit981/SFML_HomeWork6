#define _USE_MATH_DEFINES

#include "Ball.h"
#include <cmath>
#include <math.h>
#include<iostream>

using namespace gm;
using namespace std;
using namespace sf;


Ball::Ball(const sf::Vector2f& position, const sf::Vector2f& size): GameObject(position, size)
{
	this->size = size;
	body.setPosition(position);
	body.setFillColor(Color::Yellow);
	body.setSize(size);
}

void Ball::update(RenderWindow& window, float deltaTime)
{
	MoveBall(deltaTime);

	//ResetBallPos(window, deltaTime);
}

void Ball::render(RenderWindow& window, float deltaTime)
{
	window.draw(body);
}

void Ball::move(const Vector2f& velocity)
{
	GameObject::move(velocity);
	// Don't forget to update the Box's shape position to match the new position
	
	body.setPosition(position);
	body.setSize(size);

	
}

void Ball::setPosition(const Vector2f& position)
{
	GameObject::setPosition(position);
	body.setPosition(position);
}

void Ball::setSize(const sf::Vector2f& size)
{
	GameObject::setSize(size);
	body.setSize(size);
}



void gm::Ball::setVelocity(const sf::Vector2f& velocity)
{
	this->velocity = velocity;
}

const sf::Vector2f& gm::Ball::getVelocity() const
{
	return velocity;
}

void gm::Ball::setDirection(const int MoveDirection)
{
	this->MoveDirection = MoveDirection;
}

int gm::Ball::getDirection() const
{
	return MoveDirection;
}

// Bounces the ball of the paddle based on which side of the paddle the ball hits
void Ball::Bounce(const sf::Vector2f& BallPos, const sf::Vector2f& PaddlePos,const sf::Vector2f& PaddleSize, int SpeedIncrease)
{
	
	//ball collides with left side paddle
	if (BallPos.x < PaddlePos.x + PaddleSize.y)
	{	

		setVelocity(Vector2f(reflectionDir.x, MoveDirection));
	}
	else
	{
		//ball collides with middle side paddle

		setVelocity(Vector2f(rebound, MoveDirection));
		//printf("Center");

	}

	//ball collides with right side of the paddle
	if (BallPos.x >= PaddlePos.x + (PaddleSize.x)/2 && BallPos.y >= PaddlePos.x + (PaddleSize.y) / 2)
	{
		setVelocity(Vector2f(reflectionDir.y, MoveDirection));
		

	}

	/*cout<< " Paddle Center X: " << PaddlePos.x + (PaddleSize.x) / 2 << endl;
	cout<< " Paddle Center Y: " << PaddlePos.x + (PaddleSize.y) / 2 << endl;

	cout << " Ball Pos X: " << BallPos.x << endl;
	cout << " Ball Pos Y: " << BallPos.y << endl;*/


	BallMovementSpeed += SpeedIncrease;

	


	

}


//when the ball goes off the screen then after 2 sec reset the ball to the original position and radomize direction
//void Ball::ResetBallPos(sf::RenderWindow& window, float deltaTime, bool IsClicked)
//{
//	/*IsClicked = false;
//	cout << IsClicked << endl;*/
//
//	if ( getPosition().y > window.getSize().x - getSize().x)
//	{
//
//		
//		ResetTimer += deltaTime;
//
//		
//		
//	}
//
//	if (ResetTimer >= 2)
//	{
//		
//		//MoveDirection = 1;
//
//		BallMovementSpeed = 300;
//
//		printf("Called Reset");
//
//		//setPosition(Vector2f(paddle->getPosition().x + paddle->getSize().x / 2 + 10, paddle->getPosition().y - paddle->getSize().y / 2 - 5));
//		//setPosition(Vector2f(300,0));
//
//		IsClicked = false;
//
//		/*cout << "Ball POS X: " << paddle->getPosition().x + paddle->getSize().x / 2 + 10 << endl;
//		cout << "Ball POS Y: " << paddle->getPosition().y - paddle->getSize().y / 2 - 5 << endl;*/
//
//		ResetTimer = 0;
//		
//		
//	}
//
//	
//}

// moves the ball on update
void Ball::MoveBall(float deltaTime)
{

	move(Vector2f(getVelocity().x* BallMovementSpeed* deltaTime, getVelocity().y * BallMovementSpeed * deltaTime));

}


