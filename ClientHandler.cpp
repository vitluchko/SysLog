//
// Created by appetitus on 03.09.23.
//

#include "ClientHandler.h"

ClientHandler::ClientHandler(int socket) : clientSocket(socket) {}

void ClientHandler::handleClient() const {
    //Wait for a connection
    sockaddr_in client{};
    socklen_t clientSize = sizeof(client);
    char host[NI_MAXHOST];  //Client's remote name
    char svc[NI_MAXSERV];   //Service (i.e. port) the client is connected on

    memset(host, 0, NI_MAXHOST);
    memset(svc, 0, NI_MAXSERV);

    int result = getnameinfo((sockaddr *) &client, sizeof(client),
                             host, NI_MAXHOST, svc, NI_MAXSERV, 0);

    if (result) {
        cout << host << " connected on " << svc << endl;
    } else {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " connected on " << ntohs(client.sin_port) << endl;
    }

    //Process client messages
    processClientMessages();

    close(clientSocket);
}

void ClientHandler::processClientMessages() const {
    //While loop: accept and echo message back to client
    char buffer[4096];
    while (true) {
        memset(buffer, 0, 4096);
        int bytesRecv = recv(clientSocket, buffer, 4096, 0);
        if (bytesRecv == -1) {
            cerr << "There was a connection issue" << endl;
            break;
        }
        if (bytesRecv == 0) {
            cout << "The client disconnected" << endl;
            break;
        }

        //Process and send the message
        string command = "tail -f /var/log/syslog";
        system(command.c_str());

        FILE *pipe = popen(command.c_str(), "r");
        while (true) {
            if (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
                send(clientSocket, buffer, bytesRecv + 1, 0);
            }
        }
    }
}
