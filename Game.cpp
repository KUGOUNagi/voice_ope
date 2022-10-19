#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <math.h>
#include <string>
#include <fstream>
#include <sstream>
#define PI 3.1415926f

static int mImageHandle, Handle, sounds, candy, cookie, bag;    //�摜�n���h���i�[�p�ϐ�
int y = 0, hantei = 3, interval = 100, bpm = 30, speeds = 2, bags_x = 280;
FILE* fp;

int a[] = { 0,0,0,1,0,2,0,0,0,1,0,1,0,2,0,0,0,1,0,1,0,
2,0,1,0,2,0,1,0,2,0,0,0,2,0,1,0,0,0,2,0,2,0,1,0,0,0,1,
0,2,0,1,0,2,0,1,0,1,0,2,0,0,0,1,0,2,0,0,0,1,0,1,0,2,0,
0,0,1,0,1,0,2,0,1,0,2,0,1,0,2,0,0,0,2,0,1,0,0,0,2,0,2,
0,1,0,0,0,1,0,2,0,1,0,2,0,1,0,1,0,2,0,0,0,1,0,2,0,0,0,
1,0,1,0,2,0,0,0,1,0,1,0,2,0,1,0,2,0,1,0,2,0,0,0,2,0,1,
0,0,0,2,0,2,0,1,0,0,0,1,0,2,0,1,0,2,0,1,0,1,0,2,0,0,0,
1,0,2,0,0,0,1,0,1,0,2,0,0,0,1,0,1,0,2,0,1,0,2,0,1,0,2,
0,0,0,2,0,1,0,0,0,2,0,2,0,1,0,0,0,1,0,2,0,1,0,2,0,1,0,1,0,2, };//���Z�b�g�p�̔z��

int reen[] = { 0,0,0,1,0,2,0,0,0,1,0,1,0,2,0,0,0,1,0,1,0,
2,0,1,0,2,0,1,0,2,0,0,0,2,0,1,0,0,0,2,0,2,0,1,0,0,0,1,
0,2,0,1,0,2,0,1,0,1,0,2,0,0,0,1,0,2,0,0,0,1,0,1,0,2,0,
0,0,1,0,1,0,2,0,1,0,2,0,1,0,2,0,0,0,2,0,1,0,0,0,2,0,2,
0,1,0,0,0,1,0,2,0,1,0,2,0,1,0,1,0,2,0,0,0,1,0,2,0,0,0,
1,0,1,0,2,0,0,0,1,0,1,0,2,0,1,0,2,0,1,0,2,0,0,0,2,0,1,
0,0,0,2,0,2,0,1,0,0,0,1,0,2,0,1,0,2,0,1,0,1,0,2,0,0,0,
1,0,2,0,0,0,1,0,1,0,2,0,0,0,1,0,1,0,2,0,1,0,2,0,1,0,2,
0,0,0,2,0,1,0,0,0,2,0,2,0,1,0,0,0,1,0,2,0,1,0,2,0,1,0,1,0,2, };//���[���̔z��

int fumen[] = { 0,0,0,1,0,2,0,0,0,1,0,1,0,2,0,0,0,1,0,
1,0,2,0,1,0,2,0,1,0,2,0,0,0,2,0,1,0,0,0,2,0,2,0,1,0,0,
0,1,0,2,0,1,0,2,0,1,0,1,0,2,0,0,0,1,0,2,0,0,0,1,0,1,0,
2,0,0,0,1,0,1,0,2,0,1,0,2,0,1,0,2,0,0,0,2,0,1,0,0,0,2,
0,2,0,1,0,0,0,1,0,2,0,1,0,2,0,1,0,1,0,2,0,0,0,1,0,2,0,
0,0,1,0,1,0,2,0,0,0,1,0,1,0,2,0,1,0,2,0,1,0,2,0,0,0,2,
0,1,0,0,0,2,0,2,0,1,0,0,0,1,0,2,0,1,0,2,0,1,0,1,0,2,0,
0,0,1,0,2,0,0,0,1,0,1,0,2,0,0,0,1,0,1,0,2,0,1,0,2,0,1,
0,2,0,0,0,2,0,1,0,0,0,2,0,2,0,1,0,0,0,1,0,2,0,1,0,2,0,1,0,1,0,2, };//�摜�̔z��

//������
void Game_Initialize() {
    sounds = LoadSoundMem("sound/music.wav");
    mImageHandle = LoadGraph("img/backgraund.png");    //�摜�̃��[�h
    candy = LoadGraph("img/candy.png");
    cookie = LoadGraph("img/cookie.png");
    bag = LoadGraph("img/bag.png");
    PlaySoundMem(sounds, DX_PLAYTYPE_BACK,TRUE);//���y
}

//�I������
void Game_Finalize() {
    DeleteGraph(mImageHandle);    //�摜�̉��
    DeleteGraph(candy);
    DeleteGraph(cookie);
    DeleteGraph(bag);
    DeleteSoundMem(sounds);
}
//�X�V
void Game_Update() {
    for (int i = 0; i < 1; i++) {
        y = y + (interval / bpm);
    }

    for (int j = 0; j < (sizeof(a) / sizeof(a[0])); j++) {
        if (fumen[j] == 1 || fumen[j] == 3) {//�z����̐����ɂ���ďo�͂�ύX
            fumen[j] = candy;
        }
        if (fumen[j] == 2 || fumen[j] == 4) {
            fumen[j] = cookie;
        }
    }

    if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {//�G���^�[�L�[��������Ă�����
        for (int i = 0; i < (sizeof(a) / sizeof(a[0])); i++) {//���Z�b�g
            fumen[i] = a[i];
            reen[i] = a[i];
        }
        StopSoundMem(sounds);
        bags_x = 280;
        y = 0;
        Game_Initialize();//���Z�b�g
        SceneMgr_ChangeScene(eScene_Score);//�V�[�������j���[�ɕύX
    }

    if (Keyboard_Get(KEY_INPUT_RIGHT) != 0) { // �E�L�[��������Ă�����
        bags_x = bags_x + speeds;                       // �E�ֈړ�
    }
    if (Keyboard_Get(KEY_INPUT_LEFT) != 0) { // �E�L�[��������Ă�����
        bags_x = bags_x - speeds;                       // �E�ֈړ�
    }


}

//�`��
void Game_Draw() {
    DrawRotaGraph(320, 230, 0.9, 0.0, mImageHandle, FALSE);//�w�i
    
    for (int i = 0; i < (sizeof(a) / sizeof(a[0])); i++) {
        if (a[i] == 1) {
            if (reen[i] == 1) {
                DrawRotaGraph(176 * 1, y - interval * i, 0.7, 0.0, fumen[i], TRUE);//�P��ޖځA1���[��
            }
            if (reen[i] == 2) {
                DrawRotaGraph(176 * 2, y - interval * i, 0.7, 0.0, fumen[i], TRUE);//�P��ޖځA�Q���[��
            }
        }
        if (a[i] == 2) {
            if (reen[i] == 1) {
                DrawRotaGraph(176 * 1, y - interval * i, 0.7, 0.0, fumen[i], TRUE);//�Q��ޖځA1���[��
            }
            if (reen[i] == 2) {
                DrawRotaGraph(176 * 2, y - interval * i, 0.7, 0.0, fumen[i], TRUE);//�Q��ޖځA�Q���[��
            }
        }
        if (a[i] == 3) {
            if (reen[i] == 1) {
                DrawRotaGraph(176 * 1, y - interval * i, 0.7, 0.0, fumen[i], TRUE);//�R��ޖځA1���[��
            }
            if (reen[i] == 2) {
                DrawRotaGraph(176 * 2, y - interval * i, 0.7, 0.0, fumen[i], TRUE);//�R��ޖځA�Q���[��
            }
        }
        if (a[i] == 4) {
            if (reen[i] == 1) {
                DrawRotaGraph(176 * 1, y - interval * i, 0.7, 0.0, fumen[i], TRUE);//�S��ޖځA1���[��
            }
            if (reen[i] == 2) {
                DrawRotaGraph(176 * 2, y - interval * i, 0.7, 0.0, fumen[i], TRUE);//�S��ޖځA�Q���[��
            }
        }
        if (a[i] == 5) {
            if (reen[i] == 1) {
                DrawRotaGraph(176 * 1, y - interval * i, 0.7, 0.0, fumen[i], TRUE);//�T��ޖځA1���[��
            }
            if (reen[i] == 2) {
                DrawRotaGraph(176 * 2, y - interval * i, 0.7, 0.0, fumen[i], TRUE);//�T��ޖځA�Q���[��
            }
        }
    }

    
    DrawString(0, 20, "�G���^�[�L�[�������ƃ��U���g�Ɉڂ�܂��B", GetColor(255, 255, 255));
    DrawRotaGraph(bags_x, 310, 0.6, 0.0, bag, TRUE);
    DrawFormatString(250, 0, GetColor(255, 255, 255), "�X�R�A_%d", bags_x);
}