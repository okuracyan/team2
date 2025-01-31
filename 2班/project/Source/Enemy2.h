#pragma once
#include "../Library/gameObject.h"
#include "Vector2.h"

class Enemy2 : public GameObject {
public:
	Enemy2();
	~Enemy2();
	void Update() override;
	void Draw() override;
	int frameCounter;
	float timer; // 時間を測るため
	int hImage; // 画像
	bool dead;
	VECTOR2 position;
};