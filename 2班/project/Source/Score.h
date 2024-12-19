#pragma once
#include <Dxlib.h>
class Score
{
private:
	const char* NUMBER_GRAPH_PATH = "data/Graph/Number/number_%d.png";
	// ���l�摜�̃t�@�C����
	static const int NUMBER_WIDTH = 32; // ���l�̕�
	static const int MAX_DIGITS = 10; // �ő包��()
private:
	int score;
	int numberHandle[10]; // ���l�摜�n���h��
public:
	Score();
	~Score();
	void DispScore(int x, int y); // �X�R�A�̕\��
	void SetScore(int score) { this->score = score; }// �X�R�A�̓o�^
	void AddScore(int point) { score += point; } // �X�R�A�̉��Z
};
