#include <iostream>
using namespace std;

struct Triplet {
  int row;
  int column;
  int value;
};

int give_value(Triplet A[], int i, int j, int m) {
  for(int k=0; k<m; k++) {
    if (A[k].row == i && A[k].column == j) return A[k].value;
  }
  return 0;
}

void print(Triplet A[], int m, int n) {
  int val;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      val = give_value(A,i,j,m);
      cout << val << "\t";
    }
    cout << endl;
  }
  cout << endl;
}

void Transpose(Triplet A[], int m) {
  int temp;
  for(int i=0; i<m; i++) {
    temp = A[i].row;
    A[i].row = A[i].column;
    A[i].column = temp;
  }
}

void add(Triplet A[], Triplet B[], Triplet C[], int a, int b, int c) {
  int val;
  for(int i=0; i<c; i++) {
    C[i].row = 0;
    C[i].column = 0;
    C[i].value = 0;
  }
  int c_end = 0;
  for(int i=0; i<a; i++) {
    val = give_value(B,A[i].row, A[i].column, b);
    C[c_end].row = A[i].row;
    C[c_end].column = A[i].column;
    C[c_end].value = A[i].value + val;
    c_end++;
  }
  for(int i = 0; i<b; i++) {
    val = give_value(A,B[i].row, B[i].column, a);
    if (val != 0) continue;
    C[c_end].row = B[i].row;
    C[c_end].column = B[i].column;
    C[c_end].value = B[i].value;
    c_end++;
  }
}

void showMenu() {
  cout << "1. Transpose" << endl;
  cout << "2. Add" << endl;
  cout << "3. Multiply" << endl;
}

void takeinput(Triplet A[], int n, int m, char name) {
  int k = 0;
  int flag = 0;
  int val;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if (k >= m) {
        flag = 1;
        break;
      }
      cout << "Enter element " << name << "[" << i << "]" << "[" << j << "]: ";
      cin >> val;
      if (val == 0) continue;
      else {
        A[k].row = i;
        A[k].column = j;
        A[k].value = val;
        k++;
      }
    }
    if (flag == 1) break;
  }
}

void choice_1() {
  Triplet *A;
  int n,m;
  cout << "Enter the order of matrix: ";
  cin >> n;
  cout << "Enter number of non-zero elements in matrix: ";
  cin >> m;
  A = new Triplet[m];
  takeinput(A,n,m,'A');
  print(A, m, n);
  Transpose(A, m);
  print(A, m, n);
  delete[] A;
}

void choice_2() {
  Triplet *A, *B, *C;
  int n,a,b;
  cout << "Enter the order of matrix: ";
  cin >> n;
  cout << "Enter number of non-zero elements in matrix1: ";
  cin >> a;
  cout << "Enter number of non-zero elements in matrix2: ";
  cin >> b;
  A = new Triplet[a];
  B = new Triplet[b];
  int len = a + b;
  for(int i=0; i<a; i++) {
    int val = give_value(B,A[i].row, A[i].column, b);
    if (val != 0) len--;
  }
  C = new Triplet[len];
  takeinput(A,n,a,'A');
  takeinput(B,n,b,'B');

  add(A,B,C,a,b,len);
  print(A,a,n);
  print(B,b,n);
  print(C,len,n);

  delete[] A;
  delete[] B;
  delete[] C;
}

void choice_3() {
  Triplet *A, *B;
  int n,a,b;
  cout << "Enter the order of matrix: ";
  cin >> n;
  cout << "Enter number of non-zero elements in matrix1: ";
  cin >> a;
  cout << "Enter number of non-zero elements in matrix2: ";
  cin >> b;
  A = new Triplet[a];
  B = new Triplet[b];
  takeinput(A,n,a,'A');
  takeinput(B,n,b,'B');
  int sum;

  print(A,a,n);
  print(B,b,n);

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      sum = 0;
      for(int k=0; k<n; k++) {
        // sum += A[i][k] * B[k][j];
        sum += give_value(A,i,k,a) * give_value(B,k,j,b);
      }
      cout << sum << "\t";
    }
    cout << endl;
  }

  delete[] A;
  delete[] B;
}

int main() {
  int choice = 0;
  cout << "Select Operation: " << endl;
  showMenu();
  cin >> choice;
  switch (choice) {
    case 1:
      choice_1();
      break;
    case 2:
      choice_2();
      break;
    case 3:
      choice_3();
      break;
    default:
      break;
  }
  return 0;
}
