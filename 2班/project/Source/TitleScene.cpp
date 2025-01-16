#include "TitleScene.h"
#include <DxLib.h>
#include <cassert>
#include "../Utility.h"
#include "../Library/Time.h"

TitleScene::TitleScene()
{
	bgHandle = LoadGraph("data/image/Title.png");
	assert(bgHandle > 0);
	pushStartHandle= LoadGraph("data/image/���b�Z�[�W1_�����L��/���b�Z�[�W1_����/GAMESTERT.png");
	assert(pushStartHandle > 0);
	hBGImageII = LoadGraph("data/image/Haikei2.jpg");
	sound = LoadSoundMem(START_SOUND_PATH);
	//	[GAME START]�\���ݒ�̏�����
	DrawStertTimer = 0.0f;
	alpha = 0;
	ofset = (int)((float)MAX_ALPHA / DRAW_STERT_WAIT);
}

TitleScene::~TitleScene()
{
	DeleteGraph(hBGImageII);
	DeleteGraph(bgHandle);
	DeleteGraph(pushStartHandle);
}

void TitleScene::Update()
{
	//	�A���t�@�l�̌v�Z
	alpha += (int)(ofset * Time::DeltaTime());

	//	�O�t���[������̌o�ߎ��Ԃ��擾
	DrawStertTimer += Time::DeltaTime();
	//	��莞��(DRAW_STERT_WAIT)�o�߂�����A�A���t�@�l�̉��Z�E���Z��؂肩����
	if (DrawStertTimer >= DRAW_STERT_WAIT)
	{
		ofset = -ofset;;
		DrawStertTimer = 0.0f;
	}

	//	[SPACE]�L�[�������ꂽ��v���C�V�[����
	if (KeyUtility::CheckTrigger(KEY_INPUT_SPACE))
	{
		SceneManager::ChangeScene("PLAY");
		PlaySoundFile(START_SOUND_PATH, DX_PLAYTYPE_NORMAL);
	}

}


void TitleScene::Draw()
{
	DrawGraph(0, 0, hBGImageII, TRUE);
	//	�^�C�g�����
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//	�ʏ�`��
	DrawGraph(0, 0, bgHandle, TRUE);
	//	[GAME START]
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);	//	�A���t�@�u�����f�B���O
	DrawGraph(STERT_GRAPH_X, STERT_GRAPH_Y, pushStartHandle, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//	�ʏ�`��
}
