#include<iostream>
using namespace std;

class cpu{
    int n;
    int* at;
    int* bt;
    int *wt;
    int *tat;

    public :

    cpu(){
        int counter = 0;
        int counter1 = 0;
        cout<<"enter the number of processes : "<<endl;
        cin>>n;
        at = new int [n];
        bt = new int [n];
        wt = new int [n];
        tat = new int [n];

        //wt[0] = 0;

        for (int i = 0; i < n; i++)
        {
        cout<<"enter arrival time for process "<<counter<<endl;
        cin>>at[i];
        counter++;
        }

        for (int i = 0; i < n; i++)
        {

        cout<<"enter cpu burst time for process "<<counter1<<endl;
        cin>>bt[i];
        counter1++;
        }

    }

    void sorting_atime(){
        
    for(int i = 0;i<n-1;i++){
 
        for (int j = 0; j < n-1-i; j++)
        {
            if(at[j]>at[j+1]){
                
                swap(at[j],at[j+1]);
                swap(bt[j],bt[j+1]);
            }
      
        }
        
    }

    }

  //  void display(){
  //      cout<<"sorted arrival times : "<<endl;
  //      for(int i = 0;i<n;i++){
  //          cout<<at[i]<<"  \n"<<bt[i];
  //      }
  // }

  void waiting_time(){

    int ct[n];
    ct[0] = at[0];
    wt[0] = 0;
    cout<<"WAT : "<<wt[0]<<" ";
    for (int i = 1; i < n; i++)
    {
        ct[i] = ct[i-1] + bt[i-1];
        wt[i] = ct[i]-at[i];

            if (wt[i] < 0)
            wt[i] = 0;

       cout<< wt[i]<<" ";

    }
    cout<<"\n";
    

  }

  void turn_around_time(){
    cout<<"TAT : ";
    for (int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
       cout<< tat[i]<<" ";
    }
    
  }



};

int main(){

    cpu A;
   A.sorting_atime();
  // A.display();
 A.waiting_time();
  A.turn_around_time();


}