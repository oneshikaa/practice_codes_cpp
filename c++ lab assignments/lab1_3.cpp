#include<iostream>
using namespace std;

namespace ns1{
    int x = 3;
    int value(){
        return 1;
    }
}

namespace ns2{
    float x = 3.0;
    float value(){
        return 1.0;
    }
}

namespace ns3{

}

int main(){
    cout<<ns1::value()<<endl;
    cout<<ns2::value()<<endl;
    cout<<ns1::x<<endl;
    cout<<ns2::x<<endl;

    return 0;
}