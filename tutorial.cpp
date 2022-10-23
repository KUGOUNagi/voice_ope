#include "tutorial.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <math.h>
#include <string>
#include <fstream>
#include <sstream>
#define PI 3.1415926f

static int mImageHandle, Handle, bag;   //画像ハンドル格納用変数
int bag_x = 280, speed = 2;

//初期化
void tutorial_Initialize() {
    mImageHandle = LoadGraph("img/backgraund.png");    //画像のロード
    bag = LoadGraph("img/bag.png");
}

//終了処理
void tutorial_Finalize() {
    DeleteGraph(mImageHandle);    //画像の解放
    //DeleteGraph(Handle);
    DeleteGraph(bag);
}
//更新
void tutorial_Update() {
    if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {//エンターキーが押されていたら
        SceneMgr_ChangeScene(eScene_Game);//シーンをゲームに変更
    }
        if (Keyboard_Get(KEY_INPUT_RIGHT) != 0) { 
        bag_x=bag_x+speed;                       //右に移動
    }
    if (Keyboard_Get(KEY_INPUT_LEFT) != 0) { 
        bag_x=bag_x-speed;                       //左に移動
    }
}

//描画
void tutorial_Draw() {
    DrawRotaGraph(320, 230, 0.9, 0.0, mImageHandle, FALSE);
    DrawRotaGraph(bag_x, 330, 0.7, 0.0, bag, TRUE);
    DrawString(0, 0, "チュートリアル画面です。", GetColor(255, 255, 255));
    DrawString(0, 20, "エンターキーを押すとゲーム画面に移ります。", GetColor(255, 255, 255));
    DrawFormatString(0, 40, GetColor(255, 255, 255), "%d", 5);
}