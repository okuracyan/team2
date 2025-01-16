#include"Stage.h"

#include"Player.h"
#include"Enemy.h"
#include"Enemy2.h"

const int CHIP_SIZE = 40;
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "Stage4.h"
#include "Stage5.h"
#include "Stage6.h"
#include "Stage7.h"
#include "Stage8.h"
#include "Stage9.h"
#include "Stage10.h"
int map[HEIGHT][WIDTH * 10];


Stage::Stage()
{
	for (int j = 0; j < HEIGHT; j++) {
		for (int x = 0; x < WIDTH; x++) {
			map[j][x] = map1[j][x];
			map[j][x + WIDTH] = map2[j][x];
			map[j][x + WIDTH * 2] = map3[j][x];
			map[j][x + WIDTH * 3] = map4[j][x];
			map[j][x + WIDTH * 4] = map5[j][x];
			map[j][x + WIDTH * 5] = map6[j][x];
			map[j][x + WIDTH * 6] = map7[j][x];
			map[j][x + WIDTH * 7] = map8[j][x];
			map[j][x + WIDTH * 8] = map9[j][x];
			map[j][x + WIDTH * 9] = map10[j][x];
		}
	}
	for (int j = 0; j < HEIGHT; j++) {
		for (int i = 0; i < WIDTH*10; i++) {
			if (map[j][i] == 9) {
				Player* p = Instantiate<Player>();
				p->position.x = i * 40 + 100;
				p->position.y = j * 40 + 10;
			}
			if (map[j][i] == 2) {
				Enemy* c = Instantiate<Enemy>();
				c->position.x = i * 40 + 100;
				c->position.y = j * 40 + 10;
			}
			if (map[j][i] == 3) {
				Enemy2* c = Instantiate<Enemy2>();
				c->position.x = i * 40 + 100;
				c->position.y = j * 40 + 10;
			}
			
			
		}
	}
	scroll = 0;
}	



Stage::~Stage(){
}

void Stage::Draw()
{
	for (int j = 0; j < HEIGHT; j++) {
		int y = j * 40 + 100;
		for (int i = 0; i < WIDTH*10; i++) {
			int x = i * 40 + 100;
			if (map[j][i] == 1) {
				DrawRectGraph(x - scroll, y, 0, 40, 40, 40, hImage, TRUE);
			}
			//if (map[j][i] == 2) {
			//	DrawRectGraph(x, y, 120, 0, 40, 40, hImage, TRUE);
			//}
			}
	}
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

bool Stage::IsGoal(VECTOR2 pos)
{

	return false;
}
