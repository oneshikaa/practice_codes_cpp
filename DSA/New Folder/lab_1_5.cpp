#include <iostream>
using namespace std;

int BinarySearch(int *A,int n, int value) {
  int low = 0, high = n-1;
  int mid;
  while (low < high) {
    mid = (low+high)/2;
    if (A[mid] == value) return mid;
    else if (A[mid] < value) low = mid+1;
    else high = mid-1;
  }
  return -1;
}

int main() {
  int *A;
  int n;
  int p;
  cout << "Enter number of elements in array: ";
  cin >> n;
  A = new int[n];
  cout << "Enter the elements: ";
  for(int i=0; i<n; i++)
    cin >> A[i];
  cout << "Enter the elements to search for: ";
  cin >> p;
  int res = BinarySearch(A,n,p);
  if (res == -1) cout << "Not found" << endl;
  else cout << "Found at index: " << res << endl;
  delete[] A;
  return 0;
}

