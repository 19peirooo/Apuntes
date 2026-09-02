// C++ program to show the example of server application in

// socket programming
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

int count = 0; //Count como variable global para que los todos los threads puedan tener acceso a el

void connect_to_client(int clientSocket) {
    // -- Aqui trabaja con el cliente en concreto
    mtx.lock();
    count++;
    mtx.unlock();

    // recieving data
    char buffer[1024] = { 0 };
    recv(clientSocket, buffer, sizeof(buffer), 0);
    
    cout << "Message from client: " << buffer << " : " << count << endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    const char* message = "Hello, client!";

    send(clientSocket, message, strlen(message), 0);
    close(clientSocket);
}

int main() {

    // creating socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    // AF_INET - IPV4
    // SOCK_STREAM - TCP

    // specifying the address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080); // Transforma a binario - Ports < 1000 -> Requieren privilegios de ROOT
    serverAddress.sin_addr.s_addr = INADDR_ANY; // Acepta conexiones de cualquier IP 

    // binding socket.
    bind(serverSocket, (struct sockaddr*)&serverAddress,sizeof(serverAddress));
    
    // listening to the assigned socket
    listen(serverSocket, 5); // Acepta máximo 5 clientes en la cola
    while(1){
        // accepting connection request
        int clientSocket = accept(serverSocket, nullptr /*socket addr -- redundante */, nullptr /* Tamaño de estrucutra de socket addr*/);
        thread t(connect_to_client,clientSocket);
        t.join();
    }
     
    // closing the socket.
    close(serverSocket);
    return 0;

}