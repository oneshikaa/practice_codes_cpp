#include <iostream>
#include <limits.h>
using namespace std;

class Queue {
  private:
    int f;
    int r;
    int size;
    int *arr;

  public:
    Queue(int size) {
      f = -1;
      r = -1;
      this->size = size;
      arr = new int[size];
    }

    ~Queue() {
      delete[] arr;
    }

    bool isFull() {
      if (r == -1) return false;
      else if (f == -1 && r == size-1) return true;
      else return (r == f);
    }

    bool isEmpty() {
      return (r == -1);
    }

    void enqueue(int val) {
      if (isFull()) return;
      r = (r + 1) % size;
      arr[r] = val;
    }

    int dequeue() {
      if (isEmpty()) return INT_MIN;
      f = (f + 1) % size;
      int val = arr[f];
      if (f == r) f = r = -1;
      return val;
    }

    int first() {
      if (isEmpty()) return INT_MIN;
      else return arr[(f+1) % size];
    }

    void printQueue() {
      if (isEmpty()) return;
      for(int i=f+1; i !=r; i = (i + 1) % size)
        cout << arr[i] << "  ";
      cout << arr[r];
      cout << endl;
    }
};

class Stack_using_queue {
  private:
    Queue* Q;
    int size;
  public:
    Stack_using_queue(int cap) {
      size = cap;
      Q = new Queue(size);
    }
    void push(int val) {
      if (Q->isFull()) {
        cout << "Queue is full" << endl;
        return;
      }
      if (Q->isEmpty()) {
        Q->enqueue(val);
        return;
      }
      Q->enqueue(val);
      while (Q->first() != val) {
        Q->enqueue(Q->dequeue());
      }
    }
    int pop() {
      if (Q->isEmpty()) return INT_MIN;
      else return (Q->dequeue());
    }
    bool isEmpty() {
      return Q->isEmpty();
    }
    bool isFull() {
      return Q->isFull();
    }
};

int main() {
  int n, temp;
  cout << "Enter number of elements: ";
  cin >> n;
  Stack_using_queue *S = new Stack_using_queue(n);
  for(int i=0; i<n; i++) {
    cout << "Enter element: ";
    cin >>temp;
    S->push(temp);
  }
  while (!S->isEmpty()) {
    cout << S->pop() << endl;
  }

  return 0;
}

