#include <easy2d/easy2d.h>
#include <corecrt_math.h>
#include "Snowball.h"

Snowball::Snowball() : Sprite(L"pic/snowball.png") {
	this->setScale(0.3f, 0.3f);
	this->setAnchor(0.01f, 0.01f);
	this->setPos(Random::range(50.f, 910.f), 0);
}
void Snowball::move() {
	this->setPosY(getPosY() + speed);
}