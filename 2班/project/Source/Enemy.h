#pragma once
#include "../Library/sceneBase.h"
#include "Vector2.h"

class Enemy : public GameObject {
public:
	Enemy();
	~Enemy();
	void Update() override;
	void Draw() override;
	int hImage;
	VECTOR2 position;
};