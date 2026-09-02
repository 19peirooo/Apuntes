#include "chat.h"

Chat::Chat() {
    this->numMsgs = 0;
}

void Chat::showMsgs(){
    for (auto& msg : this->chat) {
        cout << msg << endl;
    }
}

void Chat::newMessage(string msg){
    chat.push_back(msg);
    this->numMsgs++;
}

Chat::~Chat(){

}

vector<string> Chat::getChat() {
    return this->chat;
}

int Chat::getNumMsgs() {
    return this->numMsgs;
}