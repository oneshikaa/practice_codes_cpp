#include <cstring>
#include <iostream>
#include <string>
#include <limits.h>
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

// Checks whether the character is a operator or not.
bool isOperator(char a) {
  return (a == '+' || a == '-' || a == '*' || a == '/' );
}

// Evaluates a postfix expression.
int posfixEval(string postfix) {
  int n = postfix.length();
  menu_stack *S = new menu_stack(n);
  char arr[n + 1];
  strcpy(arr, postfix.c_str());
  int a, b;
  int result;
  for(int i=0; i<n; i++) {
    if (!isOperator(arr[i])) {
      S->push(arr[i] - 48);
    }
    else {
      if (!S->isEmpty()) a = S->pop();
      else break;
      if (!S->isEmpty()) b = S->pop();
      else break;
      if (arr[i] == '+') result = b + a;
      else if (arr[i] == '-') result = b-a;
      else if (arr[i] == '*') result = b*a;
      else if (arr[i] == '/') result = b/a;
      S->push(result);
    }
  }
  if (S->isEmpty()) return INT_MIN;
  else result = S->pop();
  if (!S->isEmpty()) return INT_MIN;
  delete S;
  return result;
}

int main() {
  string str;
  getline(cin, str);
  int val = posfixEval(str);
  if (val != INT_MIN) cout << val << endl;
  else cout << "Invalid input" << endl;
  return 0;
}

