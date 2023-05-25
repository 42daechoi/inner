#ifndef BOT_HPP
# define BOT_HPP

# include <string>
# include <iostream>
# include <sys/socket.h>

using namespace std;

class Bot {
	public:
		Bot(string msg);

		void 	sendToServer(int serverfd);
		string 	makeMsg();
	private:
		string 	_nickname;
		string 	_username;
		string 	_ip;
		string 	_msg;
};

#endif

// #include "Bot.hpp"

// Bot::Bot(string msg) {
// 	int i, j;

// 	i = msg.find("!");
// 	_nickname = msg.substr(1, i - 2);
// 	j = msg.find("@");
// 	_username = msg.substr(i + 1, j - i);
// 	i = msg.find(" ");
// 	_ip = msg.substr(j + 1, i - j);
// 	i = msg.find(":", 2);
// 	_msg = msg.substr(i + 1, msg.length() - i + 1);

// 	cout << "nickname: " << _nickname << endl;
// 	cout << "username: " << _username << endl;
// 	cout << "ip: " << _ip << endl;
// 	cout << "msg: " << _msg << endl;
// }

// void Bot::sendToServer(int serverfd) {
// 	string msg = makeMsg();
// 	if (send(serverfd, msg.c_str(), msg.length(), 0) == -1) {
// 		cout << "Error: send error\n";
// 		exit(1);
// 	}
// }

// string Bot::makeMsg() {
// 	string msg;

// 	if (_msg == "help")
// 		msg = "PRIVMSG " + _nickname + " :<COMMAND LIST>\nSUPERJOIN\n";
// 	else if (_msg == "superjoin")
// 		msg = "SUPERJOIN " + _nickname;
// 	else
// 		msg = "PRIVMSG " + _nickname + " :There is no matching command. Please send me a help message\n";
// 	return msg;
// }






// #include <iostream>
// #include <unistd.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <arpa/inet.h>
// #include <sstream>
// #include <string>
// #include "Bot.hpp"

// using namespace std;

// void init_send(int serverfd, string password) {
// 	string msg = "NICK bot\n";
// 	char buffer[1024] = {0};

// 	if (send(serverfd, msg.c_str(), msg.length(), 0) == -1) {
// 		cout << "Error: send error\n";
// 		exit(1);
// 	}
// 	recv(serverfd, buffer, sizeof(buffer), 0);
// 	msg = "PASS " + password + "\n";
// 	if (send(serverfd, msg.c_str(), msg.length(), 0) == -1) {
// 		cout << "Error: send error\n";
// 		exit(1);
// 	}
// 	recv(serverfd, buffer, sizeof(buffer), 0);
// 	msg = "USER bot\n";
// 	if (send(serverfd, msg.c_str(), msg.length(), 0) == -1) {
// 		cout << "Error: send error\n";
// 		exit(1);
// 	}
// 	recv(serverfd, buffer, sizeof(buffer), 0);
// }

// int main(int ac, char **av) {
//     int sockfd;
//     struct sockaddr_in serv_addr;


// 	if (ac != 3) {
// 		cout << "usage: ./botclient <port> <password>\n";
// 		return 1;
// 	}

//     if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
//         return 1;

// 	istringstream iss(av[1]);
// 	int port;
// 	iss >> port;
//     serv_addr.sin_family = AF_INET;
//     serv_addr.sin_port = htons(port);

//     if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
//         cerr << "유효하지 않은 서버 주소" << endl;
//         return 1;
//     }

//     if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
//         cerr << "서버 연결 실패" << endl;
//         return 1;
//     }

//     cout << "서버에 연결되었습니다." <<endl;
// 	init_send(sockfd, av[2]);
//     while (true) {
//         char buffer[1024] = {0};
//         int recv_bytes = recv(sockfd, buffer, sizeof(buffer), 0);
//         if (recv_bytes <= 0) {
//             cerr << "server down\n";
//             break;
//         }
//         cout << "받은 메시지: " << buffer << endl;
// 		Bot bot(buffer);
// 		bot.sendToServer(sockfd);
//     }
//     close(sockfd);

//     return 0;
// }