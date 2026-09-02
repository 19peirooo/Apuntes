#include "persona.h"
#include "clientManager.h"

Persona::Persona(){
	auto conn=initClient("127.0.0.1",3001);
	vector<unsigned char> buffer;
	
	pack(buffer,PersonaF);
	sendMSG(conn.serverId, buffer);
	buffer.clear();
	recvMSG(conn.serverId, buffer);
	
	auto ack=unpack<personaFuncs>(buffer);
	if(ack!=ackMSG) 
		cout<<"ERROR:"<<__FILE__<<":"<<__LINE__<<endl;
	else
		clientManager::connectionIds[this]=conn;
}

Persona::Persona(string nombre, int edad){
	auto conn=initClient("127.0.0.1",3001);
	vector<unsigned char> buffer;
	
	pack(buffer,PersonaParamsF);
	pack(buffer,(int)nombre.size());
	packv(buffer,(char*)nombre.data(), nombre.size());
	pack(buffer,(int)edad);
	
	sendMSG(conn.serverId, buffer);
	buffer.clear();
	recvMSG(conn.serverId, buffer);
	
	auto ack=unpack<personaFuncs>(buffer);
	if(ack!=ackMSG) cout<<"ERROR:"<<__FILE__<<":"<<__LINE__<<endl;
	
	clientManager::connectionIds[this]=conn;
	
}
Persona::~Persona(){
	connection_t conn=clientManager::connectionIds[this];
	//empaquetar destructor
	
	vector<unsigned char> buffer;
	pack(buffer,PersonaDF);//)empaquetar tipo
	
	sendMSG(conn.serverId, buffer);//enviar peticion
	buffer.clear();
	recvMSG(conn.serverId, buffer);//recibir ack
	
	personaFuncs ack=unpack<personaFuncs>(buffer); 
	//si no ack, error
	if(ack!=ackMSG) cout<<"ERROR:"<<__FILE__<<":"<<__LINE__<<endl;

	closeConnection(conn.serverId);
}
	
void Persona::setNombre(string nombre){
		//empaquetar tipo
		//enviar
		//recvMSG
		connection_t conn=clientManager::connectionIds[this];
		//empaquetar destructor

		vector<unsigned char> buffer;
		pack(buffer,setNombreF);//)empaquetar tipo
		pack(buffer,(int)nombre.size());//empaquetar parametros
		packv(buffer,(char*)nombre.data(), nombre.size());

		sendMSG(conn.serverId, buffer);//enviar peticion
		
		//recv ack
		buffer.clear();
		recvMSG(conn.serverId, buffer);
		
		personaFuncs ack=unpack<personaFuncs>(buffer);
		if(ack!=ackMSG) cout<<"ERROR:"<<__FILE__<<":"<<__LINE__<<endl;

	
}
void Persona::setEdad(int edad){
	
	//empaquetar tipo
		//enviar
		//recvMSG
		connection_t conn=clientManager::connectionIds[this];
		//empaquetar destructor

		vector<unsigned char> buffer;
		pack(buffer,setEdadF);//empaquetar tipo
		pack(buffer,(int)edad);//empaquetar parametros
		
		sendMSG(conn.serverId, buffer);//enviar peticion
		
		//recv ack
		buffer.clear();
		recvMSG(conn.serverId, buffer);
		
		personaFuncs ack=unpack<personaFuncs>(buffer);
		if(ack!=ackMSG) cout<<"ERROR:"<<__FILE__<<":"<<__LINE__<<endl;
	
	
	
}
string Persona::getNombre(){
	
	//empaquetar tipo
	//enviar
	//recvMSG
	string nombre;
	connection_t conn=clientManager::connectionIds[this];
	//empaquetar destructor

	vector<unsigned char> buffer;
	pack(buffer,getNombreF);//)empaquetar tipo
	sendMSG(conn.serverId, buffer);//enviar peticion

	buffer.clear();
	recvMSG(conn.serverId, buffer);

	personaFuncs ack=unpack<personaFuncs>(buffer);
	if(ack!=ackMSG) 
		cout<<"ERROR:"<<__FILE__<<":"<<__LINE__<<endl;
	else{
		nombre.resize(unpack<int>(buffer));
		unpackv<char>(buffer,(char*)nombre.data(),nombre.size());
	}
	return nombre;
		
		//desempaquetar ack
		//si ack
			//desempaquetar tamaño
			//resize
			//desempaquetar data()
		//else ERROR
		
	
	
}
int Persona::getEdad(){
	
	//empaquetar tipo
	//enviar
	//recvMSG
	int edad;
	connection_t conn=clientManager::connectionIds[this];
	//empaquetar destructor

	vector<unsigned char> buffer;
	pack(buffer,getEdadF);//)empaquetar tipo
	sendMSG(conn.serverId, buffer);//enviar peticion

	buffer.clear();
	recvMSG(conn.serverId, buffer);

	personaFuncs ack=unpack<personaFuncs>(buffer);
	if(ack!=ackMSG) 
		cout<<"ERROR:"<<__FILE__<<":"<<__LINE__<<endl;
	else{
		edad=unpack<int>(buffer);	
	}
	return edad;
	
	
}








