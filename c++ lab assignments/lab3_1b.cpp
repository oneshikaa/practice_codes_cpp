#include<iostream>
using namespace std;

class A{
    int a;

    public :

    void setData(){
        cout<<"enter the value of integer "<<endl;
        cin>>a;
    }

    void getData(){
        cout<<"the value of the integer is "<<a<<endl;
    }
};

int main(){
    A *ptr = new A[3];

    for(int i = 0;i<3;i++){
        ptr[i].setData();
        ptr[i].getData();
    }

    return 0;
}