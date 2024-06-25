#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int x = -3;
    long y = 3.456678;
    cout<<showpos<<x<<endl;
    cout<<noshowpos<<x<<endl;
    cout<<setprecision(6)<<y<<endl;
    cout<<setw(4)<<y;

    return 0;



}