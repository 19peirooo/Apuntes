#pragma once
#include <iostream>
#include <cstring>
#include "chat.h"

using namespace std;

class User{

    private:
        string username;

    public:
        User();
        User(string username);
        string getUsername();
        void setUsername(string username);
        string sendMsg(string msg);
        void seeChat();
        ~User();

};

