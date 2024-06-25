#include <iostream>
using namespace std;

void transpose(int* arr, int r, int c){
	int counter = 0;
	cout << "Transpose" << endl;
	for(int i = 0; i < r; i++){
		cout << "|";
		for(int j = 0; j < c; j++){
			if(arr[counter] == j && arr[counter+1] == i){
				cout << " " << arr[counter+2] << " ";
				counter += 3;
			}else{
				cout << " " << 0 << " ";
			}
		}
		cout << "|" << endl;
	}
}