#include "PlayScene.h"
#include <DxLib.h>
#include "Player.h"
#include "Enemy2.h"
#include "Enemy.h"

PlayScene::PlayScene()
{
	Instantiate<Player>();
	Instantiate<Enemy2>();
	Instantiate<Enemy>();
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TITLE");
	}
}

void PlayScene::Draw()
{
	DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
}
