#ifndef LESSON06_H
#define LESSON06_H

#include "Game.h"
#include "Setting.h"
#include "Texture.h"
#include "Sprite.h"
#include "Music.h"
#include "Sound.h"
#include "Text.h"

namespace Engine {
	class Lesson06 :public Engine::Game
	{
	public:
		Lesson06(Setting* setting);
		~Lesson06();
		virtual void Init();
		virtual void Update();
		virtual void Render();

	private:
		Engine::Texture* birdTexture;
		Engine::Sprite* birdSprite;
		Engine::Sprite* planeSprite[4];
		Engine::Texture* planeTexture;
		float count;

		Texture* backgroundTexture = NULL;
		Sprite* backgroudSprite = NULL;
		Texture* logoTexture = NULL;
		Sprite* logoSprite = NULL;
		Music* music = NULL;

		Texture* buttonTexture = NULL;
		Sprite* playSprite = NULL;
		Sprite* exitSprite = NULL;
		Text* scoreText = NULL;
		Text* endText = NULL;
		bool isStartSelected = true;
		bool isPaused = true;
		int score;
		float scoreTimer;
		bool gameOver = false;
		bool gameOn = false;
		bool menu = false;
		bool isPlay = true;
	};
}
# endif