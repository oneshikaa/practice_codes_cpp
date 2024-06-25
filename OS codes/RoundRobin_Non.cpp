#include <iostream>
using namespace std;

// reffered from gfg
/*dunno why terminating*/
void waitingTime(int process[], int n, int bt[], int wt[], int tq)
{

    int rt[n];
    for (int i = 0; i < n; i++)
    {
        rt[i] = bt[i];
    }
    int ct = 0;

    while (1)
    {
        bool done = true;

        for (int i = 0; i < n; i++)
        {     
            if (rt[i] > 0)
            {
                 done = false;
              
                if (rt[i] > tq)
                {
                    ct = ct + tq;
                    rt[i] = rt[i] - tq;
                }

                else
                {
                    ct = ct + rt[i];
                    wt[i] = ct - bt[i];
                    rt[i] = 0;
                }
            }
        }
        if (done == true)
        {
            break;
        }
    }
}

void TurnAroundTime(int process[],int n,int bt[],int wt[],int tat[]){

for (int i = 0; i < n; i++)
{
    tat[i]  = bt[i] + wt[i];
}

}

void AvgTime(int process[],int n,int bt[],int tq){
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
 
    
waitingTime(process, n, bt, wt, tq);
 
    
TurnAroundTime(process, n, bt, wt, tat);
 
    
        cout << "PN\t "<< " \tBT "<< "  WT " << " \tTAT\n"<<endl;
    for (int i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout <<i+1 << "\t\t"<<bt[i]<<"\t "<< wt[i] <<"\t\t " << tat[i] <<endl;
    }
 
    cout << "Average waiting time = "<< (float)total_wt / (float)n<<endl;;
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)n;

}

int main()
{
    int process[] = {1, 2, 3};
    int n = sizeof(process) / sizeof(process[0]);

    int bt[] = {10, 5, 8};

    int tq = 2;
}