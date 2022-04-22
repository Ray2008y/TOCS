#include <easy2d/easy2d.h>
#include <corecrt_math.h>
#include "Sword.h"

Sword::Sword() : Sprite(L"pic/sword.png") {
	this->setScale(0.1f, 0.1f);
	this->setAnchor(0.005f, 0.005f);
	auto rotateBy = gcnew RotateBy(0.25f, 15.f);
	auto LoopRB = gcnew Loop(rotateBy);
	this->runAction(LoopRB);
}
void Sword::move(int dirction) {
	switch (dirction) {
		case 1: {
			this->setPosX(getPosX() - speed);
			break;
		}
		case 2: {
			this->setPosX(getPosX() + speed);
			break;
		}
		case 3: {
			this->setPosY(getPosY() - speed);
			break;
		}
	}
	
}