#include "ResultScene.h"
#include <DxLib.h>
#include <cassert>
#include "../Utility.h"
#include "Player.h"
#include "Record.h"
#include "Score.h"

ResultScene::ResultScene()
{
	bgHandle = LoadGraph("data/image/メッセージ1_数字記号/メッセージ1_文字/SCORE.png");
	assert(bgHandle > 0);
	ScoreHandle = LoadGraph("data/image/メッセージ1_数字記号/メッセージ1_文字/GAMEOVERA.png");
	assert(ScoreHandle > 0);
	pushSpaceHandle = LoadGraph("data/image/PUSHSPACE.png");
	assert(pushSpaceHandle > 0);
	hBGImageII = LoadGraph("data/image/Haikei2.jpg");
	Instantiate<Score>();
}

ResultScene::~ResultScene()
{
	DeleteGraph(bgHandle);
	DeleteGraph(hBGImageII);
	DeleteGraph(pushSpaceHandle);
}

void ResultScene::Update()
{

	if ((CheckHitKey(KEY_INPUT_SPACE)))
	{
		SceneManager::ChangeScene("TITLE");
	}
}


void ResultScene::Draw()
{
	DrawGraph(0, 0, hBGImageII, TRUE);
	//	タイトル画面
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//	通常描画
	DrawGraph(0, 0, bgHandle, TRUE);
	//	[GameOver]
	DrawGraph(OVER_GRAPH_X, OVER_GRAPH_Y, ScoreHandle, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//	通常描
	DrawGraph(SPACE_GRAPH_X, SPACE_GRAPH_Y, pushSpaceHandle, TRUE);

}