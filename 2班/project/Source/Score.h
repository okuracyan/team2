#pragma once
#include <Dxlib.h>
class Score
{
private:
	const char* NUMBER_GRAPH_PATH = "data/Graph/Number/number_%d.png";
	// 数値画像のファイル名
	static const int NUMBER_WIDTH = 32; // 数値の幅
	static const int MAX_DIGITS = 10; // 最大桁数()
private:
	int score;
	int numberHandle[10]; // 数値画像ハンドル
public:
	Score();
	~Score();
	void DispScore(int x, int y); // スコアの表示
	void SetScore(int score) { this->score = score; }// スコアの登録
	void AddScore(int point) { score += point; } // スコアの加算
};
