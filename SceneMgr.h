#pragma once

typedef enum {
    eScene_Menu,    //メニュー画面
    eScene_Game,    //ゲーム画面
    eScene_Config,  //設定画面
    eScene_Move,
    eScene_tutorial,
    eScene_Score,
    eScene_None,    //無し
} eScene;

void SceneMgr_Initialize();//初期化
void SceneMgr_Finalize();//終了処理
//更新
void SceneMgr_Update();

//描画
void SceneMgr_Draw();

// 引数 nextScene にシーンを変更する
void SceneMgr_ChangeScene(eScene nextScene);