#include "Lesson06.h"

using namespace Engine;


Lesson06::Lesson06(Setting* setting) :Game(setting)
{

}

Engine::Lesson06::~Lesson06()
{
	delete birdTexture;
	delete birdSprite;
}

void Engine::Lesson06::Init()
{
	// Playing music
	music = new Music("bensound-funkyelement.ogg");
	music->SetVolume(30);
	music->Play(true);

	//button
	buttonTexture = new Texture("button.png");
	playSprite = new Sprite(buttonTexture, defaultSpriteShader, defaultQuad);
	playSprite->SetPosition(200, 400);
	playSprite->SetNumXFrames(2);
	playSprite->SetNumYFrames(2);
	playSprite->AddAnimation("play-normal", 2, 2);
	playSprite->AddAnimation("play-press", 2, 3);
	playSprite->PlayAnim("play-press");
	playSprite->SetAnimationDuration(500);

	exitSprite = new Sprite(buttonTexture, defaultSpriteShader, defaultQuad);
	exitSprite->SetPosition(200, 200);
	exitSprite->SetNumXFrames(2);
	exitSprite->SetNumYFrames(2);
	exitSprite->AddAnimation("exit-normal", 0, 0);
	exitSprite->AddAnimation("exit-press", 0, 1);
	exitSprite->PlayAnim("exit-normal");
	exitSprite->SetAnimationDuration(500);

	//Logo
	logoTexture = new Texture("logo.png");
	logoSprite = new Sprite(logoTexture, defaultSpriteShader, defaultQuad);
	logoSprite->SetPosition(420, 500);
	logoSprite->SetNumXFrames(1);
	logoSprite->SetNumYFrames(1);
	logoSprite->SetScale(0.5);

	//INIT BACKGROUND
	backgroundTexture = new Texture("bg.png");
	backgroudSprite = new Sprite(backgroundTexture, defaultSpriteShader, defaultQuad);
	backgroudSprite->SetPosition(0, 0);
	backgroudSprite->SetNumXFrames(1);
	backgroudSprite->SetNumYFrames(1);

	//Input Bird
	birdTexture = new Texture("bird.png");
	birdSprite = new Sprite(birdTexture, defaultSpriteShader, defaultQuad);
	birdSprite->SetNumXFrames(5);
	birdSprite->SetNumYFrames(3);
	birdSprite->AddAnimation("fly", 0, 13);
	birdSprite->PlayAnim("fly");
	birdSprite->SetAnimationDuration(200);
	birdSprite->SetScale(0.5);
	birdSprite->SetPosition(90, 250);

	inputManager->AddInputMapping("move-up", SDLK_UP);
	inputManager->AddInputMapping("move-down", SDLK_DOWN);
	inputManager->AddInputMapping("move-right", SDLK_RIGHT);
	inputManager->AddInputMapping("move-left", SDLK_LEFT);
	inputManager->AddInputMapping("enter", SDLK_RETURN);
	inputManager->AddInputMapping("retry", SDLK_SPACE);


	//Input Plane
	planeTexture = new Texture("pesawat.png");
	for (int i = 0; i < 4; i++) {
		planeSprite[i] = new Sprite(planeTexture, defaultSpriteShader, defaultQuad);
		planeSprite[i]->SetNumXFrames(4);
		planeSprite[i]->SetNumYFrames(1);
		planeSprite[i]->AddAnimation("fly", 0, 3);
		planeSprite[i]->PlayAnim("fly");
		planeSprite[i]->SetAnimationDuration(200);
		planeSprite[i]->SetScale(1.3);
		planeSprite[i]->SetPosition(900, 300);
	}
	//Text Score
	scoreText = new Text("lucon.ttf", 20, defaultTextShader);
	scoreText->SetPosition(850, 550);
	scoreText->SetColor(0, 0, 0);

	endText = new Text("lucon.ttf", 80, defaultTextShader);
	endText->SetPosition(312, 280);
	endText->SetColor(0, 0, 0);
}

void Engine::Lesson06::Update()
{
	backgroudSprite->Update(GetGameTime());
	if (isPaused) {
		playSprite->Update(GetGameTime());
		exitSprite->Update(GetGameTime());
		if (isStartSelected) {
			playSprite->PlayAnim("play-press");
			exitSprite->PlayAnim("exit-normal");
			score = 0;
		}
		else {
			playSprite->PlayAnim("play-normal");
			exitSprite->PlayAnim("exit-press");
		}

		if (inputManager->IsKeyPressed("move-up")) {
			isStartSelected = true;

		}

		if (inputManager->IsKeyPressed("move-down")) {
			isStartSelected = false;

		}
		if (inputManager->IsKeyPressed("enter")) {
			if (isStartSelected) {
				isPaused = false;
				gameOn = true;
				gameOver = false;
				playSprite->SetScale(0.0f);
				exitSprite->SetScale(0.0f);
			}
			else {
				state = State::EXIT;
				return;
			}

		}
	}
	else if (gameOver) {
		endText->SetText("Game Over");

		if (inputManager->IsKeyReleased("retry")) {
			isPaused = true;
			gameOver = false;
			gameOn = false;
			cout << "hai" << endl;
		}

		for (int i = 0; i < 4; i++) {
			planeSprite[i] = new Sprite(planeTexture, defaultSpriteShader, defaultQuad);
			planeSprite[i]->SetNumXFrames(4);
			planeSprite[i]->SetNumYFrames(1);
			planeSprite[i]->AddAnimation("fly", 0, 3);
			planeSprite[i]->PlayAnim("fly");
			planeSprite[i]->SetAnimationDuration(200);
			planeSprite[i]->SetScale(1.3);
			planeSprite[i]->SetPosition(900, 300);
		}

	}
	else if (gameOn)
	{
		//Bird
		birdSprite->Update(GetGameTime());

		float x = birdSprite->GetPosition().x;
		float y = birdSprite->GetPosition().y;
		float velocity = 0.2f;

		birdSprite->PlayAnim("fly");

		if (inputManager->IsKeyPressed("move-up")) {
			y += velocity * GetGameTime();
			birdSprite->PlayAnim("fly");

		}

		if (inputManager->IsKeyPressed("move-down")) {
			y -= velocity * GetGameTime();
			birdSprite->PlayAnim("fly");
		}

		if (inputManager->IsKeyPressed("move-right")) {
			x += velocity * GetGameTime();
			birdSprite->PlayAnim("fly");

		}

		if (inputManager->IsKeyPressed("move-left")) {
			x -= velocity * GetGameTime();
			birdSprite->PlayAnim("fly");
		}
		birdSprite->SetPosition(x, y);

		//Background bergerak
		float xb = backgroudSprite->GetPosition().x;
		float yb = backgroudSprite->GetPosition().y;
		float newX = xb - velocity * GetGameTime() * 0.35f;
		if (newX <= -5000)
			backgroudSprite->SetPosition(0, yb);
		else
			backgroudSprite->SetPosition(newX, yb);
		cout << "xbbbb :" << xb - velocity * GetGameTime() << endl;

		//plane
		for (int i = 0; i < 4; i++) {
			float xplane = planeSprite[i]->GetPosition().x;
			float yplane = planeSprite[i]->GetPosition().y;
			float speed = -0.3f;
			if (xplane >= -50) {
				xplane += speed * GetGameTime();
				planeSprite[i]->SetPosition(xplane, yplane);
				count++;
			}
			else {
				planeSprite[i]->SetPosition((rand() % 500) + 1200, rand() % 350 + 150);
			}
		}
		//burung menabrak pesawat
		for (int i = 0; i < 4; i++) {
			if (planeSprite[i]->GetBoundingBox()->CollideWith(birdSprite->GetBoundingBox())) {
				gameOver = true;
				isPaused = false;
				gameOn = false;

			}
		}

		//Score
		if (scoreTimer >= 1000) {
			score += 10;
			scoreTimer = 0;
		}
		scoreTimer += GetGameTime();
		scoreText->SetText("Score : " + to_string(score));
	}
	else {
		isPaused = true;
	}

}

void Engine::Lesson06::Render()
{
	if (isPaused == true) {
		backgroudSprite->Draw();

		playSprite->Draw();

		exitSprite->Draw();

		logoSprite->Draw();
	}
	else if (gameOver == true) {
		backgroudSprite->Draw();
		playSprite->Draw();

		exitSprite->Draw();
		endText->Draw();
	}
	else if (gameOn == true) {
		backgroudSprite->Draw();

		playSprite->Draw();

		exitSprite->Draw();

		logoSprite->Draw();

		for (int i = 0; i < 4; i++) {
			planeSprite[i]->Draw();
		}
		birdSprite->Draw();

		scoreText->Draw();
	}
	else {
		isPaused = true;
	}

}

int main(int argc, char** argv) {

	Setting* setting = new Setting();
	setting->windowTitle = "Project Example";
	setting->screenWidth = 1024;
	setting->screenHeight = 600;
	setting->windowFlag = WindowFlag::WINDOWED;
	Game* game = new Lesson06(setting);
	game->Run();
	delete setting;
	delete game;

	return 0;

}