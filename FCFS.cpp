#include <iostream>

using namespace std;

void findTat(int p[], int n, int bt[], int tat[], int at[])
{
    int exittime[n];
    exittime[0]=bt[0];
    for (int i =1 ; i<n; i++)
    {
        exittime[i]=exittime[i-1]+bt[i];
    }
    for (int i =0; i<n;i++)
    {
        tat[i]=exittime[i]-at[i];
    }
}

void findwt(int p[], int n,int bt[], int tat[], int wt[])
{
    for(int i=0;i<n;i++)
    {
        wt[i]=tat[i]-bt[i];
    }
}

void findAvgTime(int p[], int n,int bt[], int at[])
{
    int wt[n], tat[n], totwt = 0, tottat= 0;

    findTat(p, n, bt,tat,at);
    findwt(p, n, bt,tat,wt);

    cout << "process"
         << "   Burst time"
         << "   Turn around time"
         << "   Waiting time"<<endl;

    for (int i =0 ; i<n ; i++)
    {
        tottat = tottat + tat[i];
        totwt = totwt + wt[i];

        cout << "       "<< i+1<<"       "<<bt[i]<<"       "<<tat[i]<<"        "<<wt[i]<<endl;
    }
        float avgtat = (float)tottat/(float)n;
        float avgwt = (float)totwt/(float)n;

        cout<<"Average turn around time is  "<< avgtat<<endl;
        cout<<"Average wating time is  "<< avgwt <<endl;   

}

int main (){
    int n ;
    cout <<"Enter no process "<<endl;
    cin>>n;
    int process[n];

    for(int i=0; i<n;i++)
    {
        process[i]=i+1;
    }
    int burst_time[n];
    int arrival_time[n];
    cout <<"Enter burst time and arrival time of each process"<<endl;
    for (int i=0; i<n;i++)
    {
        cout<<"For process"<<i+1<<endl;
        cin>> burst_time[i]>> arrival_time[i];
    }

    findAvgTime(process,n,burst_time,arrival_time);

    return 0;
}