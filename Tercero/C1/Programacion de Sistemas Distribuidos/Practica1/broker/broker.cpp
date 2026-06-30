#include "broker.h"

int Broker::getNumSalas() {
    return servers.size();
}

void Broker::addServer(string ip) {
    servers[getNumSalas()] = ip;
}

string Broker::getServerIP(int sala) {
    if (sala >= 0 && sala < getNumSalas()) {
        return servers[sala];
    }
    return NULL;
}

void Broker::atenderCliente(int clientId) {
    brokerFuncs tipoMsg;
    vector<unsigned char> buffer;

    do {
        recvMSG(clientId,buffer);

        tipoMsg = unpack<brokerFuncs>(buffer);

        switch (tipoMsg) {
            case addServerF:{
                string ip = Broker::unpackString(buffer);

                if (!ip.empty()) {
                    addServer(ip);
                    buffer.clear();
                    cout << "Se añadio el servidor con IP: " << ip << endl;
                    pack(buffer,ackBroker);
                } else {
                    cout << "ERROR: No se pudo conectar al broker";
                }
            }break;

            case getIPF:{
                int sala = unpack<int>(buffer);
                buffer.clear();
                pack(buffer,ackBroker);
                string brokerIp = getServerIP(sala);
                Broker::packString(buffer,brokerIp);
            }break;

            case getNumSalasF:{
                int num_salas = getNumSalas();
                buffer.clear();
                pack(buffer,ackBroker);
                pack(buffer,(int)num_salas);
            }break;

            case closeBrokerF:{
                cout << "Cerrando Conexion" << endl;
            }break;

            default: {
                cout << "ERROR: Peticion Invalida" << endl;
            }break;
        }
        sendMSG(clientId,buffer);
    } while (tipoMsg != closeBrokerF);
}

int main() {
    cout << "Launching Broker" << endl;
    //init server
	int serverSocketID=initServer(3000);
	std::vector<unsigned char> buffer;
	//esperar conexion
	
	while(1){
		while(!checkClient()) usleep(100);
		
		std::cout<<"Cliente conectado\n";
		
		int clientId=getLastClientID();
		std::thread *th=new std::thread(Broker::atenderCliente,clientId);
	}
	
	//cerrar
	close(serverSocketID);
    return 0; 
}