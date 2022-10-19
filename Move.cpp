#include "Move.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"
#include "ScoreClass.h"

static int mImageHandle;
Score score;

void Move_Initialize() {
	mImageHandle = LoadGraph("img/danzyon1.jpeg");    //�摜�̃��[�h
}
void Move_Finalize() {
}
//�X�V
void Move_Update() {
	if (CheckHitKey(KEY_INPUT_G) != 0) {//G�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Esc�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
	}
	if (CheckHitKey(KEY_INPUT_M) != 0) {//Esc�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
	}
}

//�`��
void Move_Draw() {
	score.c;
	score.print1();
	DrawRotaGraph(320, 230, 1, 0.0, mImageHandle, FALSE);
	DrawString(0, 20, "M�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
}