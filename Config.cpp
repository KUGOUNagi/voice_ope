#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"

const static int GAME_Y = 240;    //「ゲーム」文字のy位置
const static int CONFIG_Y = 270;    //「設定」文字のy位置
const static int MOVE_Y = 300;

static int mImageHandle;    //画像ハンドル格納用変数
int z = 550, sikaku1 = 0;
int sikaku[] = { 60,80,100,120,140 };

//初期化
void Config_Initialize() {
    mImageHandle = LoadGraph("img/danzyon.jpeg");    //画像のロード
}

//終了処理
void Config_Finalize() {
    DeleteGraph(mImageHandle);//画像の解放
}
typedef enum {
    eMenu_Game,        //ゲーム
    eMenu_Config,    //設定
    eMenu_Move,

    eMenu_Num,        //本項目の数
} eMenu;

static int NowSelect = eMenu_Game;    //現在の選択状態(初期はゲーム選択中)

//更新
void Config_Update() {
    if (Keyboard_Get(KEY_INPUT_DOWN) == 1) {//下キーが押されていたら
        NowSelect = (NowSelect + 1) % eMenu_Num;//選択状態を一つ下げる
    }
    if (Keyboard_Get(KEY_INPUT_UP) == 1) {//上キーが押されていたら
        NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;//選択状態を一つ上げる
    }

    if (CheckHitKey(KEY_INPUT_U) != 0) {//Gキーが押されていたら
        sikaku1--;//シーンをゲーム画面に変更
    }
    if (CheckHitKey(KEY_INPUT_D) != 0) {//Gキーが押されていたら
        sikaku1++;//シーンをゲーム画面に変更
    }
    if (CheckHitKey(KEY_INPUT_G) != 0) {//Gキーが押されていたら
        SceneMgr_ChangeScene(eScene_Menu);//シーンをゲーム画面に変更
    }
    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Escキーが押されていたら
        SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
    }
}

//描画
void Config_Draw() {
    DrawRotaGraph(320, 230, 1.5, 0.0, mImageHandle, FALSE);

    DrawString(0, 0, "設定画面です。", GetColor(255, 255, 255));
    DrawString(280, 200, "速度", GetColor(255, 255, 255));
    DrawString(280, 220, "難易度", GetColor(255, 255, 255));
    DrawString(280, 240, "明るさ", GetColor(255, 255, 255));
    DrawString(280, 260, "ルール", GetColor(255, 255, 255));
    //DrawString(280, 280, "製作者", GetColor(255, 255, 255));
    int y = 0;
    switch (NowSelect) {//現在の選択状態に従って処理を分岐
    case eMenu_Game://ゲーム選択中なら
        y = GAME_Y;    //ゲームの座標を格納
        y = GAME_Y;    //ゲームの座標を格納
        break;
    case eMenu_Config://設定選択中なら
        y = CONFIG_Y;    //設定の座標を格納
        break;
    case eMenu_Move://設定選択中なら
        y = MOVE_Y;    //設定の座標を格納
        break;
    }
    DrawString(250, y, "■", GetColor(255, 255, 255));
    //DrawString(0, 20, "Escキーを押すとメニュー画面に戻ります。", GetColor(255, 255, 255));
    DrawString(280, 300, "Gキーを押すとゲーム画面に移行します。", GetColor(255, 255, 255));
}