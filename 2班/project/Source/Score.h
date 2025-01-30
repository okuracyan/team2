#pragma once
#include "../Library/GameObject.h"
class Score: public GameObject
{
private:
	const char* NUMBER_GRAPH_PATH = "data/image/Number/number_%d.png";
	// 数値画像のファイル名
	static const int NUMBER_WIDTH = 53; // 数値の幅
	static const int MAX_DIGITS = 10; // 最大桁数()
private:
	int numberHandle[10]; // 数値画像ハンドル
public:
	Score();
	~Score();
	void Draw() override;
	void DispScore(int x, int y); // スコアの表示
};
