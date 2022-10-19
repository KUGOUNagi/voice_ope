#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"

const static int SPEED_Y = 200;    //�u�Q�[���v������y�ʒu
const static int DIFF_Y = 220;    //�u�ݒ�v������y�ʒu
const static int MOVE_Y = 240;
const static int RULE_Y = 260;

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
    eMenu_Speed,        //�Q�[��
    eMenu_Diff,    //�ݒ�
    eMenu_Move,
    eMenu_Rule,

    eMenu_Num,        //�{���ڂ̐�
} eMenu;

static int NowSelect = eMenu_Speed;    //���݂̑I�����(�����̓Q�[���I��)

//�X�V
void Config_Update() {
    if (Keyboard_Get(KEY_INPUT_DOWN) == 1) {//���L�[��������Ă�����
        NowSelect = (NowSelect + 1) % eMenu_Num;//�I����Ԃ��������
    }
    if (Keyboard_Get(KEY_INPUT_UP) == 1) {//��L�[��������Ă�����
        NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;//�I����Ԃ���グ��
    }

    if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {//�G���^�[�L�[�������ꂽ��
        switch (NowSelect) {//���ݑI�𒆂̏�Ԃɂ���ď����𕪊�
        case eMenu_Speed://�Q�[���I�𒆂Ȃ�
            SceneMgr_ChangeScene(eScene_Menu);//�V�[�����Q�[����ʂɕύX
            break;
        case eMenu_Diff://�ݒ�I�𒆂Ȃ�
            SceneMgr_ChangeScene(eScene_Menu);//�V�[����ݒ��ʂɕύX
            break;
        case eMenu_Move://�Q�[���I�𒆂Ȃ�
            SceneMgr_ChangeScene(eScene_Menu);//�V�[�����Q�[����ʂɕύX
            break;
        case eMenu_Rule://�Q�[���I�𒆂Ȃ�
            SceneMgr_ChangeScene(eScene_Menu);//�V�[�����Q�[����ʂɕύX
            break;
        }
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
    case eMenu_Speed://�Q�[���I�𒆂Ȃ�
        y = SPEED_Y;    //�Q�[���̍��W���i�[
        break;
    case eMenu_Diff://�ݒ�I�𒆂Ȃ�
        y = DIFF_Y;    //�ݒ�̍��W���i�[
        break;
    case eMenu_Move://�ݒ�I�𒆂Ȃ�
        y = MOVE_Y;    //�ݒ�̍��W���i�[
        break;
    case eMenu_Rule://�ݒ�I�𒆂Ȃ�
        y = RULE_Y;    //�ݒ�̍��W���i�[
        break;
    }
    DrawString(250, y, "��", GetColor(255, 255, 255));
    //DrawString(0, 20, "Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
    DrawString(280, 300, "G�L�[�������ƃQ�[����ʂɈڍs���܂��B", GetColor(255, 255, 255));
}