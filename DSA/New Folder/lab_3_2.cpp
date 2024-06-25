#include <iostream>
using namespace std;

class CircularLinkedList {
  struct node {
    int data;
    node *next;
  };
  node *tail = NULL; // head is always tail->next;

public:
  void add() {
    cout << "Enter value: ";
    if (tail == NULL) {
      tail = new node();
      cin >> tail->data;
      tail->next = tail;
    } else {
      node *p = new node();
      cin >> p->data;
      p->next = tail->next;
      tail->next = p;
      tail = tail->next;
    }
  }

  void print() {
    if (tail == NULL)
      return;
    node *p = tail->next;
    do {
      cout << p->data << " ";
      p = p->next;
    } while (p != tail->next);
    cout << tail->next->data;
    cout << endl;
  }
};

void showMenu() {
  cout << "1. Add" << endl;
  cout << "2. Print list." << endl;
}

int main() {
  CircularLinkedList *list = new CircularLinkedList();
  int n;
  int flag = 1;
  showMenu();
  while (flag) {
    cout << "Enter your choice: ";
    cin >> n;
    switch (n) {
    case 1:
      list->add();
      break;
    case 2:
      list->print();
      break;
    default:
      flag = 0;
    }
  }
  return 0;
}
