#include <iostream>
using namespace std;

class DoublyLinkedList {
  struct node {
    int data;
    node *prev;
    node *next;
  };
  node *head = NULL;
  node *tail = NULL;

public:
  void add() {
    cout << "Enter value: ";
    if (head == NULL) {
      head = new node();
      cin >> head->data;
      head->next = NULL;
      head->prev = NULL;
      tail = head;
    } else {
      node *p = new node();
      cin >> p->data;
      tail->next = p;
      p->prev = tail;
      p->next = NULL;
      tail = p;
    }
  }

  void count() {
    node *p = head;
    int count = 0;
    while (p != NULL) {
      p = p->next;
      count++;
    }
    cout << "List has " << count << " items." << endl;
  }

  void print() {
    if (head == NULL)
      return;
    node *p = head;
    while (p != NULL) {
      cout << p->data << " ";
      p = p->next;
    }
    cout << endl;
  }
};

void showMenu() {
  cout << "1. Add" << endl;
  cout << "2. Count" << endl;
  cout << "3. Print list" << endl;
}

int main() {
  DoublyLinkedList *list = new DoublyLinkedList();
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
