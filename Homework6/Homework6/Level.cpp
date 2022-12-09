#include "Level.h"

using namespace gm;
using namespace sf;

Level::Level(Ball* ball, SoundManager* soundManager, UI* uiManager)
{
	// Initializing ball, soundmanager and uiManager references
	this->ball = ball;
	this->soundManager = soundManager;
	this->uiManager = uiManager;

	BrickPos[0][0] = 490;
	
	bricks.push_back(std::make_unique<Brick>(Vector2f(290, 350), Vector2f(100, 30), &normal_brick));
	bricks.push_back(std::make_unique<Brick>(Vector2f(490, 350), Vector2f(100, 30), &strong_brick));
	
	for (int row = 0; row < brickHeight; row++)
	{
		for (int col = 0; col < brickWidth; col++)
		{
			
			

		}
		
	}

	
}

Level::~Level()
{
}

void Level::update(RenderWindow& window, float deltaTime)
{
	
	for (int i = 0; i < bricks.size(); i++)
	{

		if (bricks[i]->collide(FloatRect(ball->getPosition().x, ball->getPosition().y, ball->getSize().x, ball->getSize().y)))
		{
			ball->reflectionDir = Vector2f(-1, 1);
			ball->rebound = 0;

			ball->setDirection(1);

			ball->Bounce(ball->getPosition(), bricks[i]->getPosition(), bricks[i]->getSize(), 0);

			bricks[i]->SetHealth(bricks[i]->GetHealth() - 1);
			

			if (bricks[i]->GetHealth() <= 0)
			{
				uiManager->SetScore(uiManager->GetScore() + bricks[i]->score);
				soundManager->PlayShatterSFX();
				bricks.erase(bricks.begin() - i);
			}
			else
			{
				soundManager->PlayBreakSFX();

			}

			
			

		}


	}

	if (bricks.empty() == true)
	{
		uiManager->LevelCompletedtext.setString("LEVEL COMPLETED");
		soundManager->PlayLevelCompleteSFX();

	}

}

void Level::render(RenderWindow& window, float deltaTime)
{
	for (int i = 0; i < bricks.size(); i++)
	{
		bricks[i]->render(window, deltaTime);
	}
}

void Level::Reset()
{

}
