#include "TitleScene.h"
#include <DxLib.h>
#include <cassert>
#include "../Utility.h"

TitleScene::TitleScene()
{
	bgHandle = LoadGraph("data/image/Title.png");
	assert(bgHandle > 0);
	pushKeyHandle= LoadGraph("data/image/.png");
	
	//	[GAME START]表示設定の初期化
	DrawKeyTimer = 0.0f;
	alpha = 0;
	ofset = (int)((float)MAX_ALPHA / DRAW_KEY_WAIT);
}

TitleScene::~TitleScene()
{
	DeleteGraph(bgHandle);
	DeleteGraph(pushKeyHandle);
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
		ofset = -ofset;;
		DrawKeyTimer = 0.0f;
	}

	//	[SPACE]キーが押されたらプレイシーンへ
	if (KeyUtility::CheckTrigger(KEY_INPUT_SPACE))
	{
		SceneManager::ChangeScene("PLAY");
	}
}


void TitleScene::Draw()
{
	//	タイトル画面
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//	通常描画
	DrawGraph(0, 0, bgHandle, TRUE);
	//	[GAME START]
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);	//	アルファブレンディング
	DrawGraph(KEY_GRAPH_X, KEY_GRAPH_Y, pushKeyHandle, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//	通常描画
}
