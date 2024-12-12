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

	const char*  START_GRAPH_PATH= "data/image/Haikei2.png";		//	タイトル画像のファイル名
	const char* KEY_GRAPH_PATH = "data/image/メッセージ1_文字/GAMESTERT.png";			//	]画像のファイル名
	const char* TITLE_GRAPH_PATH = "data/image/Title.png";

	const int KEY_GRAPH_X = 19;			//	[GAMESTART]表示位置(X)
	const int KEY_GRAPH_Y = 600;		//	[GAMESTART]表示位置(Y)

	const float DRAW_KEY_WAIT = 1.0f;	//	[GAME START]表示間隔(1.0sec)
	const int MAX_ALPHA = 255;			//	最大アルファ値


private:
	int bgHandle;			//	画像ハンドル(タイトル画面)
	int pushKeyHandle;		//	画像ハンドル()
	int alpha;				//	[GAME START]のアルファ値
	int ofset;				//	加算するアルファ値
	float DrawKeyTimer;		//	タイマー

public:
	TitleScene();
	~TitleScene();
	void Update() override;
	void Draw() override;
};
