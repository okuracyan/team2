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
	int timer; // ���Ԃ𑪂邽��
	int hImage; // �摜
	VECTOR2 position;
};