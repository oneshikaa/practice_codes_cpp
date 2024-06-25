#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the number : "<<endl;
    cin>>n;
    for (int i = 1; i <=n; i++)
    {
        if(n%i==0){
            cout<<i<<" ";
        }
    }
    
    
}

/*
#include<iostream>
#include<cmath>
using namespace std;

void printDivisorsOptimal(int n){
    
    cout<<"The Divisors of "<<n<<" are:"<<endl;
	for(int i = 1; i <= sqrt(n); i++)
		if(n % i == 0){
			cout << i << " ";
			if(i != n/i) cout << n/i << " ";
		}
	
	cout << "\n";
}

int main(){
	printDivisorsOptimal(36);
        return 0;
}
*/