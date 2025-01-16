#include "TitleScene.h"
#include <DxLib.h>
#include <cassert>
#include "../Utility.h"
#include "../Library/Time.h"

TitleScene::TitleScene()
{
	bgHandle = LoadGraph("data/image/Title.png");
	assert(bgHandle > 0);
	pushStartHandle= LoadGraph("data/image/メッセージ1_数字記号/メッセージ1_文字/GAMESTERT.png");
	assert(pushStartHandle > 0);
	hBGImageII = LoadGraph("data/image/Haikei2.jpg");
	sound = LoadSoundMem(START_SOUND_PATH);
	//	[GAME START]表示設定の初期化
	DrawStertTimer = 0.0f;
	alpha = 0;
	ofset = (int)((float)MAX_ALPHA / DRAW_STERT_WAIT);
}

TitleScene::~TitleScene()
{
	DeleteGraph(hBGImageII);
	DeleteGraph(bgHandle);
	DeleteGraph(pushStartHandle);
}

void TitleScene::Update()
{
	//	アルファ値の計算
	alpha += (int)(ofset * Time::DeltaTime());

	//	前フレームからの経過時間を取得
	DrawStertTimer += Time::DeltaTime();
	//	一定時間(DRAW_STERT_WAIT)経過したら、アルファ値の加算・減算を切りかえる
	if (DrawStertTimer >= DRAW_STERT_WAIT)
	{
		ofset = -ofset;;
		DrawStertTimer = 0.0f;
	}

	//	[SPACE]キーが押されたらプレイシーンへ
	if (KeyUtility::CheckTrigger(KEY_INPUT_SPACE))
	{
		SceneManager::ChangeScene("PLAY");
		PlaySoundFile(START_SOUND_PATH, DX_PLAYTYPE_NORMAL);
	}

}


void TitleScene::Draw()
{
	DrawGraph(0, 0, hBGImageII, TRUE);
	//	タイトル画面
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//	通常描画
	DrawGraph(0, 0, bgHandle, TRUE);
	//	[GAME START]
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);	//	アルファブレンディング
	DrawGraph(STERT_GRAPH_X, STERT_GRAPH_Y, pushStartHandle, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//	通常描画
}
