#include "GameOver.h"
#include <DxLib.h>
#include <cassert>
#include "../Utility.h"
GameOver::GameOver()
{
	bgHandle = LoadGraph("data/image/���b�Z�[�W1_�����L��/���b�Z�[�W1_����/SCORE.png");
	assert(bgHandle > 0);
	ScoreHandle = LoadGraph("data/image/���b�Z�[�W1_�����L��/���b�Z�[�W1_����/GAMEOVER.png");
	assert(ScoreHandle > 0);
}

GameOver::~GameOver()
{
	DeleteGraph(bgHandle);
}

void GameOver::Update()
{
}


void GameOver::Draw()
{
	//	�^�C�g�����
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//	�ʏ�`��
	DrawGraph(0, 0, bgHandle, TRUE);
	//	[GAME START]
	DrawGraph(OVER_GRAPH_X, OVER_GRAPH_Y, ScoreHandle, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//	�ʏ�`��
}