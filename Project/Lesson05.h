#ifndef LESSON05_H
#define LESSON05_H

#include "Game.h"
#include "Setting.h"
#include "Texture.h"
#include "Sprite.h"

namespace Engine {
	class Lesson05 :public Engine::Game
	{
	public:
		Lesson05(Setting* setting);
		~Lesson05();
		virtual void Init();
		virtual void Update();
		virtual void Render();

	private:
		bool collRight = false;
		bool coolLeft = false;
		Engine::Texture* texture;
		Engine::Sprite* sprite;
	};

}
# endif
