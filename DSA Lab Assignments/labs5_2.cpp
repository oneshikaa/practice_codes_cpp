#include<iostream>
using namespace std;

int queue[100];
int size;
int front=-1,rear=-1;

void enqueue(int data){

if((rear+1)%size==front){
cout<<"Queue is full";
}
else if(front==-1 && rear==-1){
front=rear=0;
queue[rear]=data;
cout<<"Data added"<<endl;
}
else{
rear=(rear+1)%size;
queue[rear]=data;
cout<<"Data added"<<endl;
}

}
void dequeue(){
int data;
if(front==-1&&rear==-1){
cout<<"Empty queue"<<endl;
}
else if(front==rear){
front=rear=-1;
}
else{
data=queue[front];
cout<<"Element dequeued "<<data<<endl;
front=(front+1)%size;
}
}
void display(){
int i;

printf("\n Front -> %d", front);
printf("\n Items -> ");
for( i = front; i!=rear; i=(i+1)%size) {
printf("%d",queue[i]);
}
printf("%d",queue[i]);
printf("\n Rear -> %d \n",rear);
}
bool isEmpty() {
    if (front == rear){
        return true;
    }
    return false;
}

bool isFull() {
    if ((rear + 1) % size == front){
        return true;
    }
    return false;
}

int main(){
int choice=1, data;
cout<<"Enter size"<<endl;
cin>>size;
while(1){
cout<<"enter the choice "<<endl;
cin>>choice;
switch(choice){

case 1: cout<<"Enter the data"<<endl;
cin>>data;
enqueue(data);
break;
case 2:dequeue();
break;
case 3: display();
break;
case 4: isFull();
break;
case 5: isEmpty();
break;
case 0:exit(0);
break;

default: cout<<"Invalid case"<<endl;
break;
}

}
}



  
  