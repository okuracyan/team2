#include "Player.h"
#include <DxLib.h>
#include <cassert>

Player::Player()
{
	hImage = LoadGraph("ƒQ[ƒ€‘fÞ/rocket_01.png");
	assert(hImage > 0);

	position.x = 0;
	position.y = 0;
}

Player::~Player()
{
	DeleteGraph(hImage);
}

void Player::Update()
{
	if (hImage) {
		position.x += 2.0f;
	}
	else {
		if (CheckHitKey(KEY_INPUT_D) != 0)
			position.x += 3.0f;
		if (CheckHitKey(KEY_INPUT_A) != 0)
			position.x -= 3.0f;
		if (CheckHitKey(KEY_INPUT_W) != 0)
			position.y -= 5.0f;
		if (CheckHitKey(KEY_INPUT_S) != 0)
			position.y += 5.0f;
		if (CheckHitKey(KEY_INPUT_Q) != 0)
			position.y += 1.0f;
		if (CheckHitKey(KEY_INPUT_E) != 0)
			position.y -= 1.0f;
	}
}

void Player::Draw()
{
	DrawGraph(position.x, position.y, hImage, TRUE);
}
