#include<iostream>
using namespace std;

int number(int a){
    int counter = 0;
    while(a!=0){
        a = a/10;
        counter ++;
    }
    return counter;
}

int digit(int a){
    int c;
    while(a!=0){
        c = a%10;
        a = a/10;
    }

}

bool armstrong(int a){
    int d;
  //  d = digit(int a)

}



int main(){

}