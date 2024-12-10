#pragma once
#include "../Library/gameObject.h"
/// <summary>
/// タイトルシーン
/// 
/// タイトルを表示して、キーを押したらプレイシーンに移行する。
/// </summary>
class TitleScene : public SceneBase
{
private:
	const char* TITLE_GRAPH_PATH = "data/Graph/Title.png";		//	タイトル画像のファイル名
	const char* KEY_GRAPH_PATH = "data/Graph/Key.png";			//	[PUSH SPACE KEY]画像のファイル名
	const char* START_SOUND_PATH = "data/Sound/Start.mp3";		//	スタートサウンドのファイル名

	const int KEY_GRAPH_X = 19;			//	[PUSH SPACE KEY]表示位置(X)
	const int KEY_GRAPH_Y = 600;		//	[PUSH SPACE KEY]表示位置(Y)

	const float DRAW_KEY_WAIT = 1.0f;	//	[PUSH SPACE KEY]表示間隔(1.0sec)
	const int MAX_ALPHA = 255;			//	最大アルファ値

private:
	int bgHandle;			//	画像ハンドル(タイトル画面)
	int pushKeyHandle;		//	画像ハンドル(PUSH SPACE KEY)
	int alpha;				//	[PUSH SPACE KEY]のアルファ値

public:
	TitleScene();
	~TitleScene();
	void Update() override;
	void Draw() override;
};
