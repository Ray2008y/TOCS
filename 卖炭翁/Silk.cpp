#include <easy2d/easy2d.h>
#include <corecrt_math.h>
#include "Silk.h"

Silk::Silk() : Sprite(L"pic/fabric.png") {
	this->setScale(0.3f, 0.3f);
	this->setAnchor(0.05f, 0.05f);
}
void Silk::move() {
	this->setPosX(getPosX() + speed);
}