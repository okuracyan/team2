#include <cassert>
#include "GameManager.h"


// コンストラクタ
GameManager::GameManager()
{
	// 数値画像データの読み込み
	char fileName[100];
	for (int i = 0; i < 10; i++)
	{
		sprintf_s(fileName, "%s_%d.png", NUMBER_GRAPH_PATH, i);
		numberHandle[i] = LoadGraph(fileName); // 数値
		assert(numberHandle[i] > 0);
	}
	// GameStateの初期化
	gameState = GAME_STATE::INIT;
}
// デストラクタ
GameManager::~GameManager()
{
	for (int i = 0; i < 10; i++)
	{
		DeleteGraph(numberHandle[i]);
	}
	delete(score);
}

void GameManager::Update()
{
	// ゲームステート
	switch (gameState)
	{
		// ゲームの初期設定
	case GAME_STATE::INIT:
//		if (Init() == GAME_STATE::NEXT_STATE)
		{
			gameState = GAME_STATE::SET_BLOCK;
		}
		break;
	}
}

void GameManager::Draw()
{
	switch (gameState)
	{
		// ゲームの初期設定
	case GAME_STATE::INIT:
		DrawString(0, 700, "State:Init", GetColor(255, 255, 255));
		break;
		// ブロック配置

	}

	score->DispScore(SCORE_X, SCORE_Y);
}

GAME_STATE GameManager::ScoreWait()
{
//		score->AddScore();
	return gameState;
}
