#pragma once
#include "../Library/GameObject.h"

class Record : public GameObject {
public:
	Record();
	int score;
	void SetScore(int score) { this->score = score; }// スコアの登録
	void AddScore(int point) { score += point; } // スコアの加算

};