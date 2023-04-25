#include <iostream>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("소켓 생성 실패");
        exit(1);
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // 서버 IP 주소
    serv_addr.sin_port = htons(1234); // 서버 포트 번호

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("서버에 연결 실패");
        exit(1);
    }

    std::string sendData = "클라이언트 데이터"; // 전송할 데이터
    send(sockfd, sendData.c_str(), sendData.length(), 0);
    std::cout << "송신 데이터: " << sendData << std::endl;

    char recvBuffer[1024] = {0};
    int recvSize = recv(sockfd, recvBuffer, sizeof(recvBuffer), 0);
    if (recvSize < 0) {
        perror("데이터 수신 실패");
        exit(1);
    }

    std::string receivedData = std::string(recvBuffer, recvSize);
    std::cout << "수신 데이터: " << receivedData << std::endl;

    close(sockfd);

    return 0;
}