#include "TitleScene.h"
#include <DxLib.h>
#include <cassert>
#include "../Utility.h"

TitleScene::TitleScene()
{
	bgHandle = LoadGraph(TITLE_GRAPH_PATH);
	assert(bgHandle > 0);
	pushKeyHandle = LoadGraph(KEY_GRAPH_PATH);
	assert(pushKeyHandle > 0);
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{
	//	�A���t�@�l�̌v�Z
	alpha += (int)(ofset * Time::DeltaTime());

	//	�O�t���[������̌o�ߎ��Ԃ��擾
	DrawKeyTimer += Time::DeltaTime();
	//	��莞��(DRAW_KEY_WAIT)�o�߂�����A�A���t�@�l�̉��Z�E���Z��؂肩����
	if (DrawKeyTimer >= DRAW_KEY_WAIT)
	{
		ofset = -ofset;
		DrawKeyTimer = 0.0f;
	}

	//	[SPACE]�L�[�������ꂽ��v���C�V�[����
	if (KeyUtility::CheckTrigger(KEY_INPUT_SPACE))
	{
		//	�T�E���h���I������܂ő҂�
		//PlaySoundFile(START_SOUND_PATH, DX_PLAYTYPE_NORMAL);

		SceneManager::ChangeScene("PlayScene");
	}

	//	[ESC]�L�[�������ꂽ��Q�[���I��
	if (KeyUtility::CheckTrigger(KEY_INPUT_ESCAPE))
	{
		SceneManager::Exit();
	}
}


void TitleScene::Draw()
{
	//	[PUSH SPACE KEY]
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);	//	�A���t�@�u�����f�B���O
	DrawGraph(KEY_GRAPH_X, KEY_GRAPH_Y, pushKeyHandle, TRUE);
}
