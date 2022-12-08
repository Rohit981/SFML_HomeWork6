#include "UI.h"

using namespace gm;
using namespace sf;
using namespace std;

UI::UI(Ball* ball)
{
	if (!font.loadFromFile("Fonts/arial.ttf"))
	{
		throw("Could not found the font");
	}

	PlayerLivestext.setFont(font);
	PlayerLivestext.setCharacterSize(34);
	PlayerLivestext.setFillColor(Color::Green);
	PlayerLivestext.setStyle(Text::Bold);
	PlayerLivestext.setPosition(Vector2f(40, 450));
	PlayerLivestext.setString("LIVES:  "+ to_string(GetPlayerLive()));


	Playerscoretext.setFont(font);
	Playerscoretext.setCharacterSize(44);
	Playerscoretext.setFillColor(Color::Red);
	Playerscoretext.setStyle(Text::Bold);
	Playerscoretext.setPosition(Vector2f(550, 450));
	Playerscoretext.setString(to_string(GetScore()));

	GameOvertext.setFont(font);
	GameOvertext.setCharacterSize(60);
	//scoretext.setColor(Color::Green);
	GameOvertext.setStyle(Text::Bold);
	GameOvertext.setPosition(Vector2f(130, 300));
	

	this->ball = ball;
}

UI::~UI()
{

}

// updates the sprite for player1 and player2 scores 
void UI::Update(sf::RenderWindow& window, float deltaTime)
{
	

	if (ball->getPosition().y > window.getSize().x - ball->getSize().x && GetPlayerLive() != 0)
	{
		PlayerLivestext.setString("LIVES:  " + to_string(GetPlayerLive() - 1));

		timer += deltaTime;

	}

	if (timer >= 1.5f)
	{
		SetLive(GetPlayerLive() - 1);

		timer = 0;
	}


	if (GetPlayerLive() <= 0)
	{
		GameOvertext.setString("GAME OVER");
		
	}

}

void gm::UI::render(sf::RenderWindow& window, float deltaTime)
{

	window.draw(PlayerLivestext);
	window.draw(Playerscoretext);
	window.draw(GameOvertext);

	
}


void gm::UI::SetLive(const int PlayerLive)
{
	this->PlayerLive = PlayerLive;
}

const int gm::UI::GetPlayerLive() const
{
	return PlayerLive;
}

void UI::SetScore(const int PlayerScore)
{
	this->PlayerScore = PlayerScore;
}

const int UI::GetScore() const
{
	return PlayerScore;
}


