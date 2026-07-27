#include <iostream>
#include <string>
using namespace std;

int main() {
    string alpahbet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key{"ZYXWVUTSRQPONMLKJIHGFEDCBAzyxwvutsrqponmlkjihgfedcba"};
    string msg;
    cout<<"Enter message : ";getline(cin,msg);
    string encripted;
    for(char ch : msg)
    {
        auto pos = alpahbet.find(ch);
        if(pos != string::npos)
        {
            encripted.push_back(key.at(pos));
        }
        else
        encripted.push_back(ch);
    }
    cout<<"Encirpted messages : "<<encripted<<endl;

    string decripted;
    for(auto ch: encripted)
    {
        auto pos = key.find(ch);
        if(pos != string::npos)
        {
            decripted.push_back(alpahbet.at(pos));
        }
        else
        decripted.push_back(ch);
    }
    cout<<"Decripted message : "<<decripted<<endl;
    
    return 0;
}