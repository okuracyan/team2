#include "TitleScene.h"
#include <DxLib.h>
#include <cassert>
#include "../Utility.h"

TitleScene::TitleScene()
{
	bgHandle = LoadGraph(TITLE_GRAPH_PATH);
	assert(bgHandle > 0);
	pushKeyHandle = LoadGraph(KEY_GRAPH_PATH);
	assert(pushKeyHandle > 0);
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{
	//	アルファ値の計算
	alpha += (int)(ofset * Time::DeltaTime());

	//	前フレームからの経過時間を取得
	DrawKeyTimer += Time::DeltaTime();
	//	一定時間(DRAW_KEY_WAIT)経過したら、アルファ値の加算・減算を切りかえる
	if (DrawKeyTimer >= DRAW_KEY_WAIT)
	{
		ofset = -ofset;
		DrawKeyTimer = 0.0f;
	}

	//	[SPACE]キーが押されたらプレイシーンへ
	if (KeyUtility::CheckTrigger(KEY_INPUT_SPACE))
	{
		//	サウンドが終了するまで待つ
		//PlaySoundFile(START_SOUND_PATH, DX_PLAYTYPE_NORMAL);

		SceneManager::ChangeScene("PlayScene");
	}

	//	[ESC]キーが押されたらゲーム終了
	if (KeyUtility::CheckTrigger(KEY_INPUT_ESCAPE))
	{
		SceneManager::Exit();
	}
}


void TitleScene::Draw()
{
	//	[PUSH SPACE KEY]
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);	//	アルファブレンディング
	DrawGraph(KEY_GRAPH_X, KEY_GRAPH_Y, pushKeyHandle, TRUE);
}
