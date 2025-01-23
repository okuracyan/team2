#pragma once
#pragma once
#pragma once
#include "../Library/gameObject.h"

class ClearScene : public SceneBase
{
private://ゲームクリア

	const char* KEY_GRAPH_PATH = "data/image/Haikei2.png";
	const char* CLEAR_GRAPH_PATH = "data/image/メッセージ1_数字記号/メッセージ1_文字/CONGRATULATIONS.png";			//	]画像のファイル名
	const char* SCORE_GRAPH_PATH = "data/image/メッセージ1_数字記号/メッセージ1_文字/SCORE.png";
	const char* SPACE_GRAPH_PATH = "data/imag/PUSHSPACE.png";

	const int CLEAR_GRAPH_X = 370;			//	[GAMEOVER]表示位置(X)
	const int CLEAR_GRAPH_Y = 450;		//	[GAMEOVER]表示位置(Y)
	const int SPACE_GRAPH_X = 0;			//	[]表示位置(X)
	const int SPACE_GRAPH_Y = 650;		//	[]表示位置(Y)

private:
	int bgHandle;			//	画像ハンドル(タイトル画面)
	int ScoreHandle;		//	画像ハンドル(Score)
	int pushSpaceHandle;
public:
	ClearScene();
	~ClearScene();
	void Update() override;
	void Draw() override;
	int hBGImageII;
};