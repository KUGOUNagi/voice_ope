#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <math.h>
#include <string>
#include <fstream>
#include <sstream>
#define PI 3.1415926f

static int mImageHandle, Handle, don, katt;    //�摜�n���h���i�[�p�ϐ�
int x = 502, hantei = 3, kannkaku = 30, bpm = 5, kaunto, ryou, ka, fuka;
FILE* fp;
int a[] = { 0,0,0,1,0,2,0,0,0,1,0,1,0,2,0,0,0,1,0,1,0,
2,0,1,0,2,0,1,0,2,0,0,0,2,0,1,0,0,0,2,0,2,0,1,0,0,0,1,
0,2,0,1,0,2,0,1,0,1,0,2,0,0,0,1,0,2,0,0,0,1,0,1,0,2,0,
0,0,1,0,1,0,2,0,1,0,2,0,1,0,2,0,0,0,2,0,1,0,0,0,2,0,2,
0,1,0,0,0,1,0,2,0,1,0,2,0,1,0,1,0,2,0,0,0,1,0,2,0,0,0,
1,0,1,0,2,0,0,0,1,0,1,0,2,0,1,0,2,0,1,0,2,0,0,0,2,0,1,
0,0,0,2,0,2,0,1,0,0,0,1,0,2,0,1,0,2,0,1,0,1,0,2,0,0,0,
1,0,2,0,0,0,1,0,1,0,2,0,0,0,1,0,1,0,2,0,1,0,2,0,1,0,2,
0,0,0,2,0,1,0,0,0,2,0,2,0,1,0,0,0,1,0,2,0,1,0,2,0,1,0,1,0,2, };
int fumen[] = { 0,0,0,1,0,2,0,0,0,1,0,1,0,2,0,0,0,1,0,
1,0,2,0,1,0,2,0,1,0,2,0,0,0,2,0,1,0,0,0,2,0,2,0,1,0,0,
0,1,0,2,0,1,0,2,0,1,0,1,0,2,0,0,0,1,0,2,0,0,0,1,0,1,0,
2,0,0,0,1,0,1,0,2,0,1,0,2,0,1,0,2,0,0,0,2,0,1,0,0,0,2,
0,2,0,1,0,0,0,1,0,2,0,1,0,2,0,1,0,1,0,2,0,0,0,1,0,2,0,
0,0,1,0,1,0,2,0,0,0,1,0,1,0,2,0,1,0,2,0,1,0,2,0,0,0,2,
0,1,0,0,0,2,0,2,0,1,0,0,0,1,0,2,0,1,0,2,0,1,0,1,0,2,0,
0,0,1,0,2,0,0,0,1,0,1,0,2,0,0,0,1,0,1,0,2,0,1,0,2,0,1,
0,2,0,0,0,2,0,1,0,0,0,2,0,2,0,1,0,0,0,1,0,2,0,1,0,2,0,1,0,1,0,2, };
int fumenn = FileRead_open("fumenn.txt");
//������
void Game_Initialize() {
    mImageHandle = LoadGraph("img/taiko.png");    //�摜�̃��[�h
    Handle = LoadGraph("img/taiko01.png");
    don = LoadGraph("img/dontyan01.png");
    katt = LoadGraph("img/kattyan01.png");
}

//�I������
void Game_Finalize() {
    DeleteGraph(mImageHandle);    //�摜�̉��
    DeleteGraph(Handle);
    DeleteGraph(don);
    DeleteGraph(katt);
}
//�X�V
void Game_Update() {
    for (int i = 0; i < 1; i++) {
        x = x - (kannkaku / bpm);
        if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {
            x = 502;
        }
    }//�[���ɂ��炷
    for (int j = 0; j < (sizeof(a) / sizeof(a[0])); j++) {
        if (fumen[j] == 1 || fumen[j] == 3) {
            fumen[j] = don;
        }
        if (fumen[j] == 2 || fumen[j] == 4) {
            fumen[j] = katt;
        }
    }//�z����̐����ɂ���ďo�͂�ύX
    if (fumen[hantei] != don || fumen[hantei] != katt) {
        if (a[hantei] == 0) {
            hantei++;
        }
    }
    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Esc�L�[��������Ă�����
        for (int i = 0; i < (sizeof(a) / sizeof(a[0])); i++) {
            fumen[i] = a[i];
        }
        Game_Initialize();
        SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
    }
    if (Keyboard_Get(KEY_INPUT_G) == 1 || Keyboard_Get(KEY_INPUT_H) == 1) {//G,H�L�[��������Ă�����
        if (fumen[hantei] == don) {
            if (197 <= 2 + x + kannkaku * hantei && 2 + x + kannkaku * hantei <= 207) {
                ryou++;
            }
            if (192 <= 2 + x + kannkaku * hantei && 197 > 2 + x + kannkaku * hantei || 2 + x + kannkaku * hantei > 207 && 2 + x + kannkaku * hantei <= 212) {
                ka++;
            }
            if (192 > 2 + x + kannkaku * hantei || 2 + x + kannkaku * hantei > 212) {
                fuka++;
            }
        }
        if (fumen[hantei] == katt) {
            fuka++;
        }
        //2 + x + kannkaku * hantei;
        fumen[hantei] = 0;
        hantei++;
    }
    if (Keyboard_Get(KEY_INPUT_F) == 1 || Keyboard_Get(KEY_INPUT_J) == 1) {//F,J�L�[��������Ă�����
        if (fumen[hantei] == katt) {
            if (197 <= 2 + x + kannkaku * hantei && 2 + x + kannkaku * hantei <= 207) {
                ryou++;
            }
            if (192 <= 2 + x + kannkaku * hantei && 197 > 2 + x + kannkaku * hantei || 2 + x + kannkaku * hantei > 207 && 2 + x + kannkaku * hantei <= 212) {
                ka++;
            }
            if (192 > 2 + x + kannkaku * hantei || 2 + x + kannkaku * hantei > 212) {
                fuka++;
            }
        }
        if (fumen[hantei] == don) {
            fuka++;
        }
        //2 + x + kannkaku * hantei;
        fumen[hantei] = 0;
        hantei++;
    }
    /*if (Keyboard_Get(KEY_INPUT_RIGHT) == 1) {//�E�L�[��������Ă�����
        x = x + 10;//��������炷
    }*/

}

//�`��
void Game_Draw() {
    DrawRotaGraph(320, 230, 0.48, 0.0, mImageHandle, FALSE);
    /*DrawRotaGraph(212, 176, 0.215, 0.0, katt, TRUE);//���������J�b
    DrawRotaGraph(212, 176, 0.14, 0.0, katt, TRUE);//���������J�b
    DrawRotaGraph(602, 176, 0.17, 0.0, don, TRUE);//���������h��
    DrawRotaGraph(502, 176, 0.26, 0.0, don, TRUE);//���������h��*/
    for (int i = 0; i < (sizeof(a) / sizeof(a[0])); i++) {
        if (a[i] == 1) {
            DrawRotaGraph(2 + x + kannkaku * i, 176, 0.17, 0.0, fumen[i], TRUE);//���������h��
        }
        if (a[i] == 2) {
            DrawRotaGraph(2 + x + kannkaku * i, 176, 0.14, 0.0, fumen[i], TRUE);//���������J�b
        }
        if (a[i] == 3) {
            DrawRotaGraph(2 + x + kannkaku * i, 176, 0.26, 0.0, fumen[i], TRUE);//���������h��
        }
        if (a[i] == 4) {
            DrawRotaGraph(2 + x + kannkaku * i, 176, 0.215, 0.0, fumen[i], TRUE);//���������J�b
        }
    }
    DrawRotaGraph(82, 185, 0.48, 0.0, Handle, FALSE);
    DrawString(0, 0, "�Q�[����ʂł��B", GetColor(255, 255, 255));
    DrawString(0, 20, "Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
    DrawFormatString(0, 40, GetColor(255, 255, 255), "%d", kannkaku);
    DrawFormatString(300, 0, GetColor(255, 255, 255), "��_%d", ryou);
    DrawFormatString(350, 0, GetColor(255, 255, 255), "��_%d", ka);
    DrawFormatString(400, 0, GetColor(255, 255, 255), "�s��_%d", fuka);
}