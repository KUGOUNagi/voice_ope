/*#include <stdio.h>
#include <winsock2.h>

int main(void) {
    SOCKET s;    //�\�P�b�g
    //�ڑ�����T�[�o�̏��
    struct sockaddr_in dest;
    //�ڑ�����T�[�o��IP�A�h���X

    char destination[] = "127.0.0.1";
    char buffer[4096];

    //�\�P�b�g�ʐM�̏���
    WSADATA data;
    WSAStartup(MAKEWORD(2, 0), &data);

    //�ڑ���i�T�[�o�j�̃A�h���X����ݒ�
    memset(&dest, 0, sizeof(dest));
    //�|�[�g�ԍ��̓T�[�o�v���O�����Ƌ���
    dest.sin_port = htons(10500);
    dest.sin_family = AF_INET;
    dest.sin_addr.s_addr = inet_addr(destination);

    //�\�P�b�g�̐���
    s = socket(PF_INET, SOCK_STREAM, 0);

    //�T�[�o�ւ̐ڑ�
    if (connect(s, (struct sockaddr*)&dest, sizeof(dest))) {
        printf("NG", destination);
        return -1;
    }
    printf("OK", destination);

    for (int i = 0; i < 50; i++) {   //50�s�\��
    //�T�[�o����f�[�^����M
        recv(s, buffer, 4096, 0);
        for (int j = 0; j < 4096; j++) {
            if (buffer[j] == '.') { buffer[j + 1] = '\0'; break; }
        }
        printf("%s\n\n", buffer);
    }
    scanf("%s", buffer); //�����ɒ�~�����Ă���

    // Windows �ł̃\�P�b�g�̏I��
    closesocket(s);
    WSACleanup();

    return 0;
}*/
