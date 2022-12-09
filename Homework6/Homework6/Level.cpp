#include "Level.h"
#include <iostream>

using namespace gm;
using namespace sf;
using namespace std;


Level::Level(Ball* ball, SoundManager* soundManager, UI* uiManager, int level)
{
	// Initializing ball, soundmanager and uiManager references
	this->ball = ball;
	this->soundManager = soundManager;
	this->uiManager = uiManager;

	uiManager->LevelCompletedtext.setString("");
	isLevelCompleted = false;

	if (level == 4)
	{
		level = 1;
	}

	
	if (level == 1)
	{

		BrickPos[0][1] = 30;
		BrickPos[2][2] = 50;
		BrickPos[3][3] = 150;
		BrickPos[4][4] = 200;
		BrickPos[5][5] = 250;
		BrickPos[6][6] = 300;
		BrickPos[7][7] = 350;
		BrickPos[8][8] = 230;
		BrickPos[9][9] = 400;

	}
	
	if (level == 2)
	{
		BrickPos[1][1] = 60;
		BrickPos[2][2] = 100;
		BrickPos[3][3] = 150;
		BrickPos[4][4] = 200;
		BrickPos[5][5] = 250;
		BrickPos[6][6] = 300;
		BrickPos[7][7] = 350;
		BrickPos[8][8] = 230;
		BrickPos[9][9] = 30;
	}

	if (level == 3)
	{
		BrickPos[1][1] = 150;
		BrickPos[2][2] = 100;
		BrickPos[3][3] = 180;
		BrickPos[4][4] = 200;
		BrickPos[5][5] = 280;
		BrickPos[6][6] = 300;
		BrickPos[7][7] = 350;
		BrickPos[8][8] = 230;
		BrickPos[9][9] = 450;
	}
	
	
	
	
	
	//for (int row = 1; row < brickHeight; row++)
	//{
	//	for (int col = 1; col < brickWidth; col++)
	//	{
	//		
	//		BrickPos[row][col] = { 490};
	//		//BrickPos[0][col] = { 29};
	//		

	//		cout << "Element at x[" << row
	//			<< "][" << col << "]: ";
	//		cout << BrickPos[row][col] << endl;
	//	}
	//	
	//}

	for (int i = 0; i < 5; i++)
	{
		
		bricks.push_back(std::make_unique<Brick>(Vector2f(BrickPos[i][i], BrickPos[i][i]), Vector2f(100, 30), &normal_brick));	

	}
	for (int i = 5; i < 10; i++)
	{
		bricks.push_back(std::make_unique<Brick>(Vector2f(BrickPos[i][i], BrickPos[i][i]), Vector2f(100, 30), &strong_brick));
	}

	
	SetCurrentLevel(level);

	
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
				bricks.erase(bricks.begin() + i);
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
		isLevelCompleted = true;

	}
	

}

void Level::render(RenderWindow& window, float deltaTime)
{
	for (int i = 0; i < bricks.size(); i++)
	{
		bricks[i]->render(window, deltaTime);
	}
}

void Level::SetCurrentLevel(const int currentLevel)
{
	this->currentLevel = currentLevel;
}

const int Level::GetCurrentLevel() const
{
	return currentLevel;
}

void Level::Reset()
{

}
