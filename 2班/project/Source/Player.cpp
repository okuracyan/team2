#include "Player.h"
#include <DxLib.h>
#include <cassert>
#include "config.h"
#include "Enemy.h"
#include "Enemy2.h"

Player::Player()
{
	hImage = LoadGraph("data/image/rocket_01_fire.png");
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

	if (position.x <= 0) {
		position.x = 0;
	}
	if (position.x > SCREEN_WIDTH - 64) {
		position.x = SCREEN_WIDTH - 64;
	}
	if (position.y <= 0) {
		position.y = 0;
	}
	if (position.y > SCREEN_HEIGHT - 64) {
		position.y = SCREEN_HEIGHT - 64;
	}
	std::list<Enemy2*> bCenter = FindGameObjects<Enemy2>();
	for (Enemy2* e : bCenter) {
		if (CircleHit(position, e->position, 56)) {
			DestroyMe();

		}
	}
}

void Player::Draw()
{
	DrawGraph(position.x, position.y, hImage, TRUE);
}
