#pragma once
#include <easy2d/easy2d.h>
using namespace easy2d;

class Sword : public Sprite {
public:
	int dirction;
	float speed = 2;
	Sword();
	void move(int dirction);
}; 
