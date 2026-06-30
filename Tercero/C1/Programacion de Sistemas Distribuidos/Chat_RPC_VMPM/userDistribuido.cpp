#include "user.h"
#include "clientManager.h"
#include "utils.h"

User::User() {
    auto conn= initClient("127.0.0.1",3001);
    vector<unsigned char> buffer;

    pack(buffer,UserF);
    sendMSG(conn.serverId,buffer);
    buffer.clear();
    recvMSG(conn.serverId,buffer);

    auto ack=unpack<userFuncs>(buffer);
    if (ack != ackMSG) {
		cout<<"ERROR:"<<__FILE__<<":"<<__LINE__<<endl;
    } else {
        clientManager::connectionIds[this]=conn;
    }

}

User::User(string username){
    auto conn=initClient("127.0.0.1",3001);
	vector<unsigned char> buffer;

    pack(buffer, UserParamF);
    pack(buffer,(int)username.size());
    packv(buffer,(char*)username.data(), username.size());

    sendMSG(conn.serverId,buffer);
    buffer.clear();
    recvMSG(conn.serverId,buffer);

    auto ack=unpack<userFuncs>(buffer);
	if(ack!=ackMSG){
        cout<<"ERROR:"<<__FILE__<<":"<<__LINE__<<endl;
    }
	
	clientManager::connectionIds[this]=conn;

}

string User::getUsername(){
    string username;

    connection_t conn = clientManager::connectionIds[this];
    vector<unsigned char> buffer;

    pack(buffer,getUsernameF);
    sendMSG(conn.serverId,buffer);
    buffer.clear();
    recvMSG(conn.serverId,buffer);

    userFuncs ack=unpack<userFuncs>(buffer);
    if (ack!=ackMSG) {
        cout<<"ERROR:"<<__FILE__<<":"<<__LINE__<<endl;
    } else {
        username.resize(unpack<int>(buffer));
        unpackv<char>(buffer,(char*)username.data(), username.size());
    }
    return username;
}

void User::setUsername(string username){
    connection_t conn = clientManager::connectionIds[this];
    vector<unsigned char> buffer;

    pack(buffer, setUsernameF);
    pack(buffer,(int)username.size());
    packv(buffer,(char*)username.data(), username.size());

    sendMSG(conn.serverId,buffer);
    buffer.clear();
    recvMSG(conn.serverId,buffer);

    userFuncs ack = unpack<userFuncs>(buffer);
    if(ack!=ackMSG){
        cout<<"ERROR:"<<__FILE__<<":"<<__LINE__<<endl;
    }
}

string User::sendMsg(string msg){
    
    connection_t conn = clientManager::connectionIds[this];
    vector<unsigned char> buffer;

    pack(buffer,sendMsgF);
    pack(buffer,(int)msg.size());//empaquetar parametros
	packv(buffer,(char*)msg.data(), msg.size());

    sendMSG(conn.serverId,buffer);
    buffer.clear();
    recvMSG(conn.serverId,buffer);

    userFuncs ack = unpack<userFuncs>(buffer);
    if (ack != ackMSG) {
        cout<<"ERROR:"<<__FILE__<<":"<<__LINE__<<endl;
    }

    return msg;

}

void User::seeChat(){
    connection_t conn = clientManager::connectionIds[this];
    vector<unsigned char> buffer;

    pack(buffer,seeChatF);
    sendMSG(conn.serverId,buffer);
    buffer.clear();
    recvMSG(conn.serverId,buffer);

    userFuncs ack = unpack<userFuncs>(buffer);
    if (ack != ackMSG) {
        cout<<"ERROR:"<<__FILE__<<":"<<__LINE__<<endl;
    } else {
        int numMsgs = unpack<int>(buffer);

        Chat chatCopia;
        cout << "*****Historial*****" << endl;
        for (int i = 0; i < numMsgs; i++) {
            string temp;

            temp.resize(unpack<int>(buffer));
            unpackv(buffer,(char*)temp.data(),temp.size());

            chatCopia.newMessage(temp);
        }
        chatCopia.showMsgs();
    }
}

User::~User(){
    connection_t conn=clientManager::connectionIds[this];
	//empaquetar destructor
	
	vector<unsigned char> buffer;
	pack(buffer,UserDF);//)empaquetar tipo
	
	sendMSG(conn.serverId, buffer);//enviar peticion
	buffer.clear();
	recvMSG(conn.serverId, buffer);//recibir ack
	
	userFuncs ack=unpack<userFuncs>(buffer); 
	//si no ack, error
	if(ack!=ackMSG) cout<<"ERROR:"<<__FILE__<<":"<<__LINE__<<endl;

	closeConnection(conn.serverId);
}

