//
// Created by appetitus on 03.09.23.
//

#ifndef TASK_CLIENTHANDLER_H
#define TASK_CLIENTHANDLER_H

#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <cstring>
#include <string>

using namespace std;

class ClientHandler {
private:
    int clientSocket;

public:
    ClientHandler(int socket);

    void handleClient() const;

    void processClientMessages() const;
};


#endif //TASK_CLIENTHANDLER_H
