//
// Created by appetitus on 03.09.23.
//

#ifndef TASK_SERVERSOCKET_H
#define TASK_SERVERSOCKET_H

#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <cstring>
#include <string>

using namespace std;

class ServerSocket {
private:
    int listeningSocket;
    sockaddr_in hint{};

public:
    ServerSocket();

    int acceptConnection() const;

    void closeSocket() const;
};

#endif //TASK_SERVERSOCKET_H
