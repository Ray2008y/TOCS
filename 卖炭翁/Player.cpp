#include "Player.h"

Player::Player() : dirction(0) {
	this->open(L"pic/player.png");
	this->setScale(0.07f, 0.07f);
	this->setAnchor(0.5f, 0.5f);
	this->setPos(Window::getWidth() / 2, Window::getHeight() - 170);
}

void Player::move(int dirction) {
	switch (dirction) {
		case 1: {
			if (this->getPosX() > this->getWidth() / 2) {
				this->movePosX(-speed);
			}
			break;
		}
		case 2: {
			if (this->getPosX() < Window::getWidth() - this->getWidth() / 2) {
				this->movePosX(speed);
			}
			break;
		}
		case 3: {
			if (this->getPosY() > Window::getHeight() - 180) {
				auto jumpBy = gcnew JumpBy(2, Point(), -25);
				this->runAction(jumpBy);
			}
			break;
		}
	}
}