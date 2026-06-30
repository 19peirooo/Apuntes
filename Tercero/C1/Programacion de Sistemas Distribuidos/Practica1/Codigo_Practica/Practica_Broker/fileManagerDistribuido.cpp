//Víctor Manuel Peiró Martínez
#include "filemanager.h"
#include "server.h"
#include "broker.h"


FileManager::FileManager() {

    string ip_broker, ip_server;
	cout << "IP del Broker: ";
	getline(cin,ip_broker);

	auto conn_broker = initClient(ip_broker, 3000);
	ip_server = Broker::getServerToConnect(conn_broker.serverId);
	cout << "Se ha conectado al servidor con IP: " << ip_server << endl;
	Broker::close_broker(conn_broker.serverId);

    auto conn = initClient(ip_server,3001);
    vector<unsigned char> buffer;

    pack(buffer,FileManagerF);
    sendMSG(conn.serverId,buffer);
    buffer.clear();
    recvMSG(conn.serverId,buffer);

    fileFuncs ack = unpack<fileFuncs>(buffer);
    if (ack != ackMSG) {
        cout << "ERROR: No se pudo instanciar el FileManager" << endl;
    } else {
        server::connectionIds[this] = conn;
    }

}

FileManager::~FileManager() {
    connection_t conn = server::connectionIds[this];
    vector<unsigned char> buffer;

    pack(buffer,FileManagerDF);
    sendMSG(conn.serverId,buffer);
    buffer.clear();
    recvMSG(conn.serverId,buffer);

    fileFuncs ack = unpack<fileFuncs>(buffer);
    if (ack != ackMSG) {
        cout << "ERROR: No se pudo destruir el FileManager" << endl;
    } else {
        closeConnection(conn.serverId);
    }

}

FileManager::FileManager(string path) {

    string ip_broker, ip_server;
	cout << "IP del Broker: ";
	getline(cin,ip_broker);

	auto conn_broker = initClient(ip_broker, 3000);
	ip_server = Broker::getServerToConnect(conn_broker.serverId);
	cout << "Se ha conectado al servidor con IP: " << ip_server << endl;
	Broker::close_broker(conn_broker.serverId);

    auto conn = initClient(ip_server,3001);
    vector<unsigned char> buffer;

    pack(buffer,FileManagerParamsF);
    server::packString(buffer,path);
    sendMSG(conn.serverId,buffer);
    buffer.clear();
    recvMSG(conn.serverId,buffer);

    fileFuncs ack = unpack<fileFuncs>(buffer);
    if (ack != ackMSG) {
        cout << "ERROR: No se pudo instanciar el FileManager" << endl;
    } else {
        server::connectionIds[this] = conn;
    }

}

vector<string> FileManager::listFiles() {
    connection_t conn = server::connectionIds[this];
    vector<unsigned char> buffer;
    vector<string> files;

    pack(buffer, ListFilesF);
    sendMSG(conn.serverId, buffer);
    buffer.clear();
    recvMSG(conn.serverId, buffer);

    fileFuncs ack = unpack<fileFuncs>(buffer);
    if (ack != ackMSG) {
        cout << "Error: no se recibió ackMSG del servidor" << endl;
    } else {
        files = server::unpackStrings(buffer);
    }
    return files;
}


void FileManager::readFile(string fileName, vector<unsigned char> &data) {
    connection_t conn = server::connectionIds[this];
    vector<unsigned char> buffer;

    pack(buffer,readFileF);
    server::packString(buffer,fileName);

    sendMSG(conn.serverId,buffer);
    buffer.clear();
    recvMSG(conn.serverId,buffer);

    fileFuncs ack = unpack<fileFuncs>(buffer);
    if (ack != ackMSG) {
        cout << "ERROR: No se pudo leer el fichero" << endl;
    } else {
        data.clear();
        data = server::unpackData(buffer);
    }

}

void FileManager::writeFile(string fileName, vector<unsigned char> &data) {
    connection_t conn = server::connectionIds[this];
    vector<unsigned char> buffer;

    pack(buffer,writeFileF);
    server::packString(buffer,fileName);
    server::packData(buffer,data);

    sendMSG(conn.serverId,buffer);
    buffer.clear();
    recvMSG(conn.serverId,buffer);

    fileFuncs ack = unpack<fileFuncs>(buffer);
    if (ack != ackMSG) {
        cout << "ERROR: No se pudo leer el fichero" << endl;
    }
}