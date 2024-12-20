#include "ResultScene.h"
#include <DxLib.h>
#include <cassert>
#include "../Utility.h"
#include "Player.h"
ResultScene::ResultScene()
{
	bgHandle = LoadGraph("data/image/���b�Z�[�W1_�����L��/���b�Z�[�W1_����/SCORE.png");
	assert(bgHandle > 0);
	ScoreHandle = LoadGraph("data/image/���b�Z�[�W1_�����L��/���b�Z�[�W1_����/GAMEOVERA.png");
	assert(ScoreHandle > 0);
	hBGImageII = LoadGraph("data/image/Haikei2.jpg");
}

ResultScene::~ResultScene()
{
	DeleteGraph(bgHandle);
	DeleteGraph(hBGImageII);
}

void ResultScene::Update()
{

	if ((CheckHitKey(KEY_INPUT_T)) || CheckHitKey(KEY_INPUT_RSHIFT))
	{
		SceneManager::ChangeScene("TITLE");
	}
}


void ResultScene::Draw()
{
	DrawGraph(0, 0, hBGImageII, TRUE);
	//	�^�C�g�����
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//	�ʏ�`��
	DrawGraph(0, 0, bgHandle, TRUE);
	//	[GameOver]
	DrawGraph(OVER_GRAPH_X, OVER_GRAPH_Y, ScoreHandle, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//	�ʏ�`

	
}