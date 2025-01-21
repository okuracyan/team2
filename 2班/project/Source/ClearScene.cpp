#include "ClearScene.h"
#include <DxLib.h>
#include <cassert>
#include "../Utility.h"
#include "TitleScene.h"
ClearScene::ClearScene()
{
	bgHandle = LoadGraph("data/image/���b�Z�[�W1_�����L��/���b�Z�[�W1_����/SCORE.png");
	assert(bgHandle > 0);
	ScoreHandle = LoadGraph("data/image/���b�Z�[�W1_�����L��/���b�Z�[�W1_����/CONGRATULATIONS.png");
	assert(ScoreHandle > 0);
	hBGImageII = LoadGraph("data/image/Haikei2.jpg");
}

ClearScene::~ClearScene()
{
	DeleteGraph(bgHandle);
	DeleteGraph(hBGImageII);
}

void ClearScene::Update()
{

	if ((CheckHitKey(KEY_INPUT_T)) || CheckHitKey(KEY_INPUT_RSHIFT))
	{
		SceneManager::ChangeScene("TITLE");
	}
}


void ClearScene::Draw()
{
	DrawGraph(0, 0, hBGImageII, TRUE);
	//	�^�C�g�����
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//	�ʏ�`��
	DrawGraph(0, 0, bgHandle, TRUE);
	//	[GameClear]
	DrawGraph(CLEAR_GRAPH_X, CLEAR_GRAPH_Y, ScoreHandle, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//	�ʏ�`


}