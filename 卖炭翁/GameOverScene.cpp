#include "GameScene.h"
#include "GameOverScene.h"

GameOverScene::GameOverScene() {
	auto background = gcnew Sprite(L"pic/gameover.png");
	background->setPos(Window::getSize() / 2);
	background->setScale(1.0f, 1.0f);
	this->addChild(background);
}
void GameOverScene::onUpdate() {
	if (Input::isDown(KeyCode::Enter)) {
		SceneManager::enter(gcnew GameScene());
	}
}