#ifndef LEVEL_H
#define LEVEL_H

#include "Brick.h"
#include "Ball.h"
#include "SoundManager.h"
#include "UI.h"
#include <vector>

namespace gm
{
	class Level
	{
		BrickType normal_brick = {
				1,
				sf::Color::Cyan,
				20
				//normal_brick_tex
		};

		BrickType strong_brick = {
				2,
				sf::Color::Red,
				30
				//normal_brick_tex
		};

	public:
		Level(Ball* ball, SoundManager* soundManager, UI* uiManager, int level);
		~Level();

		virtual void update(sf::RenderWindow& window, float deltaTime);
		virtual void render(sf::RenderWindow& window, float deltaTime);

		void Reset();

		void SetCurrentLevel(const int currentLevel);
			
		const int GetCurrentLevel() const;

		bool isLevelCompleted = false;
		

	private:
		const int brickHeight = 10;
		const int brickWidth = 10;

		int BrickPos[10][10];
		std::vector<std::unique_ptr<Brick>> bricks;
		int currentLevel = 1;
		

		SoundManager* soundManager;
		UI* uiManager;

		Ball* ball;

		

		

	};

}

#endif // !LEVEL_H

