#pragma once
#include <easy2d/easy2d.h>
using namespace easy2d;

class Silk : public Sprite {
public:
	float speed = 1.5f * Random::range(-2.f, 2.f);
	Silk();
	void move();
};