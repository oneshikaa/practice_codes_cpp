#include<iostream>
using namespace std;

class Queue{

    int size;
    int front;
    int rear;
    int *Q;

    public :

    Queue(int size){

        this->size = size;
        front=rear = 0;
        Q = new int [size];
 
    }

     
    ~Queue() {
         delete [] Q;
    }

    void enqueue(int x){
        if((rear+1)%size==front){
            cout<<"queue is full"<<endl;
            }
        else{
            rear = (rear+1)%size;
            Q[rear] = x;

        }    

    }

    void dequeue(){
        //int x = -1;

        if(front==rear){
            cout<<"queue is empty"<<endl;
        }

        else{
            front = (front+1)%size;
           // x = Q[front];

        }
        //return x;
    }

    void display(){
        int i = front+1;

        do{
            cout<<Q[i]<<" ";
            i = (i+1)%size; 

        }while(i!= (rear+1)%size);
    }

};

 int main(){

    Queue q(4);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    //q.enqueue(40);

    q.display();

    q.dequeue();
    cout<<endl;
    

    q.display();

    return 0;

 }