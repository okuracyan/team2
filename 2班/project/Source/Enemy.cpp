#include "Enemy.h"
#include <cassert>

#include"Player.h"


Enemy::Enemy()
{
	hImage = LoadGraph("data/image/ufo_02_green.png");
	assert(hImage > 0);
	position.x = 300;
	position.y = 300;

}

Enemy::~Enemy()
{
	DeleteGraph(hImage);
}

void Enemy::Update()
{
	VECTOR2 uCenter;
	uCenter.x = position.x + 32;
	uCenter.y = position.y + 32;
}

void Enemy::Draw()
{
	DrawGraph(position.x, position.y, hImage, TRUE);
}
