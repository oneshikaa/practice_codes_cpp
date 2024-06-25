#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the number : "<<endl;
    cin>>n;
    for (int i = 2; i < n; i++)
    {
      if(n%i==0){
        cout<<"Not prime"<<endl;
      }
      else{
        cout<<"prime"<<endl;
      }
    }
    
}

/*#include<bits/stdc++.h>

using namespace std;

bool isPrime(int N) {
  for (int i = 2; i < sqrt(N); i++) {
    if (N % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {

  int n = 11;

  bool ans = isPrime(n);
  if (n != 1 && ans == true) {
    cout << "Prime Number";
  } else {
    cout << "Non Prime Number";
  }
  return 0;
}*/