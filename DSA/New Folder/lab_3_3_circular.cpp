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

  void count() {
    if (tail == NULL) {
      cout << "List has 0 items." << endl;
      return;
    }
    int count = 0;
    node *p = tail;
    do {
      p = p->next;
      count++;
    } while (p != tail);
    cout << "List has " << count << " items." << endl;
  }

  void print() {
    if (tail == NULL)
      return;
    node *p = tail->next;
    do {
      cout << p->data << " ";
      p = p->next;
    } while (p != tail->next);
    cout << endl;
  }
};

void showMenu() {
  cout << "1. Add" << endl;
  cout << "2. Count" << endl;
  cout << "3. Print List" << endl;
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
      list->count();
      break;
    case 3:
      list->print();
      break;
    default:
      flag = 0;
    }
  }
  return 0;
}

