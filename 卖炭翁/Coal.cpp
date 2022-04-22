#include <easy2d/easy2d.h>
#include <corecrt_math.h>
#include "Coal.h"

Coal::Coal() : Sprite(L"pic/coal.png") {
	this->setScale(0.08f, 0.08f);
	this->setAnchor(0.01f, 0.01f);
	this->setPos(Random::range(30.f, 910.f), 0);
}
void Coal::move() {
	this->setPosY(getPosY() + speed);
}