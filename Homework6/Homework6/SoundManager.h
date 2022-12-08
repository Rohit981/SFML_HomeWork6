#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H


#include <SFML/Audio.hpp>

namespace gm
{
	class SoundManager
	{
	public:
		SoundManager();
		~SoundManager();

		void PlayPaddleSFX();
		void PlayWallSFX();
		void PlayScoreSFX();
		void PlayGameOverSFX();
		void PlayBreakSFX();
		void PlayShatterSFX();
		void PlayLevelCompleteSFX();

	private:
		//Paddle Bounce SFX
		sf::SoundBuffer PaddlesfxBuffer;
		sf::Sound paddleBounceSFX;

		//Wall Bounce SFX
		sf::SoundBuffer WallsfxBuffer;
		sf::Sound wallBounceSFX;

		//Lose Live SFX
		sf::SoundBuffer LoseLivesfxBuffer;
		sf::Sound LoseLiveSFX;

		//Game Over SFX
		sf::SoundBuffer GameOverBuffer;
		sf::Sound GameOverSFX;

		//Break SFX
		sf::SoundBuffer BreakBuffer;
		sf::Sound BreakSFX;

		//Shatter SFX
		sf::SoundBuffer ShatterBuffer;
		sf::Sound ShatterSFX;

		//Level Complete SFX
		sf::SoundBuffer LevelCompleteBuffer;
		sf::Sound LevelCompleteSFX;


		float stopSound = 0;
		

	};

}

#endif // !SOUND_MANAGER_H


