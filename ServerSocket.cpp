//
// Created by appetitus on 03.09.23.
//

#include "ServerSocket.h"

ServerSocket::ServerSocket() {
    //Create a socket
    listeningSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (listeningSocket == -1) {
        cerr << "Can't create a socket!";
        exit(-1);
    }

    //Bind the socket to IP/port
    hint.sin_family = AF_INET;
    hint.sin_port = htons(1337);
    inet_pton(AF_INET, "127.0.0.1", &hint.sin_addr);

    if (bind(listeningSocket, (sockaddr *) &hint, sizeof(hint)) == -1) {
        cerr << "Can't bind to IP/port";
        exit(-2);
    }

    //Mark the socket is for listening
    if (listen(listeningSocket, SOMAXCONN) == -1) {
        cerr << "Can't listen!";
        exit(-3);
    }
}

int ServerSocket::acceptConnection() const {
    //Accept a call
    sockaddr_in client{};
    socklen_t clientSize = sizeof(client);

    int clientSocket = accept(listeningSocket, (sockaddr *) &client, &clientSize);

    if (clientSocket == -1) {
        cerr << "Problem with client connecting!";
        exit(-4);
    }

    return clientSocket;
}

void ServerSocket::closeSocket() const {
    //Close listening socket
    close(listeningSocket);
}
