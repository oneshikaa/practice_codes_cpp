#include <iostream>
using namespace std;

void removeDuplicates(int *A, int n) {
    if (A==NULL) return;
    int *B = new int[n];
    B[0] = A[0];
    int B_end = 0;
    int flag = 0;
    for(int i=1; i<n; i++) {
        flag = 0;
        for(int j=0; j<=B_end; j++)
            if (A[i] == B[j]) flag = 1;
        if (flag == 0)
            B[++B_end] = A[i];
    }
    for(int i=0; i<=B_end; i++)
        cout << B[i] << " ";
    cout << endl;
}

int main() {
    int *A;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    A = new int[n];
    cout << "Enter elemnts: ";
    for(int i=0; i<n; i++) {
      cin >> A[i];
    }
    cout << "Original: ";
    for(int i=0; i<n; i++) {
      cout << A[i] << "  ";
    }
    cout << endl << "After removing duplicates: ";
    removeDuplicates(A,n);
    cout << endl;
    return 0;
}

