#include <iostream>
using namespace std;

class LinkedList {

  typedef struct node {
    int data;
    struct node *next;
  } node;

  node *head = NULL, *tail;

public:
  void add() {
    if (head == NULL) {
      head = new node();
      int n;
      cout << "Enter value: ";
      cin >> n;
      head->data = n;
      head->next = NULL;
      tail = head;
    } else {
      int n;
      tail->next = new node();
      cout << "Enter value: ";
      cin >> n;
      tail = tail->next;
      tail->data = n;
      tail->next = NULL;
    }
  }

  void print_list() {
    node *p = head;
    while (p != NULL) {
      cout << p->data << " ";
      p = p->next;
    }
    cout << endl;
  }

  void countAndDelete() {
    int counter = 0;
    int n;
    cout << "Enter number: ";
    cin >> n;
    node *p = head;
    node *q = NULL; // stays behind p
    node *temp;     // stores node to be deleted
    while (p != NULL) {
      if (p->data == n) {
        // delete the node
        if (p == head) {
          temp = p;
          head = head->next;
          p = p->next;
          delete temp;
          counter++;
        } else {
          temp = q->next;
          q->next = p->next;
          p = p->next;
          delete temp;
          counter++;
        }
      } else {
        q = p;
        p = p->next;
      }
    }
    cout << "Deleted " << counter << " Values." << endl;
  }
};

void show_menu() {
  cout << "1. Add" << endl;
  cout << "2. Print List" << endl;
  cout << "3. Count and delete" << endl;
  cout << "4. Exit" << endl;
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
      list.add();
      break;
    case 2:
      list.print_list();
      break;
    case 3:
      list.countAndDelete();
      break;
    default:
      flag = 1;
      break;
    }
  }
  return 0;
}
