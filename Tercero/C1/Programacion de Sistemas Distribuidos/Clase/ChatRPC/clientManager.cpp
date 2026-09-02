#include "clientManager.h"

void clientManager::atiendeCliente(int clientId){
	userFuncs tipoMsg;
	std::vector<unsigned char> buffer;
	//repetir
	do{
		//recibir mensaje
		recvMSG(clientId, buffer);
		//desempaquetar tipo de mensaje
		tipoMsg=unpack<userFuncs>(buffer);
		
		switch (tipoMsg) {

			case UserF:{
				User user;

				clients[clientId] = user;
				buffer.clear();
				pack(buffer,ackMSG);
			}break;

			case UserParamF:{
				string username;

				username.resize(unpack<int>(buffer));
				unpackv<char>(buffer,(char*)username.data(),username.size());
				
				User user(username);

				clients[clientId] = user;
				buffer.clear();
				pack(buffer,ackMSG);

			}break;
			case UserDF:{
				clients.erase(clientId);
				buffer.clear();
				pack(buffer,ackMSG);
			}break;
			case getUsernameF:{
				string username = clients[clientId].getUsername();

				pack(buffer,ackMSG);
				pack(buffer,(userFuncs)username.size());
				packv(buffer,(char*)username.data(),username.size());

			}break;

			case setUsernameF:{
				string username;
				username.resize(unpack<int>(buffer));
				unpackv<char>(buffer,(char*)username.data(),username.size());

				clients[clientId].setUsername(username);
				buffer.clear();
				pack(buffer,ackMSG);

			}break;

			case sendMsgF:{

				string msg;
				msg.resize(unpack<int>(buffer));
				unpackv<char>(buffer,(char*)msg.data(),msg.size());
				string full_msg = clients[clientId].getUsername()+": " + msg;
				chat->newMessage(full_msg);
				buffer.clear();
				pack(buffer,ackMSG);

			}break;
			case seeChatF:{
				pack(buffer,ackMSG);
				vector<string> history = chat->getChat();
				pack(buffer,chat->getNumMsgs());

				for (auto& msg: history) {
					pack(buffer,(int)msg.size());
					packv(buffer,(char*)msg.data(),msg.size());
				}
			}break;
		
			default:{
				cout << "ERROR: Tipo de Mensaje no valido" << endl;
			}break;
		}
		sendMSG(clientId,buffer);
	}while(tipoMsg != UserDF);
	closeConnection(clientId);
}