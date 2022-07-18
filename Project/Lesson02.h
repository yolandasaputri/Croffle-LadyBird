#ifndef LESSON02_H
#define LESSON02_H

#include "Game.h"
#include "Setting.h"
#include "Texture.h"
#include "Sprite.h"

namespace Engine {
	class Lesson02 :public Engine::Game
	{
	public:
		Lesson02(Setting* setting);
		~Lesson02();
		virtual void Init();
		virtual void Update();
		virtual void Render();

	private:
	Engine::Texture * birdTexture;
	Engine::Sprite * birdSprite;
	Engine::Texture* planeTexture;
	Engine::Sprite* planeSprite;
	float count;

	//Texture* birdTexture = NULL;
	//Texture* planeTexture = NULL;
	Texture* backgroundTexture = NULL;
	
	Sprite* backgroundSprite = NULL;
	};

}
# endif
