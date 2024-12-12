#pragma once
#include "../Library/GameObject.h"
#include "Vector2.h"
class Player : public GameObject{
public:
	Player();
	~Player();
	void Update();
	void Draw();
	VECTOR2 position;

	int hImage;
	bool IsBom;
	int bomImage;
	bool prevDushKey;

	int patternX;
	int patternY;
	float animTimer;

	bool dead;
};