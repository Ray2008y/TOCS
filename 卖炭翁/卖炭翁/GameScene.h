#pragma once
#include "Player.h"
#include "Coal.h"
#include "Snowball.h"
#include "NPC.h"
#include "Silk.h"
#include "Sword.h"
using namespace easy2d;

class GameScene : public Scene {
public:
	Player* player;
	std::vector<Coal*> coals;
	std::vector<Snowball*> Snowballs;
	std::vector<Silk*> Silks;
	std::vector<Sword*> Swordsl, Swordsr, Swordsu;
	bool exist = false;
	npc* NPC;
	int score = 0;
	Text* scoreText;
	GameScene();
	void onUpdate() override;
};