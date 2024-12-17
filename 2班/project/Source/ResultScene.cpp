#include "ResultScene.h"
#include <DxLib.h>
#include <cassert>
#include "../Utility.h"
#include "Player.h"
ResultScene::ResultScene()
{
	bgHandle = LoadGraph("data/image/メッセージ1_数字記号/メッセージ1_文字/SCORE.png");
	assert(bgHandle > 0);
	ScoreHandle = LoadGraph("data/image/メッセージ1_数字記号/メッセージ1_文字/GAMEOVERA.png");
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
	//	タイトル画面
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//	通常描画
	DrawGraph(0, 0, bgHandle, TRUE);
	//	[GameOver]
	DrawGraph(OVER_GRAPH_X, OVER_GRAPH_Y, ScoreHandle, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//	通常描

	DrawString(0, 0, "左シフトでタイトル", GetColor(255, 255, 255));
}