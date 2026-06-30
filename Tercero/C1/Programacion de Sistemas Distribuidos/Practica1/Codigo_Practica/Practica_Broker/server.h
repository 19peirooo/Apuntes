//Víctor Manuel Peiró Martínez
#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "utils.h"
#include "filemanager.h"

using namespace std;

typedef enum{

	FileManagerF,
	FileManagerParamsF,
	FileManagerDF,
	ListFilesF,
	readFileF,
	writeFileF,

	closeServerF,
	ackMSG
}fileFuncs;

class server {
    public:

        static inline map<int, FileManager> clients;
        static inline map<FileManager*,connection_t > connectionIds;
        
        static inline bool salir=false;			
        static void atiendeCliente(int clientId);

		static void packString(vector<unsigned char> &buffer,string s) {
			pack(buffer,(int)s.size());
			packv<char>(buffer,(char*)s.data(),(int)s.size());
		}

		static void packData(vector<unsigned char>& buffer, vector<unsigned char> data) {
			pack(buffer,(int)data.size());
			packv<unsigned char>(buffer,(unsigned char*)data.data(),(int)data.size());
		}

		static void packStrings(vector<unsigned char>& buffer, vector<string> strings) {
			pack(buffer,(int)strings.size());
			for (string s : strings) {
				packString(buffer,s);
			}
		}

		static string unpackString(vector<unsigned char> &buffer) {
			int size = unpack<int>(buffer);
			string s;
			s.resize(size);
			unpackv<char>(buffer,(char*)s.data(),size);
			return s;
		}

		static vector<unsigned char> unpackData(vector<unsigned char>& buffer) {
			int size = unpack<int>(buffer);
			vector<unsigned char> data;
			data.resize(size);
			unpackv<unsigned char>(buffer,(unsigned char*)data.data(),size);
			return data;
		}

		static vector<string> unpackStrings(vector<unsigned char>& buffer) {
			int size = unpack<int>(buffer);
			vector<string> strings;
			while (size > 0) {
				string s = unpackString(buffer);
				strings.push_back(s);
				size--;
			}
			return strings;
		}

};