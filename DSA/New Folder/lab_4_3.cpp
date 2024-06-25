#include <iostream>
#include <cstring>
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

  bool isEmpty() {
    return (top == -1);
  }

  bool isFull() {
    return (top == size - 1);
  }

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
    for(int i=top; i>=0; i--)
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

int main() {
  int flag = 0;
  string s;
  cout << "Enter a string containing parenthesis: ";
  getline (cin, s);
  menu_stack *S = new menu_stack(s.length());

  char *c = new char[s.length() + 1];
  strcpy(c, s.c_str());

  char top;

  for(int i=0; c[i] != 0 && !flag ; i++) {
    if (c[i] == '{' || c[i] == '[' || c[i] == '(')
      S->push(c[i]);
    else if (c[i] == '}' || c[i] == ']' || c[i] == ')') {
      top = S->pop();
      if (top == 0) flag = 1;
      else if (top == '(' && c[i] != ')') flag = 1;
      else if (top == '{' && c[i] != '}') flag = 1;
      else if (top == '[' && c[i] != ']') flag = 1;
    }
  }

  if (flag == 0 && S->isEmpty()) cout << "Balanced" << endl;
  else cout << "Unbalanced" << endl;

  delete[] c;
  delete S;
  return 0;
}

