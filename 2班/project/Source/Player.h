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


	const char* START_SOUND_PATH = "data/sound/BAKUHATU.mp3";
	const char* GOAL_SOUND_PATH = "data/sound/GOAL.mp3";

	int ClarhImage; 
	int hImage;
	bool IsBom;
	bool numimage;
	int bomImage;
	bool prevDushKey;
	int sound1;
	int sound2;

	int patternX;
	int patternY;
	float animTimer;

	bool dead;
	bool goal;
};