#include <iostream>
using namespace std;

void sum_every_row(int **A, int m, int n) {
  int sum;
  for(int i=0; i<m; i++) {
    sum = 0;
    for(int j=0; j<n; j++) {
      sum += A[i][j];
    }
    cout << sum << endl;
  }
}

void sum_every_col(int **A, int m, int n) {
  int sum;
  for(int i=0; i<n; i++) {
    sum = 0;
    for(int j=0; j<m; j++) {
      sum += A[j][i];
    }
    cout << sum << endl;
  }
}

void print(int **A, int m, int n) {
  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      cout << A[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  int m;
  int n;
  cout << "Enter number of rows: ";
  cin >> m;
  cout << "Enter number of columns: ";
  cin >> n;

  int **A = new int*[m];
  for(int i=0; i<m; i++) {
    A[i] = new int[n];
  }

  for(int i=0; i < m; i++) {
    for(int j=0; j<n; j++) {
      cout << "Enter A[" << i << "][" << j << "]: ";
      cin >> A[i][j];
    }
  }

  print(A,m,n);
  cout << endl << "Sums of rows:" << endl;
  sum_every_row(A, m, n);
  cout << endl << "Sums of columns:" << endl;
  sum_every_col(A, m, n);

  for(int i = 0; i<m; i++) {
    delete[] A[i];
  }
  delete[] A;
  return 0;
}

