#include <iostream>
using namespace std;

class MyArray{
  private:
    int size;
    int *A;

  public:

    MyArray(int size) {
      this->size = size;
      A = new int[size];
    }

    ~MyArray() {
      delete A;
    }

    void display() {
      cout << "[ ";
      for(int i=0; i<size; i++)
        cout << A[i] << " ,";
      cout << "\b]" << endl;
    }

    void insert(int element, int index) {
      if (index < 0 || index >= size) return;
      for(int i=size-1; i>index; i--)
        A[i] = A[i-1];
      A[index] = element;
    }

    void del(int index) {
      if (index < 0 || index >= size) return;
      for(int i=index; i<size-1; i++)
        A[i] = A[i+1];
    }

    int search(int element) {
      for(int i=0; i<size; i++)
        if (A[i] == element) return i;
      return -1;
    }
};

void showMenu() {
  cout << endl;
  cout << "---- Menu ----" << endl;
  cout << "1.CREATE"       << endl;
  cout << "2.DISPLAY"      << endl;
  cout << "3.INSERT"       << endl;
  cout << "4.DELETE"       << endl;
  cout << "5.SEARCH"       << endl;
  cout << "6.EXIT"         << endl;
}

int main() {
  int choice, temp1, temp2;
  MyArray *arr = NULL;
  while (true) {
    showMenu();
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice < 1 || choice >= 6) {
      delete arr;
      break;
    }
    else if (choice == 1) {
      delete arr;
      arr=NULL;
      cout << "Enter capacity: ";
      cin >> temp1;
      arr = new MyArray(temp1);
    }
    else if (choice == 2) {
      if (arr == NULL)
        cout << "No Array to display" << endl;
      else
        arr->display();
    }
    else if (choice == 3) {
      if (arr == NULL)
        cout << "No Array to insert in" << endl;
      else {
        cout << "Enter element to insert: ";
        cin >> temp1;
        cout << "Enter index: ";
        cin >> temp2;
        arr->insert(temp1, temp2);
      }
    }
    else if (choice == 4) {
      if (arr == NULL)
        cout << "No Array to delete from" << endl;
      else {
        cout << "Enter index: ";
        cin >> temp1;
        arr->del(temp1);
      }
    }
    else if (choice == 5) {
      if (arr == NULL)
        cout << "No Array to search for" << endl;
      else {
        cout << "Enter element to search: ";
        cin >> temp1;
        temp2 = arr->search(temp1);
        if (temp2 == -1)
          cout << "Element not found" << endl;
        else
          cout << temp1 << " found at index " << temp2 << endl;
      }
    }
  }
  return 0;
}
