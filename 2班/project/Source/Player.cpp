#include "Player.h"
#include <DxLib.h>
#include <cassert>
#include "config.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Stage.h"
#include "Time.h"
#include"ResultScene.h"
#include"ClearScene.h"


Player::Player()
{
	hImage = LoadGraph("data/image/rocket_01_fire.png");
	assert(hImage > 0);
	bomImage = LoadGraph("data/image/Bakuhatu.png");
	assert(bomImage > 0);

	sound = LoadSoundMem("data/sound/BAKUHATU.mp3");


	
 
	position.x = 0;
	position.y = 0;
	IsBom = false;
	dead = false;
	goal = false;

	patternX = 0;
	patternY = 0;
	animTimer = 0.0f;
}

Player::~Player()
{
	
	DeleteGraph(hImage);
	DeleteGraph(bomImage);
}

void Player::Update()
{
	if (IsBom)
	{
		animTimer += Time::DeltaTime();
		if (animTimer >= 0.15f)
		{
			patternX++;
			animTimer = 0.0f;
		}
		if (patternX >= 7)
		{
			patternX = 7;
			DestroyMe();
		}

		if (patternX >= 7)
		{

			SceneManager::ChangeScene("RESULT");
		}
	}

	Stage* s = FindGameObject<Stage>();
	if (!IsBom)
	{
		{
			position.x += 5.0f;
		}

		if (CheckHitKey(KEY_INPUT_D) != 0)
			position.x -= 1.0f;
		if (CheckHitKey(KEY_INPUT_A) != 0)
			position.x -= 4.0f;
		if (CheckHitKey(KEY_INPUT_W) != 0)
			position.y -= 8.0f;
		if (CheckHitKey(KEY_INPUT_S) != 0)
			position.y += 8.0f;

		if ((CheckHitKey(KEY_INPUT_LSHIFT)) & CheckHitKey(KEY_INPUT_Q))
			position.y += 1.0f;
		if ((CheckHitKey(KEY_INPUT_LSHIFT)) & CheckHitKey(KEY_INPUT_E))
			position.y -= 1.0f;

		if (CheckHitKey(KEY_INPUT_X) != 0)//ブースト、
			position.x += 30.0f;
		if (CheckHitKey(KEY_INPUT_SPACE) != 0)//ぶれーき
			position.x -= 5.0f;


	if (CheckHitKey(KEY_INPUT_9)) // 自爆スイッチ
	{
		IsBom = true;
		dead = true;
	}



	if (position.y <= 0) {
		position.y = 0;
	}
	if (position.y > SCREEN_HEIGHT - 37) {
		position.y = SCREEN_HEIGHT - 37;
	}
	if (IsBom == false) {
		std::list<Enemy2*> bCenter = FindGameObjects<Enemy2>();
		for (Enemy2* e : bCenter) {
			if (CircleHit(position, e->position, 0)) {
				//DestroyMe();
				IsBom = true;
				dead = true;
				PlaySoundMem(sound, DX_PLAYTYPE_BACK);

			}
		}
		std::list<Enemy*> uCenter = FindGameObjects<Enemy>();
		for (Enemy* e : uCenter) {
			if (CircleHit(position, e->position, 0)) {
				//DestroyMe();
				IsBom = true;
				dead = true;
				PlaySoundMem(sound, DX_PLAYTYPE_BACK);

			}
		}
	}
	if (position.x - s->scroll > 400) {
		s->scroll = position.x - 400;
	}
	if (position.x - s->scroll < 0) {
		s->scroll = position.x;
	}

		
		//if (position.x - s->scroll > 400) 
			//s->scroll = position.x - 400;
		if (s->scroll = 20100); {
				s->scroll > 20100;
		}


		if (position.x - s->scroll < 0) {
			s->scroll = position.x;
			
		}
		
	}
	if (position.x >= 20100)
	{	 
		SceneManager::ChangeScene("CLEAR");
	}
	
}

void Player::Draw()
{
	Stage* s = FindGameObject<Stage>();
	DrawRectGraph(position.x - s->scroll, position.y, 0, 0, 80, 80, hImage, TRUE);

	if (IsBom)
	{
		DrawRectGraph(position.x - s->scroll -30, position.y -30, 120*patternX, 120*patternY, 120, 120, bomImage, TRUE);
	}

}
