#include <cassert>
#include <math.h>
#include "Score.h"
// �R���X�g���N�^
Score::Score()
{
	// ���l�摜�f�[�^�̓ǂݍ���
	char fileName[100];
	for (int i = 0; i < 10; i++)
	{
		sprintf_s(fileName, NUMBER_GRAPH_PATH, i);
		numberHandle[i] = LoadGraph(fileName); // ���l
		assert(numberHandle[i] > 0);
	}
	score = 0;
}
// �f�X�g���N�^
Score::~Score()
{
	for (int i = 0; i < sizeof(numberHandle); i++)
	{
		DeleteGraph(numberHandle[i]);
	}
}
// �X�R�A�̕\��
void Score::DispScore(int x, int y)
{
	int numberX, numberY;
	char numberText[MAX_DIGITS + 1];
	int numCount = sprintf_s(numberText, "%d", score);
	int textIndex = 0;
	while (numCount - 1 >= 0)
	{
		DrawGraph(x - (textIndex * NUMBER_WIDTH), y,
			numberHandle[int(numberText[numCount - 1] - '0')], TRUE);
		textIndex++;
		numCount--;
	}
}