#include <iostream>
using namespace std;

template <class t>
void bubbleSort(t a[], int n) { 
    for (int i = 0; i < n - 1; i++) 
        for (int j = n - 1; i < j; j--) 
            if (a[j] < a[j - 1]) 
              swap(a[j], a[j - 1]); 
}

int main(void){

    int a[5] = {1,3,4,5,6};
    bubbleSort(a,5);
   
    for(int i = 0;i<5;i++){
        cout<<a[i]<<" ";
    }
    
}
