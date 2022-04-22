#pragma once
#include <easy2d/easy2d.h>
using namespace easy2d;

class Player : public Sprite {
public:
	int dirction;
	float speed = 4;
	Player();
	void move(int dirction);
};