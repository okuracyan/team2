#include "TitleScene.h"
#include <DxLib.h>
#include <cassert>
#include "../Utility.h"

TitleScene::TitleScene()
{
	bgHandle = LoadGraph("data/image/Title.png");
	assert(bgHandle > 0);
	pushKeyHandle= LoadGraph("data/image/.png");
	
	//	[GAME START]�\���ݒ�̏�����
	DrawKeyTimer = 0.0f;
	alpha = 0;
	ofset = (int)((float)MAX_ALPHA / DRAW_KEY_WAIT);
}

TitleScene::~TitleScene()
{
	DeleteGraph(bgHandle);
	DeleteGraph(pushKeyHandle);
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
		ofset = -ofset;;
		DrawKeyTimer = 0.0f;
	}

	//	[SPACE]�L�[�������ꂽ��v���C�V�[����
	if (KeyUtility::CheckTrigger(KEY_INPUT_SPACE))
	{
		SceneManager::ChangeScene("PLAY");
	}
}


void TitleScene::Draw()
{
	//	�^�C�g�����
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//	�ʏ�`��
	DrawGraph(0, 0, bgHandle, TRUE);
	//	[GAME START]
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);	//	�A���t�@�u�����f�B���O
	DrawGraph(KEY_GRAPH_X, KEY_GRAPH_Y, pushKeyHandle, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//	�ʏ�`��
}
