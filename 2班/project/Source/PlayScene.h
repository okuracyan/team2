#pragma once
#include "../Library/SceneBase.h"

class PlayScene : public SceneBase
{
public:
	PlayScene();
	~PlayScene();
	void Update() override;
	void Draw() override;
	int hBGImage;
	int hBGImageI;
	int hBGImageII;
	int hImage;
};
