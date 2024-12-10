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
}

void Enemy::Draw()
{
	DrawGraph(position.x, position.y, hImage, TRUE);
}
