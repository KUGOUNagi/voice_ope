#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"

const static int GAME_Y = 240;    //�u�Q�[���v������y�ʒu
const static int CONFIG_Y = 270;    //�u�ݒ�v������y�ʒu
const static int MOVE_Y = 300;

static int mImageHandle;    //�摜�n���h���i�[�p�ϐ�
int z = 550, sikaku1 = 0;
int sikaku[] = { 60,80,100,120,140 };

//������
void Config_Initialize() {
    mImageHandle = LoadGraph("img/danzyon.jpeg");    //�摜�̃��[�h
}

//�I������
void Config_Finalize() {
    DeleteGraph(mImageHandle);//�摜�̉��
}
typedef enum {
    eMenu_Game,        //�Q�[��
    eMenu_Config,    //�ݒ�
    eMenu_Move,

    eMenu_Num,        //�{���ڂ̐�
} eMenu;

static int NowSelect = eMenu_Game;    //���݂̑I�����(�����̓Q�[���I��)

//�X�V
void Config_Update() {
    if (Keyboard_Get(KEY_INPUT_DOWN) == 1) {//���L�[��������Ă�����
        NowSelect = (NowSelect + 1) % eMenu_Num;//�I����Ԃ��������
    }
    if (Keyboard_Get(KEY_INPUT_UP) == 1) {//��L�[��������Ă�����
        NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;//�I����Ԃ���グ��
    }

    if (CheckHitKey(KEY_INPUT_U) != 0) {//G�L�[��������Ă�����
        sikaku1--;//�V�[�����Q�[����ʂɕύX
    }
    if (CheckHitKey(KEY_INPUT_D) != 0) {//G�L�[��������Ă�����
        sikaku1++;//�V�[�����Q�[����ʂɕύX
    }
    if (CheckHitKey(KEY_INPUT_G) != 0) {//G�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Menu);//�V�[�����Q�[����ʂɕύX
    }
    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Esc�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
    }
}

//�`��
void Config_Draw() {
    DrawRotaGraph(320, 230, 1.5, 0.0, mImageHandle, FALSE);

    DrawString(0, 0, "�ݒ��ʂł��B", GetColor(255, 255, 255));
    DrawString(280, 200, "���x", GetColor(255, 255, 255));
    DrawString(280, 220, "��Փx", GetColor(255, 255, 255));
    DrawString(280, 240, "���邳", GetColor(255, 255, 255));
    DrawString(280, 260, "���[��", GetColor(255, 255, 255));
    //DrawString(280, 280, "�����", GetColor(255, 255, 255));
    int y = 0;
    switch (NowSelect) {//���݂̑I����Ԃɏ]���ď����𕪊�
    case eMenu_Game://�Q�[���I�𒆂Ȃ�
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
    //DrawString(0, 20, "Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
    DrawString(280, 300, "G�L�[�������ƃQ�[����ʂɈڍs���܂��B", GetColor(255, 255, 255));
}