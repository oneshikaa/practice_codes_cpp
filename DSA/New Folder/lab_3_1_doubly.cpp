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
  void insertBeg() {
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
      p->next = head;
      head->prev = p;
      head = p;
    }
  }

  void insertEnd() {
    if (head == NULL) {
      insertBeg();
      return;
    }
    cout << "Enter value: ";
    node *p = new node();
    cin >> p->data;
    tail->next = p;
    p->prev = tail;
    p->next = NULL;
    tail = p;
  }

  void insertMiddle() {
    if (head == NULL) {
      insertBeg();
      return;
    }
    cout << "After which value: ";
    int n;
    cin >> n;
    node *p = head;
    while (p != NULL && p->data != n)
      p = p->next;
    if (p == NULL) {
      cout << "Value not found." << endl;
      return;
    } else if (p == tail) {
      insertEnd();
      return;
    }
    node *q = new node();
    cout << "Enter value: ";
    cin >> q->data;
    q->next = p->next;
    q->prev = p;
    p->next = q;
  }

  void deleteBeg() {
    if (head == NULL) {
      cout << "List is empty!" << endl;
      return;
    }
    node *p = head;
    head = head->next;
    if (head)
      head->prev = NULL;
    delete p;
  }

  void deleteEnd() {
    if (head == NULL) {
      cout << "List is empty!" << endl;
      return;
    }
    node *p = tail;
    tail = tail->prev;
    if (tail)
      tail->next = NULL;
    delete p;
  }

  void deleteMiddle() {
    if (head == NULL) {
      cout << "List is empty";
      return;
    }

    int n;
    cout << "Which value: ";
    cin >> n;
    node *p = head;
    while (p != NULL && p->data != n)
      p = p->next;
    if (p == NULL) {
      cout << "Value not found." << endl;
      return;
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
  }

  void search() {
    if (head == NULL) {
      cout << "List is empty" << endl;
      return;
    }
    cout << "Enter value: ";
    int n;
    cin >> n;
    int count = 0;
    node *p = head;
    while (p != NULL && p->data != n) {
      p = p->next;
      count++;
    }
    if (p == NULL) {
      cout << "Value not found." << endl;
      return;
    }
    cout << "Found at index: " << count << endl;
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
  cout << "1. Insert at beginning." << endl;
  cout << "2. Insert at end." << endl;
  cout << "3. Insert in middle." << endl;
  cout << "4. Delete from beginning." << endl;
  cout << "5. Delete from end." << endl;
  cout << "6. Delete from middle." << endl;
  cout << "7. Print list." << endl;
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
      list->insertBeg();
      break;
    case 2:
      list->insertEnd();
      break;
    case 3:
      list->insertMiddle();
      break;
    case 4:
      list->deleteBeg();
      break;
    case 5:
      list->deleteEnd();
      break;
    case 6:
      list->deleteMiddle();
      break;
    case 7:
      list->print();
      break;
    default:
      flag = 0;
    }
  }
  return 0;
}
