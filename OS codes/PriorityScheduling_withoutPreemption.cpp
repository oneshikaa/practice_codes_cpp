#include<iostream>
using namespace std;

struct process{
    int pid;
    int bt;
    int priority;
};

void waitingTime(process proc[],int n,int wt[]){
    wt[0] = 0;
    for (int i = 0; i < n; i++)
    {
        wt[i] = proc[i-1].bt + wt[i-1];
    }
    
}

void TatTime(process proc[],int n,int wt[],int tat[]){
    for (int i = 0; i < n; i++)
    {
        tat[i] = proc[i].bt + wt[i];
    }   
}

void avgtime(process proc[], int n) {
   int wt[n], tat[n], total_wt = 0, total_tat = 0;
   
   waitingTime(proc, n, wt);
   
   TatTime(proc, n, wt, tat);

   cout << "Processes "<< " Burst time " << " Waiting time " << " Turn around time"<<endl;
  
   for (int i=0; i<n; i++) {
      total_wt = total_wt + wt[i];
      total_tat = total_tat + tat[i];
      cout <<proc[i].pid << "\t\t" << proc[i].bt << "\t " << wt[i] << "\t\t " << tat[i] <<endl;
   }
   cout << "Average waiting time = " << (float)total_wt / (float)n;
   cout << "Average turn around time = " << (float)total_tat / (float)n;
}

void scheduling(process proc[],int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (proc[j].priority>proc[j+1].priority)
            {
                swap(proc[i].pid,proc[i+1].pid);
                swap(proc[i].bt,proc[i+1].bt);

            }
            
        }
        
    }
    cout<<"order in which process gets executed : ";
    for (int i = 0; i <n; i++)
    {
        cout<<proc[i].pid<<" ";

    }
    cout<<"\n";
    avgtime(proc,n);
}

int main(){
   process proc[] = {{1, 10, 2}, {2, 5, 0}, {3, 8, 1}};
   int n = sizeof proc / sizeof proc[0];
   scheduling(proc, n);
   return 0;

}

