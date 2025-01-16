#pragma once
#include "../Library/gameObject.h"
/// <summary>
/// タイトルシーン
/// 
/// タイトルを表示して、キーを押したらプレイシーンに移行する。
/// </summary>
class TitleScene : public SceneBase
{
private://	タイトル画面

	const char*  KEY_GRAPH_PATH= "data/image/Haikei2.png";		
	const char*  STERT_GRAPH_PATH= "data/image/メッセージ1_数字記号/メッセージ1_文字/GAMESTERT.png";
	const char* TITLE_GRAPH_PATH = "data/image/Title.png";//	タイトル画像のファイル名
	const char* START_SOUND_PATH = "data/sound/START.mp3";

	const int STERT_GRAPH_X = 370;			//	[GAMESTART]表示位置(X)
	const int STERT_GRAPH_Y = 450;		//	[GAMESTART]表示位置(Y)

	const float DRAW_STERT_WAIT = 1.0f;	//	[GAME START]表示間隔(1.0sec)
	const int MAX_ALPHA = 255;			//	最大アルファ値


private:
	int bgHandle;			//	画像ハンドル(タイトル画面)
	int pushStartHandle;		//	画像ハンドル(GAMESTART)
	int alpha;				//	[GAME START]のアルファ値
	int ofset;				//	加算するアルファ値
	int sound;//効果音
	float DrawStertTimer;		//	タイマー


public:
	TitleScene();
	~TitleScene();
	void Update() override;
	void Draw() override;
	int hBGImageII;
};
