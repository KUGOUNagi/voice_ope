/*#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"

const static int aa, bb, cc, dd, ee;
static int mImageHandle;    //�摜�n���h���i�[�p�ϐ�
int z = 550, sikaku1 = 0;
int sikaku[] = { 60,80,100,120,140 };
//������
void Config_Initialize() {
    mImageHandle = LoadGraph("img/char.png");//�摜�̃��[�h
}

//�I������
void Config_Finalize() {
    DeleteGraph(mImageHandle);//�摜�̉��
}
//�X�V
void Config_Update() {
    if (CheckHitKey(KEY_INPUT_U) != 0) {//G�L�[��������Ă�����
        sikaku1--;//�V�[�����Q�[����ʂɕύX
    }
    if (CheckHitKey(KEY_INPUT_D) != 0) {//G�L�[��������Ă�����
        sikaku1++;//�V�[�����Q�[����ʂɕύX
    }
    if (CheckHitKey(KEY_INPUT_G) != 0) {//G�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
    }
    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Esc�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
    }
}

//�`��
void Config_Draw() {

    DrawString(0, 0, "�ݒ��ʂł��B", GetColor(255, 255, 255));
    DrawString(100, 60, "��������2000", GetColor(255, 255, 255));
    DrawString(100, 80, "�H���m��", GetColor(255, 255, 255));
    DrawString(100, 100, "���炩���", GetColor(255, 255, 255));
    DrawString(100, 120, "�V���i��", GetColor(255, 255, 255));
    DrawString(100, 140, "�}�t�B�A", GetColor(255, 255, 255));
    DrawString(50, sikaku[sikaku1], "��", GetColor(255, 255, 255));
    DrawString(0, 20, "Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
    DrawString(0, 40, "G�L�[�������ƃQ�[����ʂɈڍs���܂��B", GetColor(255, 255, 255));
}*/