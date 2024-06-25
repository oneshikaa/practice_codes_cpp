#include <iostream>
using namespace std;

void diagonal(int *A, int n) {
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++)
      if (i==j) cout << A[i] << "\t";
      else cout << 0 << "\t";
    cout << endl;
  }
}

void tridiagonal(int *A, int n) {
  int k = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
      if (!(i - j > 1 || j - i > 1))
        cout << A[k++] << "\t";
      else cout << 0 << "\t";
    cout << endl;
  }
}

void lowerTriangular(int *A, int n) {
  int k=0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++)
      if (i > j)
        cout << A[k++] << "\t";
      else cout << 0 << "\t";
    cout << endl;
  }
}

void upperTriangular(int *A, int n) {
  int k=0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++)
      if (i < j)
        cout << A[k++] << "\t";
      else cout << 0 << "\t";
    cout << endl;
  }
}

void symmetric(int *A, int n) {
  int k;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++)
      if (i <= j) {
        k = i*n + (j - i*(i+1)/2);
        cout << A[k] << "\t";
      }
      else {
        k = j*n + (i - j*(j+1)/2);
        cout << A[k] << "\t";
      }
    cout << endl;
  }
}

void showMenu() {
  cout << endl;
  cout << "Choose matrix type:" << endl;
  cout << "1. Diagonal Matrix" << endl;
  cout << "2. Tri-Diagonal Matrix" << endl;
  cout << "3. Lower Triangular Matrix" << endl;
  cout << "4. Upper Triangular Matrix" << endl;
  cout << "5. Symmetric Matrix" << endl;
  cout << "6. EXIT" << endl;
}

int main() {
  int choice;
  int n;
  int k;
  int *A = NULL;
  while (true) {
    delete A;
    showMenu();
    cout << "Enter integer[0-6]: ";
    cin >> choice;
    if (choice < 1 || choice > 5) break;
    cout << "Enter the order of matrix: ";
    cin >> n;

    if (choice == 1){
      A = new int[n];
      for(int i=0; i<n; i++) {
        cout << "Enter A[" << i << "][" << i << "]: ";
        cin >> A[i];
      }
      diagonal(A,n);
    }
    else if (choice == 2){
      k=0;
      A = new int[3*n-2];
      for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
          if (!(i-j > 1 || j-i > 1)) {
            cout << "Enter A[" << i << "][" << j << "]: ";
            cin >> A[k++];
          }
        }
      }
      tridiagonal(A,n);
    }
    else if (choice == 3){
      k=0;
      A = new int[n*(n-1)/2];
      for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
          if (i>j) {
            cout << "Enter A[" << i << "][" << j << "]: ";
            cin >> A[k++];
          }
        }
      }
      lowerTriangular(A,n);
    }
    else if (choice == 4){
      k=0;
      A = new int[n*(n-1)/2];
      for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
          if (i<j) {
            cout << "Enter A[" << i << "][" << j << "]: ";
            cin >> A[k++];
          }
        }
      }
      upperTriangular(A,n);
    }
    else {
      k=0;
      A = new int[n*(n+1)/2];
      for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
          if (i<=j) {
            cout << "Enter A[" << i << "][" << j << "]: ";
            cin >> A[k++];
          }
        }
      }
      symmetric(A,n);
    }
  }
  return 0;
}
