#pragma once

typedef enum {
    eScene_Menu,    //���j���[���
    eScene_Game,    //�Q�[�����
    eScene_Config,  //�ݒ���
    eScene_Move,
    eScene_tutorial,
    eScene_Score,
    eScene_None,    //����
} eScene;

void SceneMgr_Initialize();//������
void SceneMgr_Finalize();//�I������
//�X�V
void SceneMgr_Update();

//�`��
void SceneMgr_Draw();

// ���� nextScene �ɃV�[����ύX����
void SceneMgr_ChangeScene(eScene nextScene);