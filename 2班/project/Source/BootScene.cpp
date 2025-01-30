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
	SceneManager::ChangeScene("TITLE"); // 起動が終わったらTitleを表示
}

void BootScene::Draw()
{
}
