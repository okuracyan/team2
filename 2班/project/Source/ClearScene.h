#pragma once
#pragma once
#pragma once
#include "../Library/gameObject.h"

class ClearScene : public SceneBase
{
private://�Q�[���N���A

	const char* KEY_GRAPH_PATH = "data/image/Haikei2.png";
	const char* CLEAR_GRAPH_PATH = "data/image/���b�Z�[�W1_�����L��/���b�Z�[�W1_����/CONGRATULATIONS.png";			//	]�摜�̃t�@�C����
	const char* SCORE_GRAPH_PATH = "data/image/���b�Z�[�W1_�����L��/���b�Z�[�W1_����/SCORE.png";
	const char* SPACE_GRAPH_PATH = "data/imag/PUSHSPACE.png";

	const int CLEAR_GRAPH_X = 370;			//	[GAMEOVER]�\���ʒu(X)
	const int CLEAR_GRAPH_Y = 450;		//	[GAMEOVER]�\���ʒu(Y)
	const int SPACE_GRAPH_X = 0;			//	[]�\���ʒu(X)
	const int SPACE_GRAPH_Y = 650;		//	[]�\���ʒu(Y)

private:
	int bgHandle;			//	�摜�n���h��(�^�C�g�����)
	int ScoreHandle;		//	�摜�n���h��(Score)
	int pushSpaceHandle;
public:
	ClearScene();
	~ClearScene();
	void Update() override;
	void Draw() override;
	int hBGImageII;
};