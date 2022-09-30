/*#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"

const static int aa, bb, cc, dd, ee;
static int mImageHandle;    //画像ハンドル格納用変数
int z = 550, sikaku1 = 0;
int sikaku[] = { 60,80,100,120,140 };
//初期化
void Config_Initialize() {
    mImageHandle = LoadGraph("img/char.png");//画像のロード
}

//終了処理
void Config_Finalize() {
    DeleteGraph(mImageHandle);//画像の解放
}
//更新
void Config_Update() {
    if (CheckHitKey(KEY_INPUT_U) != 0) {//Gキーが押されていたら
        sikaku1--;//シーンをゲーム画面に変更
    }
    if (CheckHitKey(KEY_INPUT_D) != 0) {//Gキーが押されていたら
        sikaku1++;//シーンをゲーム画面に変更
    }
    if (CheckHitKey(KEY_INPUT_G) != 0) {//Gキーが押されていたら
        SceneMgr_ChangeScene(eScene_Game);//シーンをゲーム画面に変更
    }
    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Escキーが押されていたら
        SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
    }
}

//描画
void Config_Draw() {

    DrawString(0, 0, "設定画面です。", GetColor(255, 255, 255));
    DrawString(100, 60, "さいたま2000", GetColor(255, 255, 255));
    DrawString(100, 80, "幽玄ノ乱", GetColor(255, 255, 255));
    DrawString(100, 100, "やわらか戦車", GetColor(255, 255, 255));
    DrawString(100, 120, "シロナ戦", GetColor(255, 255, 255));
    DrawString(100, 140, "マフィア", GetColor(255, 255, 255));
    DrawString(50, sikaku[sikaku1], "■", GetColor(255, 255, 255));
    DrawString(0, 20, "Escキーを押すとメニュー画面に戻ります。", GetColor(255, 255, 255));
    DrawString(0, 40, "Gキーを押すとゲーム画面に移行します。", GetColor(255, 255, 255));
}*/