#include <iostream>
using namespace std;

class LinkedList {

  typedef struct node {
    int data;
    struct node *next;
  } node;

  node *head = NULL, *tail;

public:
  void create_node() {
    if (head == NULL) {
      head = new node();
      int n;
      cout << "Enter value: ";
      cin >> n;
      head->data = n;
      head->next = NULL;
      tail = head;
    } else {
      insert_end();
    }
  }

  void insert_end() {
    int n;
    tail->next = new node();
    cout << "Enter value: ";
    cin >> n;
    tail = tail->next;
    tail->data = n;
    tail->next = NULL;
  }

  void insert_mid() {
    int n;
    node *q = head;
    cout << "After which num you want to enter new node? ";
    cin >> n;
    while (q != NULL && q->data != n)
      q = q->next;
    if (q == NULL) {
      cout << "Specified value doesn't exist in linked list" << endl;
      return;
    }
    node *p = new node();
    cout << "Enter value: ";
    cin >> p->data;
    p->next = q->next;
    q->next = p;
  }

  void delete_end() {
    node *p = head;
    while (p->next->next != NULL)
      p = p->next;
    delete p->next;
    p->next = NULL;
  }

  void print_list() {
    node *p = head;
    while (p != NULL) {
      cout << p->data << " ";
      p = p->next;
    }
    cout << endl;
  }

  void insert_beg() {
    node *p = new node();
    cout << "Enter data: ";
    cin >> p->data;
    p->next = head;
    head = p;
  }

  void search() {
    int n;
    cout << "Enter value to search: ";
    cin >> n;
    node *p = head;
    int i = 0;
    while (p != NULL && p->data != n) {
      p = p->next;
      i++;
    }
    if (p == NULL)
      cout << "Not found\n";
    else
      cout << "Found at index: " << i << endl;
  }

  void delete_beg() {
    node *p = head;
    head = head->next;
    delete p;
  }
};

void show_menu() {
  cout << "1. Create head" << endl;
  cout << "2. Insert at end" << endl;
  cout << "3. Insert at beginning" << endl;
  cout << "4. Insert in middle" << endl;
  cout << "5. Delete from end" << endl;
  cout << "6. Delete from beginning" << endl;
  cout << "7. search for value" << endl;
  cout << "8. Print List" << endl;
  cout << "9. Exit" << endl;
}

int main() {
  int flag = 0;
  int choice;
  LinkedList list;
  show_menu();
  while (!flag) {
    printf("Enter choice: ");
    cin >> choice;
    switch (choice) {
    case 1:
      list.create_node();
      break;
    case 2:
      list.insert_end();
      break;
    case 3:
      list.insert_beg();
      break;
    case 4:
      list.insert_mid();
      break;
    case 5:
      list.delete_end();
      break;
    case 6:
      list.delete_beg();
      break;
    case 7:
      list.search();
      break;
    case 8:
      list.print_list();
      break;
    default:
      flag = 1;
      break;
    }
  }
  return 0;
}
