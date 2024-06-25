#include <cstring>
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

  char stack_top() {
    if (isEmpty()) {
      cout << "Stack Underflow";
      return 0;
    }
    return arr[top];
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

bool isOperator(char a) {
  return (a == '+' || a == '-' || a == '*' || a == '/' || a == '(' || a == ')');
}

int precedence(char a) {
  if (a == '*' || a == '/') return 2;
  else if (a == '+' || a == '-') return 1;
  return 0;
}

char* infixToPostfix(string str) {
  int n = str.length();
  menu_stack *S = new menu_stack(n);
  char *input = new char[n+1];
  char *result = new char[n + 1];
  strcpy(input, str.c_str());
  int k=0;

  for(int i=0; i<n; i++) {
    if (!isOperator(input[i]))
      result[k++] = input[i];
    else {
      if (input[i] == ')') {
        char temp = S->pop();
        while (temp != '(') {
          result[k++] = temp;
          temp = S->pop();
        }
      }
      else if (S->isEmpty() ||
          input[i] == '(' ||
          S->stack_top() == '(' ||
          precedence(input[i]) > precedence(S->stack_top()))
      {
        S->push(input[i]);
      }
      else {
        while (!S->isEmpty() && (precedence(input[i]) <= precedence(S->stack_top())))
          result[k++] = S->pop();
        S->push(input[i]);
      }
    }
  }

  while (!S->isEmpty()){
    result[k++] = S->pop();
  }

  result[k++] = 0;

  delete[] input;
  return result;
}

int main () {
  string input = "(a+b)/c+d*e";
  cout << infixToPostfix(input) << endl;
  return 0;
}
