#include <cmath>
#include "GameOverScene.h"
#include "Win.h"
#include "GameScene.h"

GameScene::GameScene() {
	auto gameBackGround = gcnew Sprite(L"Pic//GameB.png");
	gameBackGround->setPos(Window::getSize() / 2);
	gameBackGround->setScale(1.0f, 1.0f);
	this->addChild(gameBackGround);
	auto Ground = gcnew Sprite(L"Pic//Ground.png");
	Ground->setPos(Window::getWidth() / 2, Window::getHeight() - 85);
	Ground->setScale(1.0f, 1.0f);
	this->addChild(Ground);
	player = gcnew Player();
	this->addChild(player);
	scoreText = gcnew Text;
	scoreText->setAnchor(0.5f, 0);
	scoreText->setPos(Window::getWidth() - 50, 20);
	scoreText->setText(L"score:0");
	this->addChild(scoreText);
	for (unsigned int i = 0; i < 1; i++) {
		auto snowball = gcnew Snowball();
		Snowballs.push_back(snowball);
		this->addChild(snowball);
	}
	for (unsigned int i = 0; i <= Random::range(1.f, 3.f); i++) {
		auto coal = gcnew Coal();
		coals.push_back(coal);
		this->addChild(coal);
	}
}
void GameScene::onUpdate() {
	if (score >= 100) {
		SceneManager::enter(gcnew Win());
	}
	if (Input::isDown(KeyCode::Left) || Input::isDown(KeyCode::A)) {
		player->move(1);
	}
	if (Input::isDown(KeyCode::Right) || Input::isDown(KeyCode::D)) {
		player->move(2);
	}
	if (Input::isDown(KeyCode::Space)) {
		player->move(3);
	}
	if (Input::isDown(KeyCode::Q)) {
		if (!Swordsl.empty()) {
			auto lasts = Swordsl[Swordsl.size() - 1];
			if (player->getPosX() - lasts->getPosX() >= 20) {
				score -= 10;
				scoreText->setText(L"score:" + std::to_wstring(score));
				auto sword = gcnew Sword();
				sword->setPos(player->getPosX(), player->getPosY());
				Swordsl.push_back(sword);
				this->addChild(sword);
			}
		}
		else {
			score -= 10;
			scoreText->setText(L"score:" + std::to_wstring(score));
			auto sword = gcnew Sword();
			sword->setPos(player->getPosX(), player->getPosY());
			Swordsl.push_back(sword);
			this->addChild(sword);
		}
	}
	if (Input::isDown(KeyCode::E)) {
		if(!Swordsr.empty()) {
			auto lasts = Swordsr[Swordsr.size() - 1];
			if (lasts->getPosX() - player->getPosX() >= 20) {
				score -= 10;
				scoreText->setText(L"score:" + std::to_wstring(score));
				auto sword = gcnew Sword();
				sword->setPos(player->getPosX(), player->getPosY());
				Swordsr.push_back(sword);
				this->addChild(sword);
			}
		}
		else {
			score -= 10;
			scoreText->setText(L"score:" + std::to_wstring(score));
			auto sword = gcnew Sword();
			sword->setPos(player->getPosX(), player->getPosY());
			Swordsr.push_back(sword);
			this->addChild(sword);
		}
	}
	if (Input::isDown(KeyCode::W)) {
		if (!Swordsu.empty()) {
			auto lasts = Swordsu[Swordsu.size() - 1];
			if (player->getPosY() - lasts->getPosY() >= 20) {
				score -= 10;
				scoreText->setText(L"score:" + std::to_wstring(score));
				auto sword = gcnew Sword();
				sword->setPos(player->getPosX(), player->getPosY());
				Swordsu.push_back(sword);
				this->addChild(sword);
			}
		}
		else {
			score -= 10;
			scoreText->setText(L"score:" + std::to_wstring(score));
			auto sword = gcnew Sword();
			sword->setPos(player->getPosX(), player->getPosY());
			Swordsu.push_back(sword);
			this->addChild(sword);
		}
	}
	std::vector<Silk*> del1;
	for (size_t i = 0; i < Silks.size(); i++) {
		auto silk = Silks[i];
		if (player->containsPoint(Point(silk->getPosX(), silk->getPosY())))
		{
			SceneManager::enter(gcnew GameOverScene());
		}
		silk->move();
		if (silk->getPosX() <= 0 || silk->getPosX() >= Window::getWidth()) {
			silk->setVisible(false);
			del1.push_back(silk);
		}
	}
	for (size_t i = 0; i < Snowballs.size(); i++) {
		auto snowball = Snowballs[i];
		if (player->containsPoint(Point(snowball->getPosX(), snowball->getPosY())))
		{
			SceneManager::enter(gcnew GameOverScene());
		}
		snowball->move();
	}
	std::vector<Coal*> del2;
	for (size_t i = 0; i < coals.size(); i++) {
		auto coal = coals[i];
		coal->move();
		if (player->containsPoint(Point(coal->getPosX(), coal->getPosY()))) {
        	score++;
			scoreText->setText(L"score:" + std::to_wstring(score));
			coal->setVisible(false);
			del2.push_back(coal);
		}
		if (coal->getPosY() >= Window::getHeight()) {
			del2.push_back(coal);
		}
	}
	std::vector<Sword*> del3, del4, del5;
	for (size_t i = 0; i < Swordsl.size(); i++) {
		auto sword = Swordsl[i];
		if (exist) {
			if (NPC->containsPoint(Point(sword->getPosX(), sword->getPosY()))) {
				score += 5;
				scoreText->setText(L"score:" + std::to_wstring(score));
				NPC->setVisible(false);
				exist = false;
				for (size_t i = 0; i < Silks.size(); i++) {
					Silks[i]->setVisible(false);
				}
				Silks.clear();
			}
		}
		sword->move(1);
		if (sword->getPosX() <= 0) {
			sword->setVisible(false);
			del3.push_back(sword);
		}
	}
	for (size_t i = 0; i < Swordsr.size(); i++) {
		auto sword = Swordsr[i];
		if (exist) {
			if (NPC->containsPoint(Point(sword->getPosX(), sword->getPosY()))) {
				score += 5;
				scoreText->setText(L"score:" + std::to_wstring(score));
				NPC->setVisible(false);
				exist = false;
				for (size_t i = 0; i < Silks.size(); i++) {
					Silks[i]->setVisible(false);
				}
				Silks.clear();
			}
		}
		sword->move(2);
		if (sword->getPosX() >= Window::getWidth()) {
			sword->setVisible(false);
			del4.push_back(sword);
		}
	}
	for (size_t i = 0; i < Swordsu.size(); i++) {
		auto sword = Swordsu[i];
		if (exist) {
			if (NPC->containsPoint(Point(sword->getPosX(), sword->getPosY()))) {
				score += 5;
				scoreText->setText(L"score:" + std::to_wstring(score));
				NPC->setVisible(false);
				exist = false;
				for (size_t i = 0; i < Silks.size(); i++) {
					Silks[i]->setVisible(false);
				}
				Silks.clear();
			}
		}
		sword->move(3);
		if (sword->getPosX() >= Window::getWidth()) {
			sword->setVisible(false);
			del5.push_back(sword);
		}
	}
	for (size_t i = 0; i < del1.size(); i++) {
		auto silk = del1[i];
		auto it = Silks.begin();
		while (it != Silks.end()) {
			if (*it == silk) {
				Silks.erase(it);
				break;
			}
			else {
				it++;
			}
		}
	}
	for (size_t i = 0; i < del2.size(); i++) {
   		auto coal = del2[i];
		auto it = coals.begin();
     		while (it != coals.end()) {
			if (*it == coal) {
				coals.erase(it);
				break;
			}
			else {
				it++;
			}
		}
	}
	for (size_t i = 0; i < del3.size(); i++) {
		auto sword = del3[i];
		auto it = Swordsl.begin();
		while (it != Swordsl.end()) {
			if (*it == sword) {
				Swordsl.erase(it);
				break;
			}
			else {
				it++;
			}
		}
	}
	for (size_t i = 0; i < del4.size(); i++) {
		auto sword = del4[i];
		auto it = Swordsr.begin();
		while (it != Swordsr.end()) {
			if (*it == sword) {
				Swordsr.erase(it);
				break;
			}
			else {
				it++;
			}
		}
	}
	for (size_t i = 0; i < del5.size(); i++) {
		auto sword = del5[i];
		auto it = Swordsu.begin();
		while (it != Swordsu.end()) {
			if (*it == sword) {
				Swordsu.erase(it);
				break;
			}
			else {
				it++;
			}
		}
	}
	auto lastc = coals[coals.size()-1];
	if (lastc->getPosY() >= 50) {
		for (unsigned int i = 0; i < Random::range(0.f, 5.f); i++) {
			auto coal = gcnew Coal();
			coals.push_back(coal);
			this->addChild(coal);
		}
	}
	auto lasts = Snowballs[Snowballs.size() - 1];
	if (lasts->getPosY() >= 200) {
		for (unsigned int i = 0; i < Random::range(0.f, 1.f); i++) {
			auto snowball = gcnew Snowball();
			Snowballs.push_back(snowball);
			this->addChild(snowball);
		}
	}
	if (!exist && Random::range(0.f, 800.f) <= 1) {
		exist = true;
		NPC = gcnew npc();
		this->addChild(NPC);
		auto silk = gcnew Silk();
		silk->setPos(NPC->getPosX() + 20, NPC->getPosY() + 20);
		Silks.push_back(silk);
		this->addChild(silk);
	}
	if (exist) {
		if (!Silks.empty()) {
			auto lastsi = Silks[Silks.size() - 1];
			if (abs(lastsi->getPosX() - NPC->getPosX()) >= 300) {
				auto silk = gcnew Silk();
				silk->setPos(NPC->getPosX() + 20, NPC->getPosY() + 20);
				Silks.push_back(silk);
				this->addChild(silk);
			}
		}
		else {
			auto silk = gcnew Silk();
			silk->setPos(NPC->getPosX(), NPC->getPosY());
			Silks.push_back(silk);
			this->addChild(silk);
		}
	}
}