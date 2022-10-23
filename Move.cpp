#include "Move.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"
#include "ScoreClass.h"

static int mImageHandle;
Score score;

void Move_Initialize() {
	mImageHandle = LoadGraph("img/danzyon1.jpeg");    //画像のロード
}
void Move_Finalize() {
}
//更新
void Move_Update() {
	if (CheckHitKey(KEY_INPUT_G) != 0) {//Gキーが押されていたら
		SceneMgr_ChangeScene(eScene_Game);//シーンをゲーム画面に変更
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Escキーが押されていたら
		SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
	}
	if (CheckHitKey(KEY_INPUT_M) != 0) {//Mキーが押されていたら
		SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
	}
}

//描画
void Move_Draw() {
	score.c;
	score.print1();
	DrawRotaGraph(320, 230, 1, 0.0, mImageHandle, FALSE);
	DrawString(0, 20, "Mキーを押すとメニュー画面に戻ります。", GetColor(255, 255, 255));
}
