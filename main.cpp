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
    EllipticCurve<int> ECC (7, 3, 4);
    Point<int> P {1,1};
    Point<int> Q {2,5};
    Point<int> res1 = ECC.addition(P, Q);

    std::cout << "Attendu: [6,0] | Recu : [" << res1.x << "," << res1.y << "]\n";
    Point<int> X {2,2};

    X = ECC.addition(X,X);
    std::cout << "Attendu: [0,2] | Recu : [" << X.x << "," << X.y << "]\n";

    EllipticCurve<int64_t> ECCBis (17,2,3);
    Point<int64_t> R {5,11};
    Point<int64_t> res = ECCBis.addition(R, R);
    std::cout << "Attendu: [15,5] | Recu : [" << res.x << "," << res.y << "]\n";

    std::cout << "A: 10 | R : " << ECC.numberOfPoints() << "\n";


    return 0;

}