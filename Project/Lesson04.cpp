#include "LESSON04.h"

using namespace Engine;

Lesson04::Lesson04(Setting* setting) :Game(setting)
{

}

Engine::Lesson04::~Lesson04()
{
	delete texture;
	delete sprite;
}

void Engine::Lesson04::Init()
{
	texture = new Texture("serigala.png");
	sprite = new Sprite(texture, defaultSpriteShader, defaultQuad);
	sprite->SetNumXFrames(2);
	sprite->SetNumYFrames(4);
	sprite->AddAnimation("idle", 0, 4);
	sprite->AddAnimation("walk", 2, 8);
	sprite->PlayAnim("walk");
	sprite->SetScale(5);
	sprite->SetAnimationDuration(100);
	sprite->SetSize(50, 50);
	//sprite->SetRotation(90);

	SetBackgroundColor(244, 91, 176);
}

void Engine::Lesson04::Update()
{
	sprite->Update(GetGameTime());

	float x = sprite->GetPosition().x;
	float y = sprite->GetPosition().y;
	if (collRight == false) {
		float velocity = 0.05f;
		x += velocity * GetGameTime();
		sprite->SetPosition(x, y);

		if (x >= 900) {
			collRight = true;
		}
	}
	else if (collRight == true) {
		float velocity = -0.05f;
		x += velocity * GetGameTime();
		sprite->SetPosition(x, y);
		sprite->SetFlipHorizontal(true);
		if (x <= 0) {
			collRight = false;
			sprite->SetFlipHorizontal(false);
		}
	}
	
	////s = v * t;
	//x += velocity * GetGameTime();
	//sprite->SetPosition(x, y);
	//sprite->GetRotatedPoint(x, y);
}

void Engine::Lesson04::Render()
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
//	Game* game = new Lesson04(setting);
//	game->Run();
//	delete setting;
//	delete game;
//
//	return 0;
//
//}