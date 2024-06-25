#include<iostream>
using namespace std;

int main(){
    char *str = "data stucture";
    char stack[30];
    int i =0;
    int top =0;
    while(str[i]!=0){
        if(str[i]!=32){
            stack[top]=str[i];
            top++;
        }
        i++;
    }
    i =top-1;
    while(i>=0){
        cout<<stack[i];
        i--;
    }
}