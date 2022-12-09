#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "Paddle.h"
namespace gm {
	class PlayerController
{
public:
	PlayerController(Paddle* playerPaddle);
	~PlayerController();

	void HandleInput(sf::RenderWindow& window);

	bool IsLeftClicked = false;


private:
	Paddle* playerPaddle;
};

}

#endif // !PLAYER_CONTROLLER_H


