#include "clientlib.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <signal.h>

using namespace std;

void PrintHelp() {
    cout << "====Help====\n"
        << " <enter>  - check for incoming message\n"
        << " :h       - help\n"
        << " :ls      - display chat users list\n"
        << " :to      - switch message reciever\n"
        << " :q       - quit\n\n"
}


int main(int argc, char**argv) {
    signal(SIGPIPE, SIG_IGN);

    string ip;
    int port = 0;
    cout << "Server IP and port: ";
    cin >> ip >> port;

    TClient client(ip, port);
    if (!client.Connect())
        return 0;

    string login, pass;
    cout << "Login: ";
    cin >> login;
    cout << "Password: ";
    cin >> pass;
    string fictive;
    getline(cin, fictive);
    if (!client.SignIn(login, pass)) {
        cout << "Failed to sign in.\n";
        client.SignOut();
        return 0;
    }

    PrintHelp();
    string recieve("server");
    while (true) {
        cout << "[" << login << " -> " << reciever << "] $ ";
        string line;
        getline(cin, line);
        if (line == ":q")
            break;

        const vector<TMessageText>& text = client.GetText();
        if (!text.empty()) {
            cout << "======New Message=====\n";
            for (size_t i = 0; i < text.size(); ++i)

        }
    }
}