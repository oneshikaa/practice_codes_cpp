#include <iostream>
using namespace std;

int main() {
	int t,size,counter;
	counter = 0;
    int *arr;

	cin>>t;
	while(t--){
	   cin>>size;
       arr = new int [size];
	    	
	    for (int i = 0; i < size; i++) {
	        cin>>arr[i];
	       // cout<<"h";
	    }
	    for (int i = 1; i < size; i++) {
	  	    if(arr[0]==arr[i]){
	  	        counter++;
	  	        
	  	    }
	  	
	}
	cout<<size-counter;
	}
	
	return 0;
	
}