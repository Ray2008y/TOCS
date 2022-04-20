#include <easy2d/easy2d.h>
#include <corecrt_math.h>
#include "NPC.h"

npc::npc() : Sprite(L"pic/NPC.png") {
	this->setScale(0.07f, 0.07f);
	this->setAnchor(0.01f, 0.01f);
	this->setPos(Random::range(50.f, 910.f), Window::getHeight() - 222);
}
void npc::move() {
	if (this->getPosY() > Window::getHeight() - 180) {
		auto jumpBy = gcnew JumpBy(2, Point(), -25);
		this->runAction(jumpBy);
	}
}