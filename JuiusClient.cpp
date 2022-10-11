/*#include <stdio.h>
#include <winsock2.h>

int main(void) {
    SOCKET s;    //ソケット
    //接続するサーバの情報
    struct sockaddr_in dest;
    //接続するサーバのIPアドレス

    char destination[] = "127.0.0.1";
    char buffer[4096];

    //ソケット通信の準備
    WSADATA data;
    WSAStartup(MAKEWORD(2, 0), &data);

    //接続先（サーバ）のアドレス情報を設定
    memset(&dest, 0, sizeof(dest));
    //ポート番号はサーバプログラムと共通
    dest.sin_port = htons(10500);
    dest.sin_family = AF_INET;
    dest.sin_addr.s_addr = inet_addr(destination);

    //ソケットの生成
    s = socket(PF_INET, SOCK_STREAM, 0);

    //サーバへの接続
    if (connect(s, (struct sockaddr*)&dest, sizeof(dest))) {
        printf("NG", destination);
        return -1;
    }
    printf("OK", destination);

    for (int i = 0; i < 50; i++) {   //50行表示
    //サーバからデータを受信
        recv(s, buffer, 4096, 0);
        for (int j = 0; j < 4096; j++) {
            if (buffer[j] == '.') { buffer[j + 1] = '\0'; break; }
        }
        printf("%s\n\n", buffer);
    }
    scanf("%s", buffer); //強引に停止させている

    // Windows でのソケットの終了
    closesocket(s);
    WSACleanup();

    return 0;
}*/
