#include <iostream>
using namespace std;

class DoublyLinkedList {
  struct node {
    int data;
    node *next;
  };
  node *tail = NULL; // head is always tail->next;

public:
  void insertBeg() {
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
    }
  }

  void insertEnd() {
    insertBeg();
    tail = tail->next;
  }

  void insertMiddle() {
    if (tail == NULL)
      insertBeg();
    cout << "After which value: ";
    int n;
    cin >> n;
    node *p = tail->next;
    while (p != tail && p->data != n) {
      p = p->next;
    }
    if (p == tail && tail->data != n) {
      cout << "Value not found.";
      return;
    } else {
      node *q = new node();
      cout << "Enter value: ";
      cin >> q->data;
      q->next = p->next;
      p->next = q;
      if (p == tail)
        tail = tail->next;
    }
  }

  void deleteBeg() {
    if (tail == NULL) {
      cout << "List is empty!" << endl;
      return;
    }
    node *p = tail->next;
    tail->next = p->next;
    p->next = NULL;
    if (p == tail)
      tail = NULL;
    delete p;
  }

  void deleteEnd() {
    if (tail == NULL) {
      cout << "List is empty!" << endl;
      return;
    }
    if (tail->next == tail) {
      delete tail;
      tail = NULL;
    } else {
      node *p = tail->next;
      while (p->next != tail)
        p = p->next;
      p->next = tail->next;
      delete tail;
      tail = p;
    }
  }

  void deleteMiddle() {
    if (tail == NULL) {
      cout << "List is empty";
      return;
    }

    int n;
    cout << "Which value: ";
    cin >> n;
    node *p = tail;
    while (p->next != tail && p->next->data != n)
      p = p->next;
    if (p->next == tail && tail->data != n) {
      cout << "Value not found." << endl;
      return;
    } else {
      if (p->next == tail) {
        tail = p;
      }
      node *q = p->next;
      p->next = q->next;
      delete q;
    }
  }

  void search() {
    cout << "Enter value: ";
    int n;
    cin >> n;
    int count = 0;
    node *p = tail->next;
    while (p != tail && p->data != n) {
      p = p->next;
      count++;
    }
    if (p == tail && tail->data != n) {
      cout << "Value not found." << endl;
      return;
    }
    cout << "Found at index: " << count << endl;
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
