#include <cassert>
#include <math.h>
#include "Score.h"
// コンストラクタ
Score::Score()
{
	// 数値画像データの読み込み
	char fileName[100];
	for (int i = 0; i < 10; i++)
	{
		sprintf_s(fileName, NUMBER_GRAPH_PATH, i);
		numberHandle[i] = LoadGraph(fileName); // 数値
		assert(numberHandle[i] > 0);
	}
	score = 0;
}
// デストラクタ
Score::~Score()
{
	for (int i = 0; i < sizeof(numberHandle); i++)
	{
		DeleteGraph(numberHandle[i]);
	}
}
// スコアの表示
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