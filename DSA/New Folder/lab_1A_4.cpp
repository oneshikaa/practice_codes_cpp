#include <iostream>
#include <limits.h>
using namespace std;

void print(int **A, int m, int n) {
  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      cout << A[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl;
}

int find_min(int *A, int n) {
  int min = INT_MAX;
  int p;
  int i;
  for(i=0; i<n; i++)
    if (A[i] < min) {
      min = A[i];
      p = i;
    };

  return p;
}

int find_saddle_pt(int **A, int m, int n) {
  int saddle = INT_MIN;
  int p;
  int max;
  for(int i=0; i<m; i++) { // search in rows
    p = find_min(A[i],n); // p is the index of min element
    max = A[i][p];
    for(int j = 0; j < m; j++)
      if (A[j][p] > max) max = A[j][p];
    if (max == A[i][p]) {
      saddle = max;
      return saddle;
    }
  }
  return saddle;
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

  int saddle = find_saddle_pt(A,m,n);
  if (saddle == INT_MIN)
    cout << "No saddle point." << endl;
  else
    cout << "Saddle point: " <<  saddle << endl;

  for(int i = 0; i<m; i++) {
    delete[] A[i];
  }
  delete[] A;
  return 0;
}

