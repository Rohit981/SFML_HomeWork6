#include "SoundManager.h"

using namespace gm;

SoundManager::SoundManager()
{
	if (!PaddlesfxBuffer.loadFromFile("Audio/paddle_bounce.wav"))
	{
		throw("Could not load paddle bounce SFX");
	}

	paddleBounceSFX.setBuffer(PaddlesfxBuffer);

	if (!WallsfxBuffer.loadFromFile("Audio/wall_bounce.wav"))
	{
		throw("Could not load wall bounce SFX");
	}
	wallBounceSFX.setBuffer(WallsfxBuffer);
	
	if (!LoseLivesfxBuffer.loadFromFile("Audio/score.wav"))
	{
		throw("Could not load score SFX");
	}

	LoseLiveSFX.setBuffer(LoseLivesfxBuffer);

	if (!GameOverBuffer.loadFromFile("Audio/gameover.wav"))
	{
		throw("Could not Game Over Music");

	}
	GameOverSFX.setBuffer(GameOverBuffer);

	if (!BreakBuffer.loadFromFile("Audio/break.wav"))
	{
		throw("Could not Game Over Music");

	}
	BreakSFX.setBuffer(BreakBuffer);

	if (!ShatterBuffer.loadFromFile("Audio/shatter.wav"))
	{
		throw("Could not Game Over Music");

	}
	ShatterSFX.setBuffer(ShatterBuffer);

	if (!LevelCompleteBuffer.loadFromFile("Audio/level_complete.wav"))
	{
		throw("Could not Game Over Music");

	}
	LevelCompleteSFX.setBuffer(LevelCompleteBuffer);


}

SoundManager::~SoundManager()
{

}

void SoundManager::PlayPaddleSFX()
{
	paddleBounceSFX.play();
}

void SoundManager::PlayWallSFX()
{
	

	wallBounceSFX.play();
}

void SoundManager::PlayScoreSFX()
{
	if (LoseLiveSFX.getStatus() != LoseLiveSFX.Playing)
	{
		LoseLiveSFX.play();

	}
	

}

void SoundManager::PlayGameOverSFX()
{
	if (GameOverSFX.getStatus() != GameOverSFX.Playing)
	{
		GameOverSFX.play();
		
		stopSound += 0.1;

	}
	
	if(stopSound > 0.1f)
	GameOverSFX.stop();

}

void SoundManager::PlayBreakSFX()
{
	BreakSFX.play();
}

void SoundManager::PlayShatterSFX()
{
	ShatterSFX.play();

}

void SoundManager::PlayLevelCompleteSFX()
{
	if (LevelCompleteSFX.getStatus() != LevelCompleteSFX.Playing)
	{
		LevelCompleteSFX.play();

		stopSound += 0.1f;

	}

	if (stopSound > 0.1f)
		LevelCompleteSFX.stop();

}


