#include "LESSON01.h"

using namespace Engine;

Lesson01::Lesson01(Setting* setting) :Game(setting)
{

}

Engine::Lesson01::~Lesson01()
{
}

void Engine::Lesson01::Init()
{
}

void Engine::Lesson01::Update()
{
	if (color_duration >= 300) {
		if (r >= 255)
			isLimit = true;
		if (r <= 0)
			isLimit = false;
		if (isLimit) {
			r -= 25;
		}
		else
			r += 25;
		SetBackgroundColor(r + 25, g, b);
		color_duration = 0;
	}
	color_duration += GetGameTime();
}

void Engine::Lesson01::Render()
{
}

/*int main(int argc, char** argv) {

	Setting* setting = new Setting();
	setting->windowTitle = "Project Example";
	setting->screenWidth = 1024;
	setting->screenHeight = 600;
	setting->windowFlag = WindowFlag::WINDOWED;
	Game* game = new Lesson01(setting);
	game->Run();
	delete setting;
	delete game;

	return 0;

}*/