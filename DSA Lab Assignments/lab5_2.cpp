#include <iostream>

using namespace std;

int num;
 
class CircularQueue{
private:
    int size;
    int front;
    int rear;
    int* Q;
public:
     
    CircularQueue(){} 
    CircularQueue(int size);
    ~CircularQueue();
    bool isFull();
    bool isEmpty();
    void enqueue(int x);
    int dequeue();
    void display();
};
 
CircularQueue::CircularQueue(int size) {
    this->size = size;
    front = 0;
    rear = 0;
    Q = new int [size];
}
 
CircularQueue::~CircularQueue() {
    delete [] Q;
}
 
bool CircularQueue::isEmpty() {
    if (front == rear){
        return true;
    }
    return false;
}
 
bool CircularQueue::isFull() {
    if ((rear + 1) % size == front){
        return true;
    }
    return false;
}
 
void CircularQueue::enqueue(int x) {
    if (isFull()){
        cout << "Queue Overflow" << endl;
    } else {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}
 
int CircularQueue::dequeue() {
    int x = -1;
    if (isEmpty()){
        cout << "Queue Underflow" << endl;
    } else {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}
 
void CircularQueue::display() {
    int i = front + 1;
    do {
        cout << Q[i] << flush;
        if (i < rear) {
            cout << " <- " << flush;
        }
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
}
 
 
int main() {
 
    /*int A[] = {1, 3, 5, 7, 9};
 
    CircularQueue cq(sizeof(A)/sizeof(A[0]) + 1);
 
    // Enqueue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cq.enqueue(A[i]);
    }
 
    // Display
    cq.display();
    cout << endl;
 
    // Overflow
    cq.enqueue(10);
 
    // Dequeue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cq.dequeue();
    }
 
    // Underflow
    cq.dequeue();*/

       CircularQueue cq;
  

   while(1){
    int choice;
	cout<<"enter the choice"<<endl;
    cin>>choice;

  switch(choice){
      
      case 1 :
      break;
      
      case 2: cq.display();
      break;
      
      case 3 :
      cout<<"enter the number to be enqueued : "<<endl;
      cin>>num;
      cq.enqueue(num);
      break;
      
     /* case 4 : 
      cout<<"enter the position "<<endl;
      cin>>num1;
      peek(st,num1);
      break;*/
      
      case 4 : cq.dequeue();
      break;
      
      case 5 : cq.isFull();
      break;

      
      case 6 : cq.isEmpty();
      break;
      
  }
  
}
  
 
    return 0;
}