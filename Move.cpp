#include "Move.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"

static int kirito, mImageHandle;

void Move_Initialize() {
	kirito = LoadGraph("img/kirito02.png");
	mImageHandle = LoadGraph("img/danzyon1.jpeg");    //�摜�̃��[�h
}
void Move_Finalize() {
	DeleteGraph(kirito);
}
//�X�V
void Move_Update() {
	if (CheckHitKey(KEY_INPUT_G) != 0) {//G�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Esc�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
	}
	if (CheckHitKey(KEY_INPUT_F) != 0) {//Esc�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
	}
}

//�`��
void Move_Draw() {
	DrawRotaGraph(320, 230, 1, 0.0, mImageHandle, FALSE);
	DrawString(0, 20, "G�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
	DrawRotaGraph(300, 255, 1, 0.0, kirito, TRUE);
}