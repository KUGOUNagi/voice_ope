#include "Move.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"

static int kirito, mImageHandle;

void Move_Initialize() {
	kirito = LoadGraph("img/kirito02.png");
	mImageHandle = LoadGraph("img/danzyon1.jpeg");    //画像のロード
}
void Move_Finalize() {
	DeleteGraph(kirito);
}
//更新
void Move_Update() {
	if (CheckHitKey(KEY_INPUT_G) != 0) {//Gキーが押されていたら
		SceneMgr_ChangeScene(eScene_Game);//シーンをゲーム画面に変更
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Escキーが押されていたら
		SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
	}
	if (CheckHitKey(KEY_INPUT_F) != 0) {//Escキーが押されていたら
		SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
	}
}

//描画
void Move_Draw() {
	DrawRotaGraph(320, 230, 1, 0.0, mImageHandle, FALSE);
	DrawString(0, 20, "Gキーを押すとメニュー画面に戻ります。", GetColor(255, 255, 255));
	DrawRotaGraph(300, 255, 1, 0.0, kirito, TRUE);
}