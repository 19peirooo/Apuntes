//Víctor Manuel Peiró Martínez
#include "server.h"
#include <iostream>
#include <string>
#include <thread>
#include <list>

void server::atiendeCliente(int clientId) {
    fileFuncs tipoMsg;
    vector<unsigned char> buffer;
    do {
        recvMSG(clientId,buffer);
        tipoMsg = unpack<fileFuncs>(buffer);

        switch (tipoMsg) {
            case FileManagerF:{
                FileManager f;

                clients[clientId] = f;
                buffer.clear();
                pack(buffer,ackMSG);
            }break;
            case FileManagerParamsF: {
                string path = server::unpackString(buffer);

                FileManager f(path);
                clients[clientId] = f;
                buffer.clear();
                pack(buffer,ackMSG);

            }break;
            case FileManagerDF: {
                clients.erase(clientId);
                buffer.clear();
                pack(buffer,ackMSG);
            }break;
            case ListFilesF: {
                FileManager& f = clients[clientId]; // referencia
                vector<string> file_names = f.listFiles();
                
                buffer.clear();
                pack(buffer, ackMSG);
                server::packStrings(buffer,file_names);
            } break;
            case readFileF: {
                string file_name = server::unpackString(buffer);
                buffer.clear();
                pack(buffer,ackMSG);
                FileManager& f = clients[clientId];
                vector<unsigned char> data;
                f.readFile(file_name,data);
                server::packData(buffer,data);

            }break;
            case writeFileF: {
                cout << endl;
                string file_name = server::unpackString(buffer);
                vector<unsigned char> data = server::unpackData(buffer);

                FileManager& f = clients[clientId];
                f.writeFile(file_name,data);

                buffer.clear();
                pack(buffer,ackMSG);

            }break;
            default:{

            }break;
        }
        sendMSG(clientId,buffer);
    } while (tipoMsg != FileManagerDF);
    closeConnection(clientId);
}

int main(int argc, char** argv) {
    //init server
	int serverSocketID=initServer(3001);
	std::vector<unsigned char> buffer;
	//esperar conexion
	
	while(1){
		while(!checkClient()) usleep(100);
		
		std::cout<<"Cliente conectado\n";
		
		int clientId=getLastClientID();
		std::thread *th=new std::thread( server::atiendeCliente,clientId);
	}
	
	//cerrar
	close(serverSocketID);
    return 0;
}
