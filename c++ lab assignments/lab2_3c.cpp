#include<iostream>
using namespace std;


class X{
static int i;
public:void show()
{cout<<"i ="<<i<<endl;}
};

int X::i=1;

int main(){
X obj;
 obj.show();
}
