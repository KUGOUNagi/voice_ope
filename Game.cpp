#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <math.h>
#include <string>
#include <fstream>
#include <sstream>
#define PI 3.1415926f

static int mImageHandle, Handle, sounds, candy, cookie, bag;    //画像ハンドル格納用変数
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
0,0,0,2,0,1,0,0,0,2,0,2,0,1,0,0,0,1,0,2,0,1,0,2,0,1,0,1,0,2, };//リセット用の配列

int reen[] = { 0,0,0,1,0,2,0,0,0,1,0,1,0,2,0,0,0,1,0,1,0,
2,0,1,0,2,0,1,0,2,0,0,0,2,0,1,0,0,0,2,0,2,0,1,0,0,0,1,
0,2,0,1,0,2,0,1,0,1,0,2,0,0,0,1,0,2,0,0,0,1,0,1,0,2,0,
0,0,1,0,1,0,2,0,1,0,2,0,1,0,2,0,0,0,2,0,1,0,0,0,2,0,2,
0,1,0,0,0,1,0,2,0,1,0,2,0,1,0,1,0,2,0,0,0,1,0,2,0,0,0,
1,0,1,0,2,0,0,0,1,0,1,0,2,0,1,0,2,0,1,0,2,0,0,0,2,0,1,
0,0,0,2,0,2,0,1,0,0,0,1,0,2,0,1,0,2,0,1,0,1,0,2,0,0,0,
1,0,2,0,0,0,1,0,1,0,2,0,0,0,1,0,1,0,2,0,1,0,2,0,1,0,2,
0,0,0,2,0,1,0,0,0,2,0,2,0,1,0,0,0,1,0,2,0,1,0,2,0,1,0,1,0,2, };//レーンの配列

int fumen[] = { 0,0,0,1,0,2,0,0,0,1,0,1,0,2,0,0,0,1,0,
1,0,2,0,1,0,2,0,1,0,2,0,0,0,2,0,1,0,0,0,2,0,2,0,1,0,0,
0,1,0,2,0,1,0,2,0,1,0,1,0,2,0,0,0,1,0,2,0,0,0,1,0,1,0,
2,0,0,0,1,0,1,0,2,0,1,0,2,0,1,0,2,0,0,0,2,0,1,0,0,0,2,
0,2,0,1,0,0,0,1,0,2,0,1,0,2,0,1,0,1,0,2,0,0,0,1,0,2,0,
0,0,1,0,1,0,2,0,0,0,1,0,1,0,2,0,1,0,2,0,1,0,2,0,0,0,2,
0,1,0,0,0,2,0,2,0,1,0,0,0,1,0,2,0,1,0,2,0,1,0,1,0,2,0,
0,0,1,0,2,0,0,0,1,0,1,0,2,0,0,0,1,0,1,0,2,0,1,0,2,0,1,
0,2,0,0,0,2,0,1,0,0,0,2,0,2,0,1,0,0,0,1,0,2,0,1,0,2,0,1,0,1,0,2, };//画像の配列

//初期化
void Game_Initialize() {
    sounds = LoadSoundMem("sound/music.wav");
    mImageHandle = LoadGraph("img/backgraund.png");    //画像のロード
    candy = LoadGraph("img/candy.png");
    cookie = LoadGraph("img/cookie.png");
    bag = LoadGraph("img/bag.png");
    PlaySoundMem(sounds, DX_PLAYTYPE_BACK,TRUE);
}

//終了処理
void Game_Finalize() {
    DeleteGraph(mImageHandle);    //画像の解放
    DeleteGraph(candy);
    DeleteGraph(cookie);
    DeleteGraph(bag);
    DeleteSoundMem(sounds);
}
//更新
void Game_Update() {
    for (int i = 0; i < 1; i++) {
        y = y + (interval / bpm);
    }

    for (int j = 0; j < (sizeof(a) / sizeof(a[0])); j++) {
        if (fumen[j] == 1 || fumen[j] == 3) {//配列内の数字によって出力を変更
            fumen[j] = candy;
        }
        if (fumen[j] == 2 || fumen[j] == 4) {
            fumen[j] = cookie;
        }
    }

    if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {//エンターキーが押されていたら
        for (int i = 0; i < (sizeof(a) / sizeof(a[0])); i++) {//リセット
            fumen[i] = a[i];
            reen[i] = a[i];
        }
        StopSoundMem(sounds);
        bags_x = 280;
        y = 0;
        Game_Initialize();//リセット
        SceneMgr_ChangeScene(eScene_Score);//シーンをメニューに変更
    }

    if (Keyboard_Get(KEY_INPUT_RIGHT) != 0) { 
        bags_x = bags_x + speeds;                       // 右に移動
    }
    if (Keyboard_Get(KEY_INPUT_LEFT) != 0) { 
        bags_x = bags_x - speeds;                       // 左に移動
    }

}

//描画
void Game_Draw() {
    DrawRotaGraph(320, 230, 0.9, 0.0, mImageHandle, FALSE);//背景
    
    for (int i = 0; i < (sizeof(a) / sizeof(a[0])); i++) {
        if (a[i] == 1) {
            if (reen[i] == 1) {
                DrawRotaGraph(176 * 1, y - interval * i, 0.7, 0.0, fumen[i], TRUE);//１種類目、1レーン
            }
            if (reen[i] == 2) {
                DrawRotaGraph(176 * 2, y - interval * i, 0.7, 0.0, fumen[i], TRUE);//１種類目、２レーン
            }
        }
        if (a[i] == 2) {
            if (reen[i] == 1) {
                DrawRotaGraph(176 * 1, y - interval * i, 0.7, 0.0, fumen[i], TRUE);//２種類目、1レーン
            }
            if (reen[i] == 2) {
                DrawRotaGraph(176 * 2, y - interval * i, 0.7, 0.0, fumen[i], TRUE);//２種類目、２レーン
            }
        }
        if (a[i] == 3) {
            if (reen[i] == 1) {
                DrawRotaGraph(176 * 1, y - interval * i, 0.7, 0.0, fumen[i], TRUE);//３種類目、1レーン
            }
            if (reen[i] == 2) {
                DrawRotaGraph(176 * 2, y - interval * i, 0.7, 0.0, fumen[i], TRUE);//３種類目、２レーン
            }
        }
        if (a[i] == 4) {
            if (reen[i] == 1) {
                DrawRotaGraph(176 * 1, y - interval * i, 0.7, 0.0, fumen[i], TRUE);//４種類目、1レーン
            }
            if (reen[i] == 2) {
                DrawRotaGraph(176 * 2, y - interval * i, 0.7, 0.0, fumen[i], TRUE);//４種類目、２レーン
            }
        }
        if (a[i] == 5) {
            if (reen[i] == 1) {
                DrawRotaGraph(176 * 1, y - interval * i, 0.7, 0.0, fumen[i], TRUE);//５種類目、1レーン
            }
            if (reen[i] == 2) {
                DrawRotaGraph(176 * 2, y - interval * i, 0.7, 0.0, fumen[i], TRUE);//５種類目、２レーン
            }
        }
    }

    
    DrawString(0, 20, "エンターキーを押すとリザルトに移ります。", GetColor(255, 255, 255));
    DrawRotaGraph(bags_x, 310, 0.6, 0.0, bag, TRUE);
    DrawFormatString(250, 0, GetColor(255, 255, 255), "スコア_%d", bags_x);
}
