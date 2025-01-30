#pragma once
#include "../Library/GameObject.h"
class Score: public GameObject
{
private:
	const char* NUMBER_GRAPH_PATH = "data/image/Number/number_%d.png";
	// ���l�摜�̃t�@�C����
	static const int NUMBER_WIDTH = 53; // ���l�̕�
	static const int MAX_DIGITS = 10; // �ő包��()
private:
	int numberHandle[10]; // ���l�摜�n���h��
public:
	Score();
	~Score();
	void Draw() override;
	void DispScore(int x, int y); // �X�R�A�̕\��
};
