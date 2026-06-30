#include "user.h"
#include "clientManager.h"
#include "utils.h"

User::User() {
    this->username = "Random_User";
}

User::User(string username){
    this->username = username;
}

string User::getUsername(){
    return this->username;
}

void User::setUsername(string username){
    this->username = username;
}

string User::sendMsg(string msg){
    return msg;
}

void User::seeChat(){
    cout << "Imprimiendo MSGS" << endl;
}

User::~User(){
    
}