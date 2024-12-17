#pragma once
#include "../Library/gameObject.h"

class GameOver : public SceneBase
{
private://	ゲームオーバー

	const char* KEY_GRAPH_PATH = "data/image/Haikei2.png";
	const char* OVER_GRAPH_PATH = "data/image/メッセージ1_数字記号/メッセージ1_文字/GAMEOVER.png";			//	GAMEOVER]画像のファイル名
	const char* SCORE_GRAPH_PATH = "data/image/メッセージ1_数字記号/メッセージ1_文字/SCORE.png";
		
	const int OVER_GRAPH_X = 370;			//	[GAMEOVER]表示位置(X)
	const int OVER_GRAPH_Y = 450;		//	[GAMEOVER]表示位置(Y)

private:
	int bgHandle;			//	画像ハンドル(タイトル画面)
	int ScoreHandle;		//	画像ハンドル(Score)

public:
	GameOver();
	~GameOver();
	void Update() override;
	void Draw() override;
};