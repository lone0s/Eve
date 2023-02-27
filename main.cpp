#include <iostream>
#include "Network/Server.h"
#include "Network/Client.h"
#include "Arithmetic/EllipticCurve.h"

using namespace Network_Server;
using namespace Network_Client;
int mainServer() {
    std::cout << " whoami?\n !root :((" << std::endl;
    std::string ip = "127.0.0.1";
    size_t port = 8000;
    Server server(ip, port);
    Client iencli(ip,port);
    int res = server.bindServer();
    res == SOCKET_ERROR ? std::cout << "Error binding:  " << WSAGetLastError() << std::endl : std::cout << "Successfull binding\n";
    res = server.listenServer();
    res == SOCKET_ERROR ? std::cout << "Error listening: " << WSAGetLastError() << std::endl : std::cout << "Successfully listening\n";
    res = iencli.connectClient();
    res == SOCKET_ERROR ? std::cout << "ERROR !!!\n" << WSAGetLastError() << std::endl : std::cout << "Successfully connected client to remote server\n";
    server.acceptConnection();
    std::cout << "Trying communications \n";
    res = iencli.sendMessage("Test, 1st communication <3\n");
    res == SOCKET_ERROR ? std::cout << "Error send: " << WSAGetLastError() << std::endl : std::cout << "Sent message :)\n";
    std::cout << server.readCommunications();
    return 0;
}

int main() {
    EllipticCurve ECC (7, 3, 4);
    Point<long long> P {1,1};
    Point<long long> Q {2,5};
//    Point<long long> res = ECC.addition(*new Point<long long>{2,2}, *new Point<long long>{2,2});
    Point<long long> res = ECC.addition(P, Q);
    std::cout << "Attendu: [6,0] | Recu : [" << res.x << "," << res.y << "]\n";
    return 0;
}