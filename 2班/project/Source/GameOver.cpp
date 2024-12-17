#include "GameOver.h"
#include <DxLib.h>
#include <cassert>
#include "../Utility.h"
GameOver::GameOver()
{
	bgHandle = LoadGraph("data/image/メッセージ1_数字記号/メッセージ1_文字/SCORE.png");
	assert(bgHandle > 0);
	ScoreHandle = LoadGraph("data/image/メッセージ1_数字記号/メッセージ1_文字/GAMEOVER.png");
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
	//	タイトル画面
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//	通常描画
	DrawGraph(0, 0, bgHandle, TRUE);
	//	[GAME START]
	DrawGraph(OVER_GRAPH_X, OVER_GRAPH_Y, ScoreHandle, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//	通常描画
}