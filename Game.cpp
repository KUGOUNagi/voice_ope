#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <math.h>
#include <string>
#include <fstream>
#include <sstream>
#define PI 3.1415926f

static int mImageHandle, Handle, don, katt;    //画像ハンドル格納用変数
int y = -5000, hantei = 3, interval = 100, bpm = 30, kaunto, ryou, ka, fuka;
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
//初期化
void Game_Initialize() {
    mImageHandle = LoadGraph("img/backgraund.png");    //画像のロード
    don = LoadGraph("img/candy.png");
    katt = LoadGraph("img/cookie.png");
}

//終了処理
void Game_Finalize() {
    DeleteGraph(mImageHandle);    //画像の解放
    //DeleteGraph(Handle);
    DeleteGraph(don);
    DeleteGraph(katt);
}
//更新
void Game_Update() {
    for (int i = 0; i < 1; i++) {
        x = x + (interval / bpm);
        if (CheckHitKey(KEY_INPUT_B) != 0) {
            x = -5000;
        }
    }//ー側にずらす
    for (int j = 0; j < (sizeof(a) / sizeof(a[0])); j++) {
        if (fumen[j] == 1 || fumen[j] == 3) {
            fumen[j] = don;
        }
        if (fumen[j] == 2 || fumen[j] == 4) {
            fumen[j] = katt;
        }
    }//配列内の数字によって出力を変更
    if (fumen[hantei] != don || fumen[hantei] != katt) {
        if (a[hantei] == 0) {
            hantei++;
        }
    }
    if (CheckHitKey(KEY_INPUT_B) != 0) {//Escキーが押されていたら
        for (int i = 0; i < (sizeof(a) / sizeof(a[0])); i++) {
            fumen[i] = a[i];
        }
        Game_Initialize();
        SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
    }
    if (Keyboard_Get(KEY_INPUT_G) == 1 || Keyboard_Get(KEY_INPUT_H) == 1) {//G,Hキーが押されていたら
        if (fumen[hantei] == don) {
            if (197 <= 2 + x + interval * hantei && 2 + x + interval * hantei <= 207) {
                ryou++;
            }
            if (192 <= 2 + x + interval * hantei && 197 > 2 + x + interval * hantei || 2 + x + interval * hantei > 207 && 2 + x + interval * hantei <= 212) {
                ka++;
            }
            if (192 > 2 + x + interval * hantei || 2 + x + interval * hantei > 212) {
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
    if (Keyboard_Get(KEY_INPUT_F) == 1 || Keyboard_Get(KEY_INPUT_J) == 1) {//F,Jキーが押されていたら
        if (fumen[hantei] == katt) {
            if (197 <= 2 + y + interval * hantei && 2 + y + interval * hantei <= 207) {
                ryou++;
            }
            if (192 <= 2 + y + interval * hantei && 197 > 2 + y + interval * hantei || 2 + y + interval * hantei > 207 && 2 + y + interval * hantei <= 212) {
                ka++;
            }
            if (192 > 2 + y + interval * hantei || 2 + y + interval * hantei > 212) {
                fuka++;
            }
        }
        if (fumen[hantei] == don) {
            fuka++;
        }
        //2 + x + interval * hantei;
        fumen[hantei] = 0;
        hantei++;
    }
    /*if (Keyboard_Get(KEY_INPUT_RIGHT) == 1) {//右キーが押されていたら
        x = x + 10;//ｘを一つずらす
    }*/

}

//描画
void Game_Draw() {
    DrawRotaGraph(320, 230, 0.9, 0.0, mImageHandle, FALSE);
    for (int i = 0; i < (sizeof(a) / sizeof(a[0])); i++) {
        if (a[i] == 1) {
            DrawRotaGraph(176, y + interval * i, 0.7, 0.0, fumen[i], TRUE);//ちいさいドン
        }
        if (a[i] == 2) {
            DrawRotaGraph(176, y + interval * i, 0.7, 0.0, fumen[i], TRUE);//ちいさいカッ
        }
        if (a[i] == 3) {
            DrawRotaGraph(176, y + interval * i, 0.7, 0.0, fumen[i], TRUE);//おおきいドン
        }
        if (a[i] == 4) {
            DrawRotaGraph(176, y + interval * i, 0.7, 0.0, fumen[i], TRUE);//おおきいカッ
        }
    }
    //DrawRotaGraph(82, 185, 1.5, 0.0, Handle, FALSE);
    //DrawString(0, 0, "ゲーム画面です。", GetColor(255, 255, 255));
    DrawString(0, 20, "Bキーを押すとメニュー画面に戻ります。", GetColor(255, 255, 255));
    DrawFormatString(0, 40, GetColor(255, 255, 255), "%d", interval);
    DrawFormatString(300, 0, GetColor(255, 255, 255), "良_%d", ryou);
    DrawFormatString(350, 0, GetColor(255, 255, 255), "可_%d", ka);
    DrawFormatString(400, 0, GetColor(255, 255, 255), "不可_%d", fuka);
}