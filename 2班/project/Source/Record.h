#pragma once
#include "../Library/GameObject.h"

class Record : public GameObject {
public:
	Record();
	int score;
	void SetScore(int score) { this->score = score; }// �X�R�A�̓o�^
	void AddScore(int point) { score += point; } // �X�R�A�̉��Z

};