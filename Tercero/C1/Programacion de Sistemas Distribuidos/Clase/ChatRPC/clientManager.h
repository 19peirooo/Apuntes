#pragma once
#include "utils.h"
#include "user.h"
#include "chat.h"
using namespace std;
typedef enum{

	UserF,
	UserParamF,
	UserDF,
	getUsernameF,
	setUsernameF,
	sendMsgF,
	seeChatF,
	
	ackMSG
}userFuncs;

class clientManager{

		public:

			static inline Chat* chat = new Chat();

			static inline map<int, User> clients;
			static inline map<User*,connection_t > connectionIds;
			
			static inline bool salir=false;			
			static void atiendeCliente(int clientId);
};
