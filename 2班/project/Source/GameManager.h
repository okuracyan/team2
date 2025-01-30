#pragma once
#include "../Library/GameObject.h"
#include "../Utility.h"
#include "Player.h"
#include "Score.h"
#include "Stage.h"


enum class GAME_STATE
{
	INIT = 0, // �Q�[���̏����ݒ�
	SET_BLOCK, // �u���b�N�z�u
	GAME_START, // �Q�[���J�n
	GAME_WAIT, // �Q�[���Ď�
	MISS, // �~�X����
	STAGE_CLEAR, // �X�e�[�W�N���A
	GAME_OVER, // �Q�[���I�[�o�[
	GAME_CLEAR, // �Q�[���N���A
	CONTINUE_STATE = 10, // State�p��
	NEXT_STATE, // ���X�e�[�g��
	NEXT_GAME, // ���̃Q�[����
	NEXT_MISS, // �~�X
	NEXT_CLEAR, // �Q�[���N���A
};

class GameManager : public GameObject
{
private:
	const char* NUMBER_GRAPH_PATH = "data/Number/Number"; // ���l�摜�̃t�@�C����

	static const int SCORE_X = 450;
	static const int SCORE_Y = 86;
private:
	GAME_STATE gameState; // Game State
	GAME_STATE ScoreWait();
	Score* score; // �X�R�A���
	int numberHandle[10]; // ���l
public:
	GameManager();
	~GameManager();
	void Update() override;
	void Draw() override;

	void AddPoint(int point) { score += point; }

private:
//	GAME_STATE Init(); // �Q�[���̏����ݒ�
};