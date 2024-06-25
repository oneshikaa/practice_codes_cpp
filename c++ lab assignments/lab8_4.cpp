#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){
    ifstream file("MySecrets.txt");
    string str;
    while(getline(file,str)){
        cout<<str<<endl;
    }
}