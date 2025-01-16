#pragma once
#include "../Library/gameObject.h"
/// <summary>
/// �^�C�g���V�[��
/// 
/// �^�C�g����\�����āA�L�[����������v���C�V�[���Ɉڍs����B
/// </summary>
class TitleScene : public SceneBase
{
private://	�^�C�g�����

	const char*  KEY_GRAPH_PATH= "data/image/Haikei2.png";		
	const char*  STERT_GRAPH_PATH= "data/image/���b�Z�[�W1_�����L��/���b�Z�[�W1_����/GAMESTERT.png";
	const char* TITLE_GRAPH_PATH = "data/image/Title.png";//	�^�C�g���摜�̃t�@�C����
	const char* START_SOUND_PATH = "data/sound/START.mp3";

	const int STERT_GRAPH_X = 370;			//	[GAMESTART]�\���ʒu(X)
	const int STERT_GRAPH_Y = 450;		//	[GAMESTART]�\���ʒu(Y)

	const float DRAW_STERT_WAIT = 1.0f;	//	[GAME START]�\���Ԋu(1.0sec)
	const int MAX_ALPHA = 255;			//	�ő�A���t�@�l


private:
	int bgHandle;			//	�摜�n���h��(�^�C�g�����)
	int pushStartHandle;		//	�摜�n���h��(GAMESTART)
	int alpha;				//	[GAME START]�̃A���t�@�l
	int ofset;				//	���Z����A���t�@�l
	int sound;//���ʉ�
	float DrawStertTimer;		//	�^�C�}�[


public:
	TitleScene();
	~TitleScene();
	void Update() override;
	void Draw() override;
	int hBGImageII;
};
