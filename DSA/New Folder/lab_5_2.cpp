#include <iostream>
#include <climits>
using namespace std;

class Queue {
private:
  int f;
  int r;
  int size;
  int *arr;

public:
  Queue(int size) {
    f = -1;
    r = -1;
    this->size = size;
    arr = new int[size];
  }

  ~Queue() { delete[] arr; }

  bool isFull() {
    if (r == -1)
      return false;
    else if (f == -1 && r == size - 1)
      return true;
    else
      return (r == f);
  }

  bool isEmpty() { return (r == -1); }

  void enqueue(int val) {
    if (isFull())
      return;
    r = (r + 1) % size;
    arr[r] = val;
  }

  int dequeue() {
    if (isEmpty())
      return INT_MIN;
    f = (f + 1) % size;
    int val = arr[f];
    if (f == r)
      f = r = -1;
    return val;
  }

  int peek(int val) {
    int flag = 0;
    if (isEmpty())
      return -1;
    int count = 0;
    for (int i = f + 1; i != r; i = (i + 1) % size) {
      if (arr[i] == val) {
        flag = 1;
        break;
      }
      count++;
    }
    if (flag == 1)
      return count;
    else if (arr[r] == val)
      return count;
    else
      return -1;
  }

  void display() {
    if (isEmpty())
      return;
    for (int i = f + 1; i != r; i = (i + 1) % size)
      cout << arr[i] << "  ";
    cout << arr[r];
    cout << endl;
  }
};

void showMenu() {
  cout << "1. Enqueue" << endl;
  cout << "2. Dequeue" << endl;
  cout << "3. IsEmpty" << endl;
  cout << "4. IsFull" << endl;
  cout << "5. Display" << endl;
  cout << "6. Peek" << endl;
}

int main() {
  int n;
  cout << "Enter queue size: ";
  cin >> n;
  Queue *q = new Queue(n);
  int flag = 1;
  int choice;
  showMenu();
  while (flag) {
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1:
      int n;
      cout << "Enter data: ";
      cin >> n;
      q->enqueue(n);
      break;
    case 2:
      q->dequeue();
      break;
    case 3:
      cout << (q->isEmpty() ? "true" : "false") << endl;
      break;
    case 4:
      cout << (q->isFull() ? "true" : "false") << endl;
      break;
    case 5:
      q->display();
      break;
    case 6:
      int m;
      cout << "Enter data: ";
      cin >> m;
      cout << "Found at index: " << q->peek(m) << endl;
      break;
    default:
      flag = 0;
    }
  }
  delete q;
  return 0;
}
