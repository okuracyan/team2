#include "BootScene.h"
#include "../Library/SceneManager.h"
#include "Record.h"

BootScene::BootScene()
{
	Instantiate<Record>();
}

BootScene::~BootScene()
{
}

void BootScene::Update()
{
	SceneManager::ChangeScene("TITLE"); // ‹N“®‚ªI‚í‚Á‚½‚çTitle‚ğ•\¦
}

void BootScene::Draw()
{
}
