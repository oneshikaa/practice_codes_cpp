#include <iostream>
using namespace std;

void BubbleSort(int *A, int n) {
  int temp;
  for(int i=0; i<n-1;i++) {
    for(int j=0; j<n-i-1; j++) {
      if (A[j] > A[j+1]) {
        temp = A[j];
        A[j] = A[j+1];
        A[j+1] = temp;
      }
    }
  }
}

int main() {
  int *A;
  int n;
  cout << "Enter number of elements in array: ";
  cin >> n;
  cout << "Enter the elements: ";
  A = new int[n];
  for(int i=0; i<n; i++) {
    cin >> A[i];
  }
  cout << "Sorted: ";
  BubbleSort(A,n);
  for(int i=0; i<n; i++) {
    cout << A[i] << " ";
  }
  delete[] A;
  return 0;
}

