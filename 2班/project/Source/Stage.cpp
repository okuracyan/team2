#include"Stage.h"

#include"Player.h"
#include"Enemy.h"
#include"Enemy2.h"

const int CHIP_SIZE = 40;
#include "Stage1.h"


Stage::Stage()
{
	for (int j = 0; j < HEIGHT; j++) {
		for (int i = 0; i < WIDTH; i++) {
			if (map[j][i] == 9) {
				Player* p = Instantiate<Player>();
				p->position.x = i * 40 + 100;
				p->position.y = j * 40 + 100;
			}
			if (map[j][i] == 2) {
				Enemy* c = Instantiate<Enemy>();
				c->position.x = i * 40 + 100;
				c->position.y = j * 40 + 100;
			}
			if (map[j][i] == 3) {
				Enemy2* c = Instantiate<Enemy2>();
				c->position.x = i * 40 + 100;
				c->position.y = j * 40 + 100;
			}
		}
	}
	scroll = 0;
}
	


Stage::~Stage()
{
}

void Stage::Draw()
{
}

int Stage::IsWallRight(VECTOR2 pos)
{
	int i = (pos.x - 100) / 40;
	int j = (pos.y - 100) / 40;
	if (map[j][i] == 1) {
		int push = ((int)pos.x - 100) % 40 + 1;
		return push;
	}
	return 0;
}

int Stage::IsWallDown(VECTOR2 pos)
{
	int i = (pos.x - 100) / 40;
	int j = (pos.y - 100) / 40;
	if (map[j][i] == 1) {
		int push = ((int)pos.y - 100) % 40 + 1;
		return push;
	}
	return 0;
}

int Stage::IsWallLeft(VECTOR2 pos)
{
	int i = (pos.x - 100) / 40;
	int j = (pos.y - 100) / 40;
	if (map[j][i] == 1) {
		int push = 40 - ((int)pos.x - 100) % 40;
		return push;
	}
	return 0;
}

int Stage::IsWallUp(VECTOR2 pos)
{
	int i = (pos.x - 100) / 40;
	int j = (pos.y - 100) / 40;
	if (map[j][i] == 1) {
		int push = 40 - ((int)pos.y - 100) % 40;
		return push;
	}
	return 0;
}
