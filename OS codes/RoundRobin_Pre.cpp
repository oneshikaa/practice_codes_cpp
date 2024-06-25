#include<iostream>
using namespace std;

int main(){
    int i;//process id
    int n;
    int ct = 0;
    int time_quantum;
    int counter;

    int total_wt = 0, total_tat = 0, arrival_time[10], burst_time[10], rt[10];
    float avg_wt, avg_tat;

    cout<<"enter number of processes"<<endl;
    cin>>n;
    counter  = n;

    for (int i = 0; i <n ; i++)
    {
        cout<<"enter details of process "<<i+1<<endl;
        cout<<"arrival time : \t";
        cin>>arrival_time[i];
        cout<<"burst time : \t";
        cin>>burst_time[i];
        rt[i] = burst_time[i];
    }

    cout<<"enter time quantum : \t";
    cin>>time_quantum;

    for (ct = 0, i = 0 ; counter!=0;)
    {
        if (rt[i]<=time_quantum && rt[i]>0)
        {
            ct = ct + rt[i];
            rt[i] = 0;
            counter--;

            cout<<"process"<<i+1<<" burst time:"<<burst_time[i]<<" tat time:"<<ct-arrival_time[i]<<" wait time:"<<ct-arrival_time[i]-burst_time[i]<<endl;
            total_wt = total_wt + ct - arrival_time[i] - burst_time[i];
            total_tat = total_tat + ct - arrival_time[i];
        }
        else if (rt[i]>0)
        {
            rt[i] = rt[i]-time_quantum;
            ct = ct + time_quantum;
        }

        if (i==n-1)
        {
            i=0;
        }
        else if(arrival_time[i+1]<=ct)
        {
            i++;
        }
    
    }
 
}