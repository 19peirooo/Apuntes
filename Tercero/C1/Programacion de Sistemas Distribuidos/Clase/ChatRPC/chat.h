#pragma once
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


class Chat{

    private:

        vector<string> chat;
        int numMsgs;

    public:

        Chat();
        void showMsgs();
        void newMessage(string msg);
        ~Chat();
        vector<string> getChat();
        int getNumMsgs();

};
