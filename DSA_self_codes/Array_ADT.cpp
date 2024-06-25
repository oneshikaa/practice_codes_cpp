#include <iostream>
#include<stdlib.h>
using namespace std;

int a[20];
int k = 0;

void create(){
	cout<<"enter the number of elements : "<<endl;
	cin>>k;	
	for(int i = 0;i<k;i++ ){
		cout<<"enter the element"<<endl;
		cin>>a[i];
	}	
}

void display(){
	
	for(int i = 0;i<k;i++ ){
		cout<<a[i]<<endl;
	}
	
}

void insert(){
	int pos,element;
	cout<<"enter the position where element is to be inserted"<<endl;
	cin>>pos;
	cout<<"enter the element to be inserted"<<endl;
	cin>>element;
	
	for(int i = k-1;i>=pos;i--){
		a[i+1] = a[i];
	}
		a[pos] = element;
		k++;
	
	
	
}

void del(){
	cout<<"enter the position from where element is to be deleted"<<endl;
	int pos;
	cin>>pos;
	
	for(int i = pos;i<k-1;i++){
	a[i] = a[i+1];
	}
	k--;
	
}

void lsearch(){
	int n,found;
	cout<<"enter the number to be searched"<<endl;
	cin>>n;

	for(int i =0;i<k;i++){
		
		if(a[i]==n){
			found = 1;
			break;
		}
		else{
			found = 0;
		}
	}
	
	if(found==1){
		cout<<"found"<<endl;
	}
	
	else{
		cout<<"not found"<<endl;
	}
	

	
}

int  Bsearch(int a[]){
     int l,mid,h,n;

    cout<<"enter the element to be searched"<<endl;
    cin>>n;
   

    l=0;
    h=k-1;

    while(l<=h){
        mid=(l+h)/2;
     if(n==a[mid])
        return mid;
     


    }

}

void exits(){
    exit(0);

}

int main()
{while(1){
	int choice;
	cout<<"enter the choice"<<endl;
    cin>>choice;

  switch(choice){
      case 1 : create();
      break;
      
      case 2 : display();
      break;
      
      case 3 : insert();
      break;
      
      case 4 : del();
      break;
      
      case 5 : lsearch();
      break;
      
      case 6 : exits();
      break;
      
  }
  
}
  

    return 0;
}

