#include "GameScene.h"
#include "Win.h"

Win::Win() {
	auto background = gcnew Sprite(L"pic/YouWin.png");
	background->setPos(Window::getSize() / 2);
	background->setScale(1.0f, 1.0f);
	this->addChild(background);
}
void Win::onUpdate() {
	if (Input::isDown(KeyCode::Enter)) {
		SceneManager::enter(gcnew GameScene());
	}
}