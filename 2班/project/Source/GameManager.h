#pragma once
#include "../Library/GameObject.h"
#include "../Utility.h"
#include "Player.h"
#include "Score.h"
#include "Stage.h"


enum class GAME_STATE
{
	INIT = 0, // ゲームの初期設定
	SET_BLOCK, // ブロック配置
	GAME_START, // ゲーム開始
	GAME_WAIT, // ゲーム監視
	MISS, // ミス処理
	STAGE_CLEAR, // ステージクリア
	GAME_OVER, // ゲームオーバー
	GAME_CLEAR, // ゲームクリア
	CONTINUE_STATE = 10, // State継続
	NEXT_STATE, // 次ステートへ
	NEXT_GAME, // 次のゲームへ
	NEXT_MISS, // ミス
	NEXT_CLEAR, // ゲームクリア
};

class GameManager : public GameObject
{
private:
	const char* NUMBER_GRAPH_PATH = "data/Number/Number"; // 数値画像のファイル名

	static const int SCORE_X = 450;
	static const int SCORE_Y = 86;
private:
	GAME_STATE gameState; // Game State
	GAME_STATE ScoreWait();
	Score* score; // スコア情報
	int numberHandle[10]; // 数値
public:
	GameManager();
	~GameManager();
	void Update() override;
	void Draw() override;

	void AddPoint(int point) { score += point; }

private:
//	GAME_STATE Init(); // ゲームの初期設定
};