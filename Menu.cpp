#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"

const static int GAME_Y = 240;    //「ゲーム」文字のy位置
const static int CONFIG_Y = 270;    //「設定」文字のy位置
const static int MOVE_Y = 300;

static int mImageHandle;    //画像ハンドル格納用変数

//初期化
void Menu_Initialize() {
    mImageHandle = LoadGraph("img/danzyon1.jpeg");    //画像のロード
}

//終了処理
void Menu_Finalize() {
    DeleteGraph(mImageHandle);    //画像の解放
}
typedef enum {
    eMune_tutorial,
    //eMenu_Game,        //ゲーム
    eMenu_Config,    //設定
    eMenu_Move,

    eMenu_Num,        //本項目の数
} eMenu;

static int NowSelect = eMune_tutorial;    //現在の選択状態(初期はゲーム選択中)

//更新
void Menu_Update() {
    if (Keyboard_Get(KEY_INPUT_DOWN) == 1) {//下キーが押されていたら
        NowSelect = (NowSelect + 1) % eMenu_Num;//選択状態を一つ下げる
    }
    if (Keyboard_Get(KEY_INPUT_UP) == 1) {//上キーが押されていたら
        NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;//選択状態を一つ上げる
    }
    if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {//エンターキーが押されたら
        switch (NowSelect) {//現在選択中の状態によって処理を分岐
        case eMune_tutorial://ゲーム選択中なら
            SceneMgr_ChangeScene(eScene_tutorial);//シーンをゲーム画面に変更
            break;
        case eMenu_Config://設定選択中なら
            SceneMgr_ChangeScene(eScene_Config);//シーンを設定画面に変更
            break;
        case eMenu_Move://ゲーム選択中なら
            SceneMgr_ChangeScene(eScene_Move);//シーンをゲーム画面に変更
            break;
        }
    }
}

//描画
void Menu_Draw() {
    //DrawGraph(0, 0, mImageHandle, FALSE);
    DrawRotaGraph(320, 230, 1.7, 0.0, mImageHandle, FALSE);
    SetFontSize(50);
    DrawString(140, 70, "VOICE OPERATER", GetColor(255, 255, 255));
    SetFontSize(16);
    DrawString(170, 170, "声で操作してハイスコアを狙おう！！", GetColor(255, 255, 255));
    DrawString(280, GAME_Y, "ゲームを始める", GetColor(255, 255, 255));
    DrawString(280, CONFIG_Y, "設定", GetColor(255, 255, 255));
    DrawString(280, MOVE_Y, "ルール説明", GetColor(255, 255, 255));
    int y = 0;
    switch (NowSelect) {//現在の選択状態に従って処理を分岐
    case eMune_tutorial://ゲーム選択中なら
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
}
