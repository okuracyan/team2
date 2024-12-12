#include "Enemy2.h"
#include "Player.h"
#include <cassert>
#include "PlayScene.h"
#include <DxLib.h>
#include "config.h"
#include "Stage.h"

Enemy2::Enemy2()
{
	hImage = LoadGraph("data/image/ufo_08.png");
	assert(hImage > 0);
	position.x = 500;
	position.y = 300;
	frameCounter = 0;
	timer = 0;


}

Enemy2::~Enemy2()
{
	DeleteGraph(hImage);
}

void Enemy2::Update()
{
	timer += 0.04f;//ë¨Ç≥
		position.y += 10 * sin(timer);//êUÇÍïù
		if (position.x < 0) {
				position.x = 0;
			}
		if (position.y > SCREEN_HEIGHT - 64) {
				position.y = SCREEN_HEIGHT - 64;
			}
		VECTOR2 bCenter;
		bCenter.x = position.x + 32;
		bCenter.y = position.y + 32;
	}

void Enemy2::Draw()

{
	Stage* s = FindGameObject<Stage>();
	DrawRectGraph(position.x - s->scroll, position.y, 0, 0, 80, 80, hImage, TRUE);

	
}
