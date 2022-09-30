#include "tutorial.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <math.h>
#include <string>
#include <fstream>
#include <sstream>
#define PI 3.1415926f

static int mImageHandle, Handle, candy, cookie;    //画像ハンドル格納用変数

//初期化
void tutorial_Initialize() {
    mImageHandle = LoadGraph("img/backgraund.png");    //画像のロード
    candy = LoadGraph("img/candy.png");
    cookie = LoadGraph("img/cookie.png");
}

//終了処理
void tutorial_Finalize() {
    DeleteGraph(mImageHandle);    //画像の解放
    //DeleteGraph(Handle);
    DeleteGraph(candy);
    DeleteGraph(cookie);
}
//更新
void tutorial_Update() {
    if (CheckHitKey(KEY_INPUT_B) != 0) {//Escキーが押されていたら
        SceneMgr_ChangeScene(eScene_Game);//シーンをゲームに変更
    }

}

//描画
void tutorial_Draw() {
    DrawRotaGraph(320, 230, 0.9, 0.0, mImageHandle, FALSE);
    DrawString(0, 0, "チュートリアル画面です。", GetColor(255, 255, 255));
    DrawString(0, 20, "Bキーを押すとゲーム画面に移ります。", GetColor(255, 255, 255));
    DrawFormatString(0, 40, GetColor(255, 255, 255), "%d", 5);
    //DrawFormatString(300, 0, GetColor(255, 255, 255), "良_%d", ryou);
    //DrawFormatString(350, 0, GetColor(255, 255, 255), "可_%d", ka);
    //DrawFormatString(400, 0, GetColor(255, 255, 255), "不可_%d", fuka);
}