//Víctor Manuel Peiró Martínez
#include <iostream>
#include <sstream>
#include "filemanager.h"

int main(int argc,char** argv)
{
	FileManager fm("FileManagerDir");
	string command;
	string fileName;
	string line;

	
	do{
		cout<<"Enter command:"<<endl;
		getline(cin,line);
		
		stringstream ss(line); 
		ss>>command;
		
		if(command=="ls")
		{
			cout<<"Listing files in local path"<<endl;
			experimental::filesystem::path directorypath="./";

			for (const auto& entry : 
					 directory_iterator(directorypath)) { 
					 if(is_regular_file(entry))
						cout<<entry.path()<<endl; 
				} 
			cout<<endl;
		}else if(command=="lls")
		{
			cout<<"Listing files fileManager path"<<endl;
			auto files=fm.listFiles();

			for (int i = 0; i < files.size(); i++) {
				cout << "File " << i+1 << ": " << files[i] << endl;
			}
		}else if(command=="upload")
		{
			ss>>fileName;
			if(fileName.length()>0)
			{
				cout<<"Coping file "<<fileName<<" in to the FileManager path"<<endl;
				ifstream file(fileName, ios::in | ios::binary | ios::ate);
				if(file.is_open()){
					vector<unsigned char> data;
					ifstream::pos_type fileSize = file.tellg();
					file.seekg(0, ios::beg);
					data.resize(fileSize);
					file.read((char*)data.data(), fileSize);
					file.close();
					cout<<"Reading file: "<<fileName<<" "<<data.size()<<" bytes"<<endl;
					fm.writeFile(fileName,data);
				}else{
					cout<<"ERROR: No such file \""<<fileName<<"\"found\n";
				}
				cout<<endl;
			}
		}else if(command=="download")
		{
			ss>>fileName;
			if(fileName.length()>0)
			{
				cout<<"Coping file "<<fileName<<" from the FileManager path in to local path"<<endl;
				ofstream file(fileName, ios::out | ios::binary);
				if(file.is_open()){
					vector<unsigned char> data;
					fm.readFile(fileName,data);
					file.write((char*)data.data(),data.size());
					file.close();
					cout<<"Writting file: "<<fileName<<" "<<data.size()<<" bytes"<<endl;
				}else{
					cout<<"ERROR: No such file \""<<fileName<<"\"found\n";
				}
				cout<<endl;
			}
		}else if(command=="lls")
		{
			cout<<"Listing files fileManager path"<<endl;
			auto files=fm.listFiles();

			for (const auto& entry : 
					 files) { 
					 	cout<<entry<<endl; 
				}
			cout<<endl;
		}else if(command=="exit()")
			cout<<"Exitting system"<<endl;
		else{
			cout<<"ERROR: command "<<command<<" not implemented"<<endl;
		}
		
	}while(command!="exit()");
    return 0;
}
