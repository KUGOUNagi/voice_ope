#include "Score.h"
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
void Score_Initialize() {
    mImageHandle = LoadGraph("img/backgraund.png");    //画像のロード
    candy = LoadGraph("img/candy.png");
    cookie = LoadGraph("img/cookie.png");
}

//終了処理
void Score_Finalize() {
    DeleteGraph(mImageHandle);    //画像の解放
    //DeleteGraph(Handle);
    DeleteGraph(candy);
    DeleteGraph(cookie);
}
//更新
void Score_Update() {
    if (CheckHitKey(KEY_INPUT_RETURN) == 1) {//Escキーが押されていたら
        SceneMgr_ChangeScene(eScene_Menu);//シーンをゲームに変更
    }

}

//描画
void Score_Draw() {
    DrawRotaGraph(320, 230, 0.9, 0.0, mImageHandle, FALSE);
    DrawString(0, 0, "スコア画面です。", GetColor(255, 255, 255));
    DrawString(0, 20, "エンターキーを押すとメニュー画面に戻ります。", GetColor(255, 255, 255));
    DrawFormatString(300, 300, GetColor(255, 255, 255), "%d", 1073741824);//オーバーフロー2^30
    //DrawFormatString(300, 0, GetColor(255, 255, 255), "良_%d", ryou);
    //DrawFormatString(350, 0, GetColor(255, 255, 255), "可_%d", ka);
    //DrawFormatString(400, 0, GetColor(255, 255, 255), "不可_%d", fuka);
}