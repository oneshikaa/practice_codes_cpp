#include <iostream>
using namespace std;

int findMissing(int *A, int n) {
  int i = A[0];
  for(int j=1; j<n; j++)
    if (A[j] != ++i) return i;
  return -1;
}

int main() {
  int *A;
  int n;
  cout << "Enter number of elements: ";
  cin >> n;
  cout << "Enter elements: ";
  A = new int[n];
  for(int i=0; i<n; i++) {
    cin >> A[i];
  }
  int mis = findMissing(A,n);
  if (mis == -1)
    cout << "No element is missing\n";
  else
   cout << "Missing element: " << mis << endl;
  delete[] A;
  return 0;
}

