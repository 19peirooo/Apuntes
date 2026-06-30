//Víctor Manuel Peiró Martínez
#include "filemanager.h"

using namespace std;
namespace fs = std::experimental::filesystem; 
	
FileManager::FileManager() {
    this->dirPath="./";
    this->ready=false;
}

FileManager::~FileManager(){
    
}

FileManager::FileManager(string path) {
    try {
        fs::path p(path);
        if(!fs::exists(p)) {
            create_directory(p);
        }
        this->dirPath = path;
        this->ready = fs::is_directory(p);
    } catch(...) {
        this->ready = false;
        cout << "ERROR: No se pudo crear el FileManager";
    }
    
}

vector<string> FileManager::listFiles() {
    vector<string> file_names;
    if (ready) {
        try {
            for (const auto& file : fs::directory_iterator(this->dirPath)) {
                string file_name = file.path().filename().string();
                file_names.push_back(file_name);
            }
        } catch (...) {

        }
        
    }
    
    return file_names;
}

void FileManager::readFile(string fileName, vector<unsigned char> &data) {
    if (!ready) {
        cout << "ERROR: No se pudo leer el fichero" << endl;
        return;
    }

    try {
        fs::path file_path = fs::path(this->dirPath) / fileName;

        if (!fs::exists(file_path) || !fs::is_regular_file(file_path)){
            cout << "ERROR: No existe el fichero " << fileName << endl;
            return;
        }

        ifstream file(file_path,ios::in | ios::binary);
        if (!file.is_open()) {
            cout << "ERROR: No se pudo abrir el fichero " << fileName << endl;
            return;
        }

        int file_size = fs::file_size(file_path);
        data.resize(file_size);
        file.read((char*)data.data(),file_size);
        file.close();
    } catch (...) {
        cout << "ERROR: No se pudo leer el fichero" << endl;
        data.clear();
    }

}

void FileManager::writeFile(string fileName, vector<unsigned char> &data){
    if (!ready) {
        return;
    }
    try {
        fs::path file_path = fs::path(this->dirPath) / fileName;

        ofstream file(file_path,ios::out | ios::binary);
        if (!file.is_open()) {
            cout << "ERROR: No se pudo abrir el fichero " << fileName << endl;
            return;
        }

        if (!data.empty()) {
            file.write((char*)data.data(),data.size());
        } else {
            cout << "ERROR: No hay datos que escribir" << endl;
        }
        file.close();
    } catch (...) {
        cout << "ERROR: No se pudo escribir el fichero" << endl;
    }
    
}