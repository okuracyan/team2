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
	int timer; // ŽžŠÔ‚ð‘ª‚é‚½‚ß
	int hImage; // ‰æ‘œ
	VECTOR2 position;
};