#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"

const static int GAME_Y = 240;    //�u�Q�[���v������y�ʒu
const static int CONFIG_Y = 270;    //�u�ݒ�v������y�ʒu
const static int MOVE_Y = 300;

static int mImageHandle;    //�摜�n���h���i�[�p�ϐ�

//������
void Menu_Initialize() {
    mImageHandle = LoadGraph("img/danzyon1.jpeg");    //�摜�̃��[�h
}

//�I������
void Menu_Finalize() {
    DeleteGraph(mImageHandle);    //�摜�̉��
}
typedef enum {
    eMune_tutorial,
    //eMenu_Game,        //�Q�[��
    eMenu_Config,    //�ݒ�
    eMenu_Move,

    eMenu_Num,        //�{���ڂ̐�
} eMenu;

static int NowSelect = eMune_tutorial;    //���݂̑I�����(�����̓Q�[���I��)

//�X�V
void Menu_Update() {
    if (Keyboard_Get(KEY_INPUT_DOWN) == 1) {//���L�[��������Ă�����
        NowSelect = (NowSelect + 1) % eMenu_Num;//�I����Ԃ��������
    }
    if (Keyboard_Get(KEY_INPUT_UP) == 1) {//��L�[��������Ă�����
        NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;//�I����Ԃ���グ��
    }
    if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {//�G���^�[�L�[�������ꂽ��
        switch (NowSelect) {//���ݑI�𒆂̏�Ԃɂ���ď����𕪊�
        case eMune_tutorial://�Q�[���I�𒆂Ȃ�
            SceneMgr_ChangeScene(eScene_tutorial);//�V�[�����Q�[����ʂɕύX
            break;
        case eMenu_Config://�ݒ�I�𒆂Ȃ�
            SceneMgr_ChangeScene(eScene_Config);//�V�[����ݒ��ʂɕύX
            break;
        case eMenu_Move://�Q�[���I�𒆂Ȃ�
            SceneMgr_ChangeScene(eScene_Move);//�V�[�����Q�[����ʂɕύX
            break;
        }
    }
}

//�`��
void Menu_Draw() {
    //DrawGraph(0, 0, mImageHandle, FALSE);
    DrawRotaGraph(320, 230, 1.7, 0.0, mImageHandle, FALSE);
    SetFontSize(50);
    DrawString(140, 70, "VOICE OPERATER", GetColor(255, 255, 255));
    SetFontSize(16);
    DrawString(170, 170, "���ő��삵�ăn�C�X�R�A��_�����I�I", GetColor(255, 255, 255));
    DrawString(280, GAME_Y, "�Q�[�����n�߂�", GetColor(255, 255, 255));
    DrawString(280, CONFIG_Y, "�ݒ�", GetColor(255, 255, 255));
    DrawString(280, MOVE_Y, "���[������", GetColor(255, 255, 255));
    int y = 0;
    switch (NowSelect) {//���݂̑I����Ԃɏ]���ď����𕪊�
    case eMune_tutorial://�Q�[���I�𒆂Ȃ�
        y = GAME_Y;    //�Q�[���̍��W���i�[
        y = GAME_Y;    //�Q�[���̍��W���i�[
        break;
    case eMenu_Config://�ݒ�I�𒆂Ȃ�
        y = CONFIG_Y;    //�ݒ�̍��W���i�[
        break;
    case eMenu_Move://�ݒ�I�𒆂Ȃ�
        y = MOVE_Y;    //�ݒ�̍��W���i�[
        break;
    }
    DrawString(250, y, "��", GetColor(255, 255, 255));
}