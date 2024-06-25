#include<iostream>
using namespace std;
int main()
{
	int a[5]={2,3,4,5,7},found=0;
	int n=a[0];
	for(int i=0;i<5;i++)
	{
		if(a[i]==n)
		{
			found=1;
		}
		else{
			cout<<"Number missing "<<n;
			break;
		}
		n+=1;
	}

}