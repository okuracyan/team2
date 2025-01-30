#include "ClearScene.h"
#include <DxLib.h>
#include <cassert>
#include "../Utility.h"
#include "TitleScene.h"
#include "Record.h"
#include "Score.h"

ClearScene::ClearScene()
{
	bgHandle = LoadGraph("data/image/メッセージ1_数字記号/メッセージ1_文字/SCORE.png");
	assert(bgHandle > 0);
	ScoreHandle = LoadGraph("data/image/メッセージ1_数字記号/メッセージ1_文字/CONGRATULATIONS.png");
	assert(ScoreHandle > 0);
	pushSpaceHandle = LoadGraph("data/image/PUSHSPACE.png");
	assert(pushSpaceHandle > 0);
	hBGImageII = LoadGraph("data/image/Haikei2.jpg");
	Instantiate<Score>();
	
}

ClearScene::~ClearScene()
{
	DeleteGraph(bgHandle);
	DeleteGraph(hBGImageII);
	DeleteGraph(pushSpaceHandle);
}

void ClearScene::Update()
{

	if ((CheckHitKey(KEY_INPUT_SPACE)))
	{
		SceneManager::ChangeScene("TITLE");
	}
}


void ClearScene::Draw()
{
	DrawGraph(0, 0, hBGImageII, TRUE);
	//	タイトル画面
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//	通常描画
	DrawGraph(0, 0, bgHandle, TRUE);
	//	[GameClear]
	DrawGraph(CLEAR_GRAPH_X, CLEAR_GRAPH_Y, ScoreHandle, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//	通常描
	DrawGraph(SPACE_GRAPH_X, SPACE_GRAPH_Y, pushSpaceHandle, TRUE);

	Record* r = FindGameObject<Record>();

}