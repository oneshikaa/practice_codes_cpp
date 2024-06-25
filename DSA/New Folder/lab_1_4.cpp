#include <iostream>
using namespace std;

void reverse(int *A, int n) {
    int i=0, j=n-1;
    int temp;
    while (i<j) {
        temp = A[i];
        A[i++] = A[j];
        A[j--] = temp;
    }
}

void MultiplyMatrix(int **A, int **B, int **C, int ar, int br, int cr, int ac, int bc, int cc) {
    if (ac != br || cr != ar || cc != bc) return;
    int sum;
    for(int i=0; i<ar; i++) {
        for(int j=0; j<bc; j++) {
            sum = 0;
            for(int k=0; k<ac; k++) {
                sum+=A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

void Transpose(int **A, int ar, int ac, int**B, int br, int bc) {
    if (bc != ar || br != ac) return;
    for(int i=0; i<ar; i++) {
        for(int j=0; j<ac; j++) {
            B[j][i] = A[i][j];
        }
    }
}

void takeInput(int **A, int r, int c) {
  for(int i=0; i<r; i++) {
    for(int j=0; j<c; j++) {
      cout << "Enter value at row " << i << ", column " << j << ": ";
      cin >> A[i][j];
    }
  }
}

void printMatrix(int **A, int r, int c) {
  for(int i=0; i<r; i++) {
    for(int j=0; j<c; j++)
      cout << A[i][j] << "  ";
    cout << endl;
  }
  cout << endl;
}

void choice_1() {
  int *A;
  int n;
  cout << "Enter number of elements: ";
  cin >> n;
  A = new int[n];
  cout << "Enter elements: ";
  for(int i=0; i<n; i++)
    cin >> A[i];

  cout << "Reversed: ";
  reverse(A, n);
  for(int i=0; i<n; i++)
    cout << A[i] << " ";
  delete[] A;
}

void choice_2() {
  int **A, **B;
  int r,c;
  cout << endl << "Enter the number of rows and columns in the matrix: ";
  cin >> r >> c;
  A = new int*[r];
  B = new int*[c];
  for(int i=0; i<r; i++)
    A[i] = new int[c];
  for(int i=0; i<c; i++)
    B[i] = new int[r];
  takeInput(A,r,c);
  cout << "Original:" << endl;
  printMatrix(A,r,c);
  cout << "Transpose:" << endl;
  Transpose(A,r,c,B,c,r);
  printMatrix(B,c,r);

  for(int i=0; i<r; i++)
    delete[] A[i];
  for(int i=0; i<c; i++)
    delete[] B[i];
  delete[] A;
  delete[] B;
}

void choice_3() {
  int **A = NULL, **B = NULL, **C = NULL;
  int ra,ca,rb,cb;
  cout << endl << "Enter the number of rows and columns in the matrix A: ";
  cin >> ra >> ca;
  cout << endl << "Enter the number of rows and columns in the matrix B: ";
  cin >> rb >> cb;
  if (ca != rb) {
    delete A;
    delete B;
    delete C;
    cout << "Invalid order of matrix\n";
    exit(0);
  }
  A = new int*[ra];
  B = new int*[rb];
  C = new int*[ra];
  for(int i=0; i<ra; i++)
    A[i] = new int[ca];
  for(int i=0; i<rb; i++)
    B[i] = new int[cb];
  for(int i=0; i<ra; i++)
    C[i] = new int[cb];
  cout << "Taking input in matrix A:" << endl;
  takeInput(A,ra,ca);
  cout << "Taking input in matrix B:" << endl;
  takeInput(B,rb,cb);
  MultiplyMatrix(A,B,C,ra,rb,ra,ca,cb,cb);
  cout << "Matrix A:" << endl;
  printMatrix(A,ra,ca);
  cout << "Matrix B:" << endl;
  printMatrix(B,rb,cb);
  cout << "Matrix C:" << endl;
  printMatrix(C,ra,cb);
  for(int i=0; i<ra; i++)
    delete[] A[i];
  for(int i=0; i<rb; i++)
    delete[] B[i];
  for(int i=0; i<ra; i++)
    delete[] C[i];
  delete[] A;
  delete[] B;
  delete[] C;
}

int main() {
  int n;
  cout << "Select choice:" << endl;
  cout << "1. Reverse array" << endl;
  cout << "2. Transpose of matrix" << endl;
  cout << "3. Matrix Multiplicaton" << endl;
  cin >> n;
  switch(n) {
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
      cout << "Exiting..." << endl;
      break;
  }
  return 0;
}

