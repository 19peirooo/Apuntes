
#ifndef  _UTILS_H_
#define  _UTILS_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <thread>
#include <mutex>



#define DEBUG

#ifdef DEBUG

#define DEBUG_MSG(...)  printf(__VA_ARGS__);
#endif

typedef struct msg_t
{
    int size;
    unsigned char* data;
}msg_t;

typedef struct connection_t{
    unsigned int id;
    unsigned int serverId;
    int socket;
    std::list<msg_t*>* buffer;
    bool alive;
}connection_t;

int initServer(int port);
bool checkClient();
connection_t initClient(std::string host, int port);


template<typename t>
void sendMSG(int clientID, std::vector<t> &data);
template<typename t>
void recvMSG(int clientID, std::vector<t> &data);

int waitForConnections(int sock_fd);
void closeConnection(int clientID);
template<typename t>
void getMSG(int clientID, std::vector<t> &data);

bool checkPendingMessages(int clientID);
void recvMSGAsync(connection_t connection);
void waitForConnectionsAsync(int server_fd);

int getNumClients();
int getClientID(int numClient);
int getLastClientID();



extern std::map<unsigned int,connection_t> clientList;


template<typename t>
void recvMSG(int clientID, std::vector<t> &data){


    connection_t connection=clientList[clientID];

    int socket= connection.socket;

    int bufferSize=0;
    int readData=read(socket, &bufferSize, sizeof(int));
    DEBUG_MSG("DatosLeidos : %d\n",bufferSize);
	if(readData==0)
    {
       printf("ERROR: recvMSG -- line : %d lost connection\n", __LINE__);
    }
	
    int numElements=bufferSize/sizeof(t);
    data.resize(numElements);
    int remaining=bufferSize;
    int idxIn=0;
    while(remaining>0)
    {
        int bufferSizeBlock=read(socket, &(data.data()[bufferSize-remaining]),remaining);
        remaining-=bufferSizeBlock;        
    }
    
    if(remaining!=0)
    {
       printf("ERROR: recvMSG -- line : %d error data not matching: %d read, %d espected\n", __LINE__,remaining,bufferSize);
    }
}


template<typename t>
void sendMSG(int clientID, std::vector<t> &data){

    int dataLen=data.size()*sizeof(t);
    connection_t connection=clientList[clientID];

    int socket= connection.socket;

    //enviar tamaño buffer
    write(socket,&dataLen,sizeof(int));
    //enviar buffer
    write(socket,data.data(),dataLen);
}

template<typename t>
void getMSG(int clientID,std::vector<t> &data)
{
    if(!checkPendingMessages(clientID))
    {
	data.resize(0);
    }
    else
    {   msg_t* msg=clientList[clientID].buffer->front();
        clientList[clientID].buffer->pop_front();
        int numElem=msg->size/sizeof(t);
        data.resize(numElem);
        memcpy(data.data(),msg->data,msg->size);
	delete[] msg->data;
        delete[] msg;
    }
}



template<typename T>
inline void pack(std::vector<unsigned char> &packet,T data){
	
	int size=packet.size();
	unsigned char *ptr=(unsigned char*)&data;
	packet.resize(size+sizeof(T));
	std::copy(ptr,ptr+sizeof(T),packet.begin()+size);
	
}


template<typename T>
inline void packv(std::vector<unsigned char> &packet,T* data,int dataSize)
{
	for(int i=0;i<dataSize;i++)
			 	pack(packet,data[i]);
}



template<typename T>
inline T unpack(std::vector<unsigned char> &packet){	
	T data;
	long int dataSize=sizeof(T);
	int packetSize=packet.size();
	memcpy(&data,packet.data(),dataSize);
	memcpy(packet.data(),packet.data()+dataSize,packetSize-dataSize);
	packet.resize(packetSize-dataSize);
	return data;
}



template<typename T>
inline void unpackv(std::vector<unsigned char> &packet,T* data,int dataSize)
{
	dataSize*=sizeof(T);
	int packetSize=packet.size();
	memcpy(data,packet.data(),dataSize);
	memcpy(packet.data(),packet.data()+dataSize,packetSize-dataSize);
	packet.resize(packetSize-dataSize);
}

#endif

