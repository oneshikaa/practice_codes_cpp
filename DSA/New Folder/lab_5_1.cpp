#include <iostream>
#include <limits.h>
using namespace std;

class Queue {
  class Node {
  public:
    int data;
    Node *next;
    Node(int data) {
      this->data = data;
      this->next = NULL;
    }
  };
  Node *front = NULL;
  Node *rear = NULL;

public:
  void enqueue(int data) {
    Node *p = new Node(data);
    if (front == NULL) {
      rear = p;
      front = p;
    } else {
      rear->next = p;
      rear = p;
    }
  }

  int dequeue() {
    int val;
    if (front == NULL) {
      cout << "Queue is empty" << endl;
      val = INT_MIN;
    } else {
      val = front->data;
      Node *p = front;
      front = front->next;
      p->next = NULL;
      delete p;
    }
    return val;
  }

  bool isEmpty() { return (front == NULL); }

  bool isFull() {
    Node *p = new Node(0);
    if (!p) {
      return true;
    } else {
      delete p;
      return false;
    }
  }

  void display() {
    if (isEmpty()) {
      cout << "Queue is empty" << endl;
      return;
    }
    Node *p = front;
    while (p != NULL) {
      cout << p->data << " ";
      p = p->next;
    }
    cout << endl;
  }

  int peek(int index) {
    if (index < 0 || isEmpty())
      return INT_MIN;
    Node *p = front;
    for (int i = 0; p != NULL && i < index; i++) {
      p = p->next;
    }
    if (p == NULL)
      return INT_MIN;
    else
      return p->data;
  }
};

void showMenu() {
  cout << "1. Enqueue" << endl;
  cout << "2. Dequeue" << endl;
  cout << "3. IsEmpty" << endl;
  cout << "4. IsFull" << endl;
  cout << "5. Display" << endl;
  cout << "6. Peek" << endl;
}

int main() {
  Queue *q = new Queue();
  int flag = 1;
  int choice;
  showMenu();
  while (flag) {
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1:
      int n;
      cout << "Enter data: ";
      cin >> n;
      q->enqueue(n);
      break;
    case 2:
      q->dequeue();
      break;
    case 3:
      cout << (q->isEmpty() ? "true" : "false") << endl;
      break;
    case 4:
      cout << (q->isFull() ? "true" : "false") << endl;
      break;
    case 5:
      q->display();
      break;
    case 6:
      int m;
      cout << "Enter Index: ";
      cin >> m;
      cout << q->peek(m) << endl;
      break;
    default:
      flag = 0;
    }
  }
  delete q;
  return 0;
}
