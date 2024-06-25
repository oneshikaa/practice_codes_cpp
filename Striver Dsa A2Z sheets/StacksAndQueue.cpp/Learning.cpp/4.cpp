#include <iostream>
using namespace std;

class stack
{
    int top;
    int size;
    int *arr;

public:
    stack()
    {
        top = -1;
        cout << "enter size";
        cin>>size;
        arr = new int[size];
    }
    void push(int x)
    {
        if (top == size - 1)
        {
            cout << "overflow";
        }
        else
        {
            top++;
            arr[top] = x;
        }
    }
    int pop()
    {
        int x = -1;
        if (top == -1)
        {
            cout << "underflow";
        }
        else
        {
            int x = arr[top];
            top--;
        }
        return x;
    }
    int top_ele()
    {
        return arr[top];
    }
    void display()
    {
        for (int i = top; i >=0; i--)
        {
            cout << arr[i] << " ";
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        return false;
    }

};

class queue{
    stack s1,s2;

public :
    void enqueue(int x){
        while (!s1.isEmpty())
        {
            s2.push(s1.top_ele());
            s1.pop();
        }
        s1.push(x);
          while (!s2.isEmpty())
        {
            s1.push(s2.top_ele());
            s2.pop();
        }
    }

    int dequeue(){
        if (s1.isEmpty())
        {
            return -1;
        }

        return s1.pop();
    }

    void diplay_q(){
        s1.display();
    }

};

int main(){
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.dequeue();
    q.diplay_q();


}