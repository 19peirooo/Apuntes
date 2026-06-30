//Víctor Manuel Peiró Martínez
#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "utils.h"

using namespace std;

typedef enum {
    addServerF,
    getIPF,
    getNumSalasF,

    closeBrokerF,
	killServerF,
    ackBroker
}brokerFuncs;

class Broker {

    public: 
        static inline map<int,string> servers;

        static void addServer(string ip);
        static string getServerIP(int sala);
        static int getNumSalas();
        static void atenderCliente(int clientId);

        static void packString(vector<unsigned char> &buffer,string s) {
			pack(buffer,(int)s.size());
			packv<char>(buffer,(char*)s.data(),(int)s.size());
		}

		static string unpackString(vector<unsigned char> &buffer) {
			int size = unpack<int>(buffer);
			string s;
			s.resize(size);
			unpackv<char>(buffer,(char*)s.data(),size);
			return s;
		}

        static string getServerToConnect(int brokerId) {
			vector<unsigned char> buffer;
			string server_ip;
			int sala = -1;
			pack(buffer,getNumSalasF);
			sendMSG(brokerId,buffer);
			buffer.clear();
			recvMSG(brokerId,buffer);

			brokerFuncs ack = unpack<brokerFuncs>(buffer);
			if (ack != ackBroker) {
				cout << "ERROR: No se pudo obtener el numero de salas" << endl;
				return NULL;
			}

			int num_salas = unpack<int>(buffer);
			cout << "Salas Disponibles: " << num_salas << endl;
			while (sala < 0 || sala >= num_salas) {
				cout << "Elige sala (0-" << num_salas-1 << "): ";
				cin >> sala;
				while (getchar() != '\n');

				if (sala < 0 || sala >= num_salas) {
					cout << "ERROR: Sala no disponible" << endl;
				}
			}

			buffer.clear();
			pack(buffer,getIPF);
			pack(buffer,(int)sala);

			sendMSG(brokerId,buffer);
			buffer.clear();
			recvMSG(brokerId,buffer);

			ack = unpack<brokerFuncs>(buffer);
			if (ack != ackBroker) {
				cout << "ERROR: No se pudo obtener ip del servidor";
				return NULL;
			} else {
				server_ip = Broker::unpackString(buffer);
				return server_ip;
			}
		}
        
        
        static void register_server(string broker_ip, string ip) {
            vector <unsigned char> buffer;
            auto conn_broker = initClient(broker_ip,3000);
            pack(buffer, addServerF);
            Broker::packString(buffer,ip);
            sendMSG(conn_broker.serverId,buffer);
            buffer.clear();
            recvMSG(conn_broker.serverId,buffer);

            brokerFuncs ack = unpack<brokerFuncs>(buffer);
            if (ack != ackBroker) {
                cout << "ERROR: No se pudo añadir servidor al broker" << endl;
            } else {
                cout << "Servidor añadido correctamente al broker" << endl;
            }
			Broker::close_broker(conn_broker.serverId);
        }

		static void close_broker(int clientId) {
			vector<unsigned char> buffer;
			pack<brokerFuncs>(buffer,closeBrokerF);
			sendMSG(clientId,buffer);
			buffer.clear();
			recvMSG(clientId,buffer);

			brokerFuncs ack = unpack<brokerFuncs>(buffer);
			if (ack != ackBroker) {
				cout << "ERROR: No se pudo cerrar la conexion." << endl;
			} else {
				closeConnection(clientId);
				cout << "Conexion Cerrada con exito" << endl;
			}
		}

};