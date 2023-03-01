#include <iostream>
#include <set>
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

int oldTestECCmain() {
    EllipticCurve<int> ECC ( 3, 4,7);
    Point<int> P {1,1};
    Point<int> Q {2,5};
    Point<int> res1 = ECC.addition(P, Q);

    std::cout << "Attendu: [6,0] | Recu : [" << res1.x << "," << res1.y << "]\n";
    Point<int> X {2,2};

    X = ECC.addition(X,X);
    std::cout << "Attendu: [0,2] | Recu : [" << X.x << "," << X.y << "]\n";

    EllipticCurve<int64_t> ECCBis (2,3, 17);
    Point<int64_t> R {5,11};
    Point<int64_t> res = ECCBis.addition(R, R);
/*
    std::cout << "Attendu: [15,5] | Recu : [" << res.x << "," << res.y << "]\n";

    std::cout << "A: 10 | R : " << ECC.numberOfPoints() << "\n";

*/
//    std::cout << "A: " << true << " | R: " << ECCBis.pointIsOnCurve(*new Point<int64_t>{17,0});
//    std::cout << "A: " << false << " | R: " << ECCBis.pointIsOnCurve(*new Point<int64_t>{17,1});

    return 0;

}


//Verify generatorPoint foo

int main() {
    EllipticCurve<int64_t> ECC (2, 3,97);
//    std::cout << "A: 10 | R : " << ECC.order() << "\n";
    std::vector<Point<int64_t>> res;
    std::set<Point<int64_t>> set;
    std::set<Point<int64_t>> generators;
    for (size_t i = 0 ; i < 100000 ; ++i) {
        generators.insert(ECC.generatorPoint());
    }
    std::cout << "Order of generator Points\n";
    for(auto ge : generators) {
        std::cout << "[" << ge.x << ";" << ge.y << "] ==> [";
        try { std::cout << ECC.generatorPointOrder(ge) << "] ";}
        catch (std::exception &e) { std::cout << "-1] " ;}
    }
    std::cout << "\n";
    std::cout << "Order of generator Points\n";
    bool onCurv = true;
    for(auto ge : generators)
        onCurv = onCurv & ECC.pointIsOnCurve(ge);
    std::cout << "A: " << true << " R: " << onCurv << "\n";
/*

    for(auto& gene: generators) {
        set.insert(ECC.generateInfinityPoint());
//        Point<int64_t> generator{3, 6};
        Point<int64_t> gen = gene;
        ECC.generatorPoint();
        std::cout << "================\n";
        std::cout << "{" << gen.x << ";" << gen.y << "}\n";
        std::cout << "================\n";

        set.insert(gen);
        for (size_t i = 0; i < ECC.order()*1000; ++i) {
            Point<int64_t> temp = ECC.addition(gen, gen);
            gen = temp;
            set.insert(gen);
        }
        for (auto elem: set)
            std::cout << "{" << elem.x << ";" << elem.y << "} | ";
        std::cout << "\nSize: " << set.size() << "\n";
        set.clear();
    }
*/

    std::cout << ECC.order() << "\n";
    return 0;
}