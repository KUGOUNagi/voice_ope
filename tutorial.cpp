#include "tutorial.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <math.h>
#include <string>
#include <fstream>
#include <sstream>
#define PI 3.1415926f

static int mImageHandle, Handle, bag;    //�摜�n���h���i�[�p�ϐ�
int bag_x = 280, speed = 2;

//������
void tutorial_Initialize() {
    mImageHandle = LoadGraph("img/backgraund.png");    //�摜�̃��[�h
    bag = LoadGraph("img/bag.png");
}

//�I������
void tutorial_Finalize() {
    DeleteGraph(mImageHandle);    //�摜�̉��
    //DeleteGraph(Handle);
    DeleteGraph(bag);
}
//�X�V
void tutorial_Update() {
    if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {//�G���^�[�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Game);//�V�[�����Q�[���ɕύX
    }
    if (Keyboard_Get(KEY_INPUT_RIGHT) != 0) { // �E�L�[��������Ă�����
        bag_x=bag_x+speed;                       // �E�ֈړ�
    }
    if (Keyboard_Get(KEY_INPUT_LEFT) != 0) { // �E�L�[��������Ă�����
        bag_x=bag_x-speed;                       // �E�ֈړ�
    }
}

//�`��
void tutorial_Draw() {
    DrawRotaGraph(320, 230, 0.9, 0.0, mImageHandle, FALSE);
    DrawRotaGraph(bag_x, 330, 0.7, 0.0, bag, TRUE);
    DrawString(0, 0, "�`���[�g���A����ʂł��B", GetColor(255, 255, 255));
    DrawString(0, 20, "�G���^�[�L�[�������ƃQ�[����ʂɈڂ�܂��B", GetColor(255, 255, 255));
    DrawFormatString(0, 40, GetColor(255, 255, 255), "%d", 5);
}