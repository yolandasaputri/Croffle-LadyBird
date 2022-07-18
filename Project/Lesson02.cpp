#include "LESSON02.h"

using namespace Engine;

Lesson02::Lesson02(Setting* setting) :Game(setting)
{

}

Engine::Lesson02::~Lesson02()
{
}

void Engine::Lesson02::Init()
{
	//Bird
	birdTexture = new Texture("bird.png");
	birdSprite = new Sprite(birdTexture, defaultSpriteShader, defaultQuad);
	birdSprite->SetNumXFrames(5);
	birdSprite->SetNumYFrames(3);
	birdSprite->AddAnimation("fly", 0, 13);
	birdSprite->PlayAnim("fly");
	birdSprite->SetAnimationDuration(200);
	birdSprite->SetScale(0.5);
	birdSprite->SetPosition(90, 250);

	//Pergerakan Bird
	inputManager->AddInputMapping("Move Up", SDLK_UP);
	inputManager->AddInputMapping("Move Down", SDLK_DOWN);
	inputManager->AddInputMapping("Move Left", SDLK_LEFT);
	inputManager->AddInputMapping("Move Right", SDLK_RIGHT);

	//Plane
	planeTexture = new Texture("pesawat.png");
	planeSprite = new Sprite(planeTexture, defaultSpriteShader, defaultQuad);
	planeSprite->SetNumXFrames(4);
	planeSprite->SetNumYFrames(1);
	planeSprite->AddAnimation("fly", 0, 3);
	planeSprite->PlayAnim("fly");
	planeSprite->SetAnimationDuration(200);
	planeSprite->SetScale(1.3);
	planeSprite->SetPosition(900, 300);

	//INIT BACKGROUND
	backgroundTexture = new Texture("background.png");
	backgroundSprite = new Sprite(backgroundTexture, defaultSpriteShader, defaultQuad);
	backgroundSprite->SetPosition((0), (0));

}

void Engine::Lesson02::Update()
{
	//Bird
	birdSprite->Update(GetGameTime());

	float x = birdSprite->GetPosition().x;
	float y = birdSprite->GetPosition().y;
	float velocity = 0.2f;

	birdSprite->PlayAnim("fly");

	if (inputManager->IsKeyPressed("Move Up")) {
		y += velocity * GetGameTime();
		birdSprite->PlayAnim("fly");
	}
	if (inputManager->IsKeyPressed("Move Down")) {
		y -= velocity * GetGameTime();
		birdSprite->PlayAnim("fly");
	}
	if (inputManager->IsKeyPressed("Move Right")) {
		x += velocity * GetGameTime();
		birdSprite->PlayAnim("fly");
	}
	if (inputManager->IsKeyPressed("Move Left")) {
		x -= velocity * GetGameTime();
		birdSprite->PlayAnim("fly");
	}
	birdSprite->SetPosition(x, y);

	//Plane
	float xplane = planeSprite->GetPosition().x;
	float yplane = planeSprite->GetPosition().y;
	float speed = -0.3f;
	if (xplane >= -50) {
		xplane += speed * GetGameTime();
		planeSprite->SetPosition(xplane, yplane);
		count++;
	}
	else {
		planeSprite->SetPosition((rand() % 500) + 1200, rand() %500);
	}
}

void Engine::Lesson02::Render()
{
	birdSprite->Draw();
	backgroundSprite->Draw();
	planeSprite->Draw();
}

//int main(int argc, char** argv) {
//
//	Setting* setting = new Setting();
//	setting->windowTitle = "Project Example";
//	setting->screenWidth = 1024;
//	setting->screenHeight = 600;
//	setting->windowFlag = WindowFlag::WINDOWED;
//	Game* game = new Lesson02(setting);
//	game->Run();
//	delete setting;
//	delete game;
//
//	return 0;
//
//}