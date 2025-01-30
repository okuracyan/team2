#include <cassert>
#include "GameManager.h"


// �R���X�g���N�^
GameManager::GameManager()
{
	// ���l�摜�f�[�^�̓ǂݍ���
	char fileName[100];
	for (int i = 0; i < 10; i++)
	{
		sprintf_s(fileName, "%s_%d.png", NUMBER_GRAPH_PATH, i);
		numberHandle[i] = LoadGraph(fileName); // ���l
		assert(numberHandle[i] > 0);
	}
	// GameState�̏�����
	gameState = GAME_STATE::INIT;
}
// �f�X�g���N�^
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
	// �Q�[���X�e�[�g
	switch (gameState)
	{
		// �Q�[���̏����ݒ�
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
		// �Q�[���̏����ݒ�
	case GAME_STATE::INIT:
		DrawString(0, 700, "State:Init", GetColor(255, 255, 255));
		break;
		// �u���b�N�z�u

	}

	score->DispScore(SCORE_X, SCORE_Y);
}

GAME_STATE GameManager::ScoreWait()
{
//		score->AddScore();
	return gameState;
}
