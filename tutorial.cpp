#include "tutorial.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <math.h>
#include <string>
#include <fstream>
#include <sstream>
#define PI 3.1415926f

static int mImageHandle, Handle, candy, cookie;    //�摜�n���h���i�[�p�ϐ�

//������
void tutorial_Initialize() {
    mImageHandle = LoadGraph("img/backgraund.png");    //�摜�̃��[�h
    candy = LoadGraph("img/candy.png");
    cookie = LoadGraph("img/cookie.png");
}

//�I������
void tutorial_Finalize() {
    DeleteGraph(mImageHandle);    //�摜�̉��
    //DeleteGraph(Handle);
    DeleteGraph(candy);
    DeleteGraph(cookie);
}
//�X�V
void tutorial_Update() {
    if (CheckHitKey(KEY_INPUT_B) != 0) {//Esc�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Game);//�V�[�����Q�[���ɕύX
    }

}

//�`��
void tutorial_Draw() {
    DrawRotaGraph(320, 230, 0.9, 0.0, mImageHandle, FALSE);
    DrawString(0, 0, "�`���[�g���A����ʂł��B", GetColor(255, 255, 255));
    DrawString(0, 20, "B�L�[�������ƃQ�[����ʂɈڂ�܂��B", GetColor(255, 255, 255));
    DrawFormatString(0, 40, GetColor(255, 255, 255), "%d", 5);
    //DrawFormatString(300, 0, GetColor(255, 255, 255), "��_%d", ryou);
    //DrawFormatString(350, 0, GetColor(255, 255, 255), "��_%d", ka);
    //DrawFormatString(400, 0, GetColor(255, 255, 255), "�s��_%d", fuka);
}