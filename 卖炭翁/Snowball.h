#pragma once
#include <easy2d/easy2d.h>
using namespace easy2d;

class Snowball : public Sprite {
public:
	float speed = 1.5;
	Snowball();
	void move();
};