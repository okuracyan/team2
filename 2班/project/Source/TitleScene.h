#pragma once
#include "../Library/gameObject.h"
/// <summary>
/// �^�C�g���V�[��
/// 
/// �^�C�g����\�����āA�L�[����������v���C�V�[���Ɉڍs����B
/// </summary>
class TitleScene : public SceneBase
{
private:
	const char* TITLE_GRAPH_PATH = "data/Graph/Title.png";		//	�^�C�g���摜�̃t�@�C����
	const char* KEY_GRAPH_PATH = "data/Graph/Key.png";			//	[PUSH SPACE KEY]�摜�̃t�@�C����
	const char* START_SOUND_PATH = "data/Sound/Start.mp3";		//	�X�^�[�g�T�E���h�̃t�@�C����

	const int KEY_GRAPH_X = 19;			//	[PUSH SPACE KEY]�\���ʒu(X)
	const int KEY_GRAPH_Y = 600;		//	[PUSH SPACE KEY]�\���ʒu(Y)

	const float DRAW_KEY_WAIT = 1.0f;	//	[PUSH SPACE KEY]�\���Ԋu(1.0sec)
	const int MAX_ALPHA = 255;			//	�ő�A���t�@�l

private:
	int bgHandle;			//	�摜�n���h��(�^�C�g�����)
	int pushKeyHandle;		//	�摜�n���h��(PUSH SPACE KEY)
	int alpha;				//	[PUSH SPACE KEY]�̃A���t�@�l

public:
	TitleScene();
	~TitleScene();
	void Update() override;
	void Draw() override;
};
