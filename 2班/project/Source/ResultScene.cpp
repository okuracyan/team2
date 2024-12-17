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
}

ResultScene::~ResultScene()
{
	DeleteGraph(bgHandle);
}

void ResultScene::Update()
{
}


void ResultScene::Draw()
{
	//	�^�C�g�����
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//	�ʏ�`��
	DrawGraph(0, 0, bgHandle, TRUE);
	//	[GameOver]
	DrawGraph(OVER_GRAPH_X, OVER_GRAPH_Y, ScoreHandle, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//	�ʏ�`

	DrawString(0, 0, "���V�t�g�Ń^�C�g��", GetColor(255, 255, 255));
}