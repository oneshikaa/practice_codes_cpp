#include <iostream>
using namespace std;

class menu_stack {
  int top;
  int size;
  char *arr;

public:
  menu_stack(int cap) {
    top = -1;
    size = cap;
    arr = new char[size];
  }

  ~menu_stack() {
    delete[] arr;
    arr = 0;
  }

  bool isEmpty() { return (top == -1); }

  bool isFull() { return (top == size - 1); }

  void push(char c) {
    if (isFull()) {
      cout << "Stack Overflow" << endl;
      return;
    }
    arr[++top] = c;
  }

  char pop() {
    if (isEmpty()) {
      cout << "Stack Underflow";
      return 0;
    }
    return arr[top--];
  }

  void display() {
    for (int i = top; i >= 0; i--)
      cout << arr[i] << " ";
    cout << endl;
  }

  char peek(int index) {
    if (index < 0 || index >= size) {
      cout << "Invalid index" << endl;
      return 0;
    }
    return arr[index];
  }
};

void showMenu() {
  cout << "Select Stack Operation: " << endl;
  cout << "1. Push" << endl;
  cout << "2. Pop" << endl;
  cout << "3. isEmpty" << endl;
  cout << "4. isFull" << endl;
  cout << "5. Display" << endl;
  cout << "6. Peek" << endl;
  cout << "7. Exit" << endl;
}

int main() {
  int cap;
  int option;
  bool flag = true;
  int index;
  char val;
  cout << "Enter stack's capacity: ";
  cin >> cap;
  menu_stack *S = new menu_stack(cap);
  showMenu();
  while (flag) {
    cout << "Enter your choice: ";
    cin >> option;
    switch (option) {
    case 1: // push
      cout << "Enter character to be pushed: ";
      cin >> val;
      S->push(val);
      break;

    case 2: // pop
      cout << S->pop() << endl;
      break;

    case 3: // isEmpty
      cout << ((S->isEmpty()) ? "True" : "False") << endl;
      break;

    case 4: // isFull
      cout << ((S->isFull()) ? "True" : "False") << endl;
      break;

    case 5: // display
      S->display();
      break;

    case 6: // peek
      cout << "Enter index: ";
      cin >> index;
      cout << S->peek(index) << endl;
      break;

    default:
      flag = false;
    }
  }
  delete S;
  return 0;
}
