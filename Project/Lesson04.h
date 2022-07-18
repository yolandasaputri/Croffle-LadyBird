#ifndef LESSON04_H
#define LESSON04_H

#include "Game.h"
#include "Setting.h"
#include "Texture.h"
#include "Sprite.h"

namespace Engine {
	class Lesson04 :public Engine::Game
	{
	public:
		Lesson04(Setting* setting);
		~Lesson04();
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
