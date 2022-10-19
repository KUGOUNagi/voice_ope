#include "Score.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <math.h>
#include <string>
#include <fstream>
#include <sstream>
#define PI 3.1415926f

static int mImageHandle, Handle, candy, cookie,sound;    //�摜�n���h���i�[�p�ϐ�

//������
void Score_Initialize() {
    mImageHandle = LoadGraph("img/backgraund.png");    //�摜�̃��[�h
    candy = LoadGraph("img/candy.png");
    cookie = LoadGraph("img/cookie.png");
}

//�I������
void Score_Finalize() {
    DeleteGraph(mImageHandle);    //�摜�̉��
    //DeleteGraph(Handle);
    DeleteGraph(candy);
    DeleteGraph(cookie);
}
//�X�V
void Score_Update() {
    if (CheckHitKey(KEY_INPUT_Z) !=0) {//Esc�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Menu);//�V�[�����Q�[���ɕύX
    }

}

//�`��
void Score_Draw() {
    DrawRotaGraph(320, 230, 0.9, 0.0, mImageHandle, FALSE);
    DrawString(0, 0, "�X�R�A��ʂł��B", GetColor(255, 255, 255));
    DrawString(0, 20, "Z�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
    DrawFormatString(300, 300, GetColor(255, 255, 255), "%d", 1073741824);//�I�[�o�[�t���[2^30

}