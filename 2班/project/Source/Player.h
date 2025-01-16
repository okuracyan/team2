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

<<<<<<< HEAD
	const char* START_SOUND_PATH = "data/sound/BAKUHATU.mp3";

=======
	int ClarhImage;
>>>>>>> 9d1a53739ff806b6c4e5f0f306e322d043a575b9
	int hImage;
	bool IsBom;
	int bomImage;
	bool prevDushKey;
	int sound;

	int patternX;
	int patternY;
	float animTimer;

	bool dead;
};