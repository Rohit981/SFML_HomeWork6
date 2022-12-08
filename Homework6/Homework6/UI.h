#ifndef UI_H
#define UI_H

#include "Ball.h"
namespace gm
{
	class UI
	{
	public:
		UI(Ball* ball);
		~UI();

		void Update(sf::RenderWindow& window, float deltaTime);
		void render(sf::RenderWindow& window, float deltaTime);

		void SetLive(const int PlayerLive);
		const int GetPlayerLive() const;

		void SetScore(const int PlayerScore);
		const int GetScore() const;

	private:

		int PlayerLive = 3;
		int PlayerScore = 0;

		float timer = 0;
		

		sf::Font font;
		sf::Text PlayerLivestext;
		sf::Text Playerscoretext;
		sf::Text GameOvertext;

		

		Ball* ball;
	};

}

#endif // !UI_H

