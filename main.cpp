#include "ServerSocket.h"
#include "ClientHandler.h"

using namespace std;

int main() {
    ServerSocket server;
    while (true) {
        int clientSocket = server.acceptConnection();
        ClientHandler clientHandler(clientSocket);
        clientHandler.handleClient();
    }

    return 0;
}