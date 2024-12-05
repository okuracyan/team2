#include "Enemy2.h"
#include "Player.h"
#include <cassert>
#include "PlayScene.h"
#include <DxLib.h>

Enemy2::Enemy2()
{
	hImage = LoadGraph("data/image/ufo_08.png");
	assert(hImage > 0);
	position.x = 40;
	position.y = 40;
	frameCounter = 0;
	timer = 5;
	

}

Enemy2::~Enemy2()
{
	DeleteGraph(hImage);
}

void Enemy2::Update()
{
	if (hImage) {
		position.y += 2.0f;
		
	}

	
	 if (timer == 0) {
		position.y -= 2.0f;
	}
	
	}

void Enemy2::Draw()
{
	DrawGraph(position.x, position.y, hImage, TRUE);
}