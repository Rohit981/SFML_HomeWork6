#ifndef BALL_H
#define BALL_H

#include "GameObject.h"
#include "Paddle.h"

namespace gm {
class Ball :public GameObject
{
private:
	sf::Vector2f velocity = sf::Vector2f(0,1);
	int BallMovementSpeed = 300;
	int MoveDirection = 1.f;
	//float ResetTimer = 0;
	bool IsMoving = true;

	const int MaxMoveDirection = 2;
	const int MinMoveDirection = -2;
	
	


protected:
	sf::RectangleShape body;

public:
	Ball(const sf::Vector2f& position, const sf::Vector2f& size);
	// Our update interface, NOTE it is a pure virtual function
	virtual void update(sf::RenderWindow& window, float deltaTime) override;

	// Our render interface, NOTE it is a pure virtual function
	virtual void render(sf::RenderWindow& window, float deltaTime) override;

	// Move the box from its current position to a new one with a specified velocity
	virtual void move(const sf::Vector2f& velocity) override;

	virtual void setPosition(const sf::Vector2f& position) override;
	virtual void setSize(const sf::Vector2f& size)override;

	virtual void setVelocity(const sf::Vector2f& velocity);
	virtual const sf::Vector2f& getVelocity() const;

	virtual void setDirection(const int MoveDirection);
	virtual int getDirection() const;

	void Bounce( const sf::Vector2f& BallPos, const sf::Vector2f& PaddlePos, const sf::Vector2f& PaddleSize, int SpeedIncrease);

	//void ResetBallPos( sf::RenderWindow& window, float deltaTime, bool IsClicked);

	void MoveBall(float deltaTime);

	float ResetTimer = 0;


	int rebound = 0;

	sf::Vector2f reflectionDir = sf::Vector2f(-1, 1);


};

}
#endif // !BALL_H


