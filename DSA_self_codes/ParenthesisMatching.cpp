#include<iostream>
using namespace std;

struct stack{
    int top;
    char *exp;
    int size;

};

void create(struct stack *st){
        cout<<("enter size : ");
        cin>>st->size;
        st->top=-1;
        st->exp=(char *)malloc(st->size*sizeof(int));
    }

void display(struct stack st){
    

}    



int main(){
   string expression = "([{}])";



}