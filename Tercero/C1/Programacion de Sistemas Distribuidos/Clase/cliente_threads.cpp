// C++ program to illustrate the client application in the

// socket programming
#include <cstring>
#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

int main() {

    // creating socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    int status;

    // specifying address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
 
    //serverAddress.sin_addr.s_addr = INADDR_ANY;

    // Convert IPv4 and IPv6 addresses from text to binary

    // form

    if (inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr)<= 0) {

        printf("\nInvalid address/ Address not supported \n");
        return -1;

    }

    // sending connection request
    /*connect(clientSocket, (struct sockaddr*)&serverAddress,

            sizeof(serverAddress));*/

    if ((status = connect(clientSocket, (struct sockaddr*)&serverAddress,sizeof(serverAddress)))< 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    // sending data
    const char* message = "Hello, server!";
    send(clientSocket, message, strlen(message), 0);
    // recieving data

    char buffer[1024] = { 0 };

    recv(clientSocket, buffer, sizeof(buffer), 0);

    cout << "Message from client: " << buffer << endl;

    // closing socket
    close(clientSocket);

    return 0;

}
