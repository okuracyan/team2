#include "Enemy2.h"
#include "Player.h"
#include <cassert>
#include "PlayScene.h"
#include <DxLib.h>
#include "config.h"
#include "../config.h"

Enemy2::Enemy2()
{
	hImage = LoadGraph("data/image/ufo_08.png");
	assert(hImage > 0);
	position.x = 500;
	position.y = 300;
	frameCounter = 0;
	timer = 5;


}

Enemy2::~Enemy2()
{
	DeleteGraph(hImage);
}

void Enemy2::Update()
{
<<<<<<< HEAD
	if (hImage) {
		position.y += 2.0f;
		
	}

	
	 if (timer == 0) {
		position.y -= 2.0f;
	}
	
=======
		position.y += 1 * sin(timer);
		if (position.x < 0) {
				position.x = 0;
			}
		if (position.y > SCREEN_HEIGHT - 64) {
				position.y = SCREEN_HEIGHT - 64;
			}
				
			
>>>>>>> c0fd4fd10b0227aa9449f02bef600c3c88c0019d
	}
   // if (hImage) {
	//	position.y -= 1 * sin(timer);
	//}

void Enemy2::Draw()
{
	DrawGraph(position.x, position.y, hImage, TRUE);
}

//if (hImage) {
		//position.y += 2.0f;


	//else if (timer == 0) {
		//position.y -= 2.0f;
	//}