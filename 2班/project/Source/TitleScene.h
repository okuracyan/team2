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
	const char* TITLE_GRAPH_PATH = "data/image/Haikei2.png";		//	�^�C�g���摜�̃t�@�C����
	const char* KEY_GRAPH_PATH = "data/image/���b�Z�[�W1_����/GAMESTERT.png";			//	]�摜�̃t�@�C����
	const char* START_GRAPH_PATH= "data/image/Title.png";

	const int KEY_GRAPH_X = 19;			//	[]�\���ʒu(X)
	const int KEY_GRAPH_Y = 600;		//	[PUSH SPACE KEY]�\���ʒu(Y)

	const float DRAW_KEY_WAIT = 1.0f;	//	[PUSH SPACE KEY]�\���Ԋu(1.0sec)
	const int MAX_ALPHA = 255;			//	�ő�A���t�@�l

private:
	int bgHandle;			//	�摜�n���h��(�^�C�g�����)
	int pushKeyHandle;		//	�摜�n���h��(PUSH SPACE KEY)
	int alpha;				//	[PUSH SPACE KEY]�̃A���t�@�l
	int ofset;				//	���Z����A���t�@�l
	float DrawKeyTimer;		//	�^�C�}�[

public:
	TitleScene();
	~TitleScene();
	void Update() override;
	void Draw() override;
};
