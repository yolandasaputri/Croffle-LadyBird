#include "LESSON05.h"

using namespace Engine;

Lesson05::Lesson05(Setting* setting) :Game(setting)
{

}

Engine::Lesson05::~Lesson05()
{
	delete texture;
	delete sprite;
}

void Engine::Lesson05::Init()
{
	texture = new Texture("monster.png");
	sprite = new Sprite(texture, defaultSpriteShader, defaultQuad);
	sprite->SetNumXFrames(6);
	sprite->SetNumYFrames(2);
	sprite->AddAnimation("idle", 0, 3);
	sprite->AddAnimation("walk", 6, 11);
	sprite->PlayAnim("idle");
	sprite->SetScale(5);
	sprite->SetAnimationDuration(90);
	//sprite->SetSize(50, 50);
	//sprite->SetRotation(90);

	SetBackgroundColor(244, 91, 176);

	inputManager->AddInputMapping("walk-left", SDLK_LEFT);
	inputManager->AddInputMapping("walk-left", SDL_BUTTON_LEFT);
	inputManager->AddInputMapping("walk-left", SDL_CONTROLLER_BUTTON_DPAD_LEFT);
	inputManager->AddInputMapping("walk-left", SDL_CONTROLLER_AXIS_LEFTX);
	inputManager->AddInputMapping("walk-right", SDLK_RIGHT);
	inputManager->AddInputMapping("walk-right", SDL_BUTTON_RIGHT);
	inputManager->AddInputMapping("walk-right", SDL_CONTROLLER_BUTTON_DPAD_RIGHT);
}

void Engine::Lesson05::Update()
{
	sprite->Update(GetGameTime());

	float x = sprite->GetPosition().x;
	float y = sprite->GetPosition().y;
	float velocity = 0.07f;

	sprite->PlayAnim("idle");

	if (inputManager->IsKeyPressed("walk-right")) {
		x += velocity * GetGameTime();
		sprite->SetFlipHorizontal(false);
		sprite->PlayAnim("walk");
	}
	if (inputManager->IsKeyPressed("walk-left")) {
		x -= velocity * GetGameTime();
		sprite->SetFlipHorizontal(true);
		sprite->PlayAnim("walk");
	}

	////s = v * t;
	//x += velocity * GetGameTime();
	sprite->SetPosition(x, y);
	//sprite->GetRotatedPoint(x, y);
}

void Engine::Lesson05::Render()
{
	sprite->Draw();
}

//int main(int argc, char** argv) {
//
//	Setting* setting = new Setting();
//	setting->windowTitle = "Project Example";
//	setting->screenWidth = 1024;
//	setting->screenHeight = 600;
//	setting->windowFlag = WindowFlag::WINDOWED;
//	Game* game = new Lesson05(setting);
//	game->Run();
//	delete setting;
//	delete game;
//
//	return 0;
//
//}