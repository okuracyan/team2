#include "PlayScene.h"
#include <DxLib.h>
#include "Player.h"
#include "Enemy2.h"
#include "Enemy.h"
#include"Stage.h"
#include"Stage1.h"

PlayScene::PlayScene()
{
	Stage* s = Instantiate<Stage>();
	//hBGImageI = LoadGraph("data/image/Haikei.jpg");
	hBGImageII = LoadGraph("data/image/Haikei2.jpg");

	
}

PlayScene::~PlayScene()
{
	//DeleteGraph(hBGImageI);
	DeleteGraph(hBGImageII);

}

void PlayScene::Update()
{


	if ( (CheckHitKey(KEY_INPUT_T)) || CheckHitKey(KEY_INPUT_RSHIFT))
	{
		SceneManager::ChangeScene("TITLE");
	}
}

void PlayScene::Draw()
{
	DrawGraph(0,0, hBGImageII, TRUE);
	
	
}
