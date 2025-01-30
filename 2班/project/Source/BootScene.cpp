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
	SceneManager::ChangeScene("TITLE"); // �N�����I�������Title��\��
}

void BootScene::Draw()
{
}
