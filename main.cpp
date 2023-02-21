#include <iostream>
#include <tuple>
#include "Network/Server.h"
#include "Network/Client.h"
#include "Arithmetic/Modulus.h"

using namespace Network_Server;
using namespace Network_Client;
int mainTest() {
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
    std::cout << "PGCD {5;12} : " << Mod::pgcd(15,7) << "\n";
    std::tuple<int,int,int> res = Mod::pgcdEtendu(35,15);
    std::cout << "PGCD Etendu {35,15}\nAttendu [5;1;-2] | Recu [" ;
    std::cout << std::get<0>(res) << ";" ;
    std::cout << std::get<1>(res) << ";" ;
    std::cout << std::get<2>(res) << "]\n" ;
    std::cout << "Attendu {13}, reçu {" << Mod::fractionMod(12,15) << "}\n";
    return 0;
}
