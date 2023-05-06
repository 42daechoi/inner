// #include <iostream>
// #include <string>
// #include <unistd.h>
// #include <arpa/inet.h>

// int main() {
//     int sockfd = socket(AF_INET, SOCK_STREAM, 0);
//     if (sockfd < 0) {
//         perror("소켓 생성 실패");
//         exit(1);
//     }

//     struct sockaddr_in serv_addr;
//     serv_addr.sin_family = AF_INET;
//     serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // 서버 IP 주소
//     serv_addr.sin_port = htons(1234); // 서버 포트 번호

//     if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
//         perror("서버에 연결 실패");
//         exit(1);
//     }

//     std::string sendData = "클라이언트 데이터"; // 전송할 데이터
//     send(sockfd, sendData.c_str(), sendData.length(), 0);
//     std::cout << "송신 데이터: " << sendData << std::endl;

//     char recvBuffer[1024] = {0};
//     int recvSize = recv(sockfd, recvBuffer, sizeof(recvBuffer), 0);
//     if (recvSize < 0) {
//         perror("데이터 수신 실패");
//         exit(1);
//     }

//     std::string receivedData = std::string(recvBuffer, recvSize);
//     std::cout << "수신 데이터: " << receivedData << std::endl;

//     close(sockfd);

//     return 0;
// }

#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

const int PORT = 12345; // 포트 번호

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;

    // 소켓 생성
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "소켓 생성 실패" << std::endl;
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // 서버 주소 설정
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cerr << "유효하지 않은 서버 주소" << std::endl;
        return 1;
    }

    // 서버에 연결
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "서버 연결 실패" << std::endl;
        return 1;
    }

    std::cout << "서버에 연결되었습니다." << std::endl;

    while (true) {
        // 데이터 전송
        std::string message;
        std::cout << "보낼 메시지: ";
        std::getline(std::cin, message);
        send(sockfd, message.c_str(), message.length(), 0);

        // 데이터 수신
        // char buffer[1024] = {0};
        // int recv_bytes = recv(sockfd, buffer, sizeof(buffer), 0);
        // if (recv_bytes <= 0) {
        //     std::cerr << "서버와의 연결이 끊어졌습니다." << std::endl;
        //     break;
        // }
        // std::cout << "받은 메시지: " << buffer << std::endl;
    }

    // 소켓 닫기
    close(sockfd);

    return 0;
}