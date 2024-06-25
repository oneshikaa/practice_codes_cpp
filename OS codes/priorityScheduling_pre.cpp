#include <iostream>
using namespace std;

struct process
{
    int pid, at, bt, priority, st, ct, tat, wt;
};

int main()
{
    int n;
    struct process p[100];
    float avg_tat, avg_wt;
    int total_tat = 0, total_wt = 0;
    int rt[100];
    int is_complete[100] = {0};

    cout << "Enter the number of processes: ";
    cin >> n;
    cout<<"enter arrival time, burst time "<<endl;

    for (int i = 0; i < n; i++)
    {
        cin >> p[i].at;
        cin >> p[i].bt;
        cin >> p[i].priority;
        p[i].pid = i + 1;
        rt[i] = p[i].bt;
    }
    int time = 0;
    int completed = 0;

    while (completed != n)
    {
        int idx = -1; // higher priority process
        int mx = -1;  // priority
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= time && is_complete[i] == 0)
            {
                if (p[i].priority > mx)
                {
                    mx = p[i].priority;
                    idx = i;
                }
                if (p[i].priority == mx)
                {
                    if (p[i].at < p[idx].at)
                    {
                        mx = p[i].priority;
                        idx = i;
                    }
                }
            }
        }
        if (idx!=-1)
        {
            if (rt[idx]==p[idx].bt)
            {
                p[idx].st = time;
            }
            rt[idx]--;
            time++;
            if (rt[idx]==0)
            {
                p[idx].ct = time;
                p[idx].tat= p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;

                total_tat += p[idx].tat;
                total_wt += p[idx].wt;

                is_complete[idx] = 1;
                completed++;

            }
            
        }
        else{
            time++;
        }
        
    }   
    avg_tat = (float) total_tat / n;
    avg_wt = (float) total_wt/ n;

    cout<<"#P\t"<<"AT\t"<<"BT\t"<<"PRI\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"\n"<<endl;

    for(int i = 0; i < n; i++) {
        cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].priority<<"\t"<<p[i].st<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<"\n"<<endl;
    }
    cout<<"Average Turnaround Time = "<<avg_tat<<endl;
    cout<<"Average Waiting Time = "<<avg_wt<<endl;

}