#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
struct process{
	int pid;
	int arrival_time;
	int burst_time;
	int start_time;
	int completion_time;
	int turnaround_time;
	int waiting_time;
	
};
bool comparearr(process p1,process p2){
	return p1.arrival_time<p2.arrival_time;
}
bool compareid(process p1,process p2){
	return p1.pid<p2.pid;
}
bool compareburst(process p1,process p2){
	return p1.burst_time<p2.burst_time;
}
int main(){
	int n;
	struct process p[100];
	float avgtat,avgwt;
	int total_tat=0,total_wt=0;
	
	cout<<setprecision(2)<<fixed;
	cout<<"Enter the no of process:";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Enter arrival time"<<i+1<<":";
		cin>>p[i].arrival_time;
		cout<<"Enter burst time"<<i+1<<":";
		cin>>p[i].burst_time;
		p[i].pid=i+1;
		cout<<endl;
		}
		sort(p,p+n,comparearr);
		sort(p,p+n,compareburst);
	    for(int i=0;i<n;i++){
	    	p[i].start_time=(i==0)?p[i].arrival_time:max(p[i-1].completion_time,p[i].arrival_time);
	    	p[i].completion_time=p[i].start_time+p[i].burst_time;
	    	p[i].turnaround_time=p[i].completion_time-p[i].arrival_time;
	    	p[i].waiting_time=p[i].turnaround_time-p[i].burst_time;
	    	avgtat=avgtat+p[i].turnaround_time;
	    	avgwt=avgwt+p[i].waiting_time;
		}
		sort(p,p+n,compareid);
		
		cout<<endl;
		
		cout<<"process\t\t"<<"arrival time\t\t"<<"burst time\t\t"<<"completion time\t\t"<<"tat\t\t\t"<<"wt";
		cout<<endl;
		for(int i=0;i<n;i++){
		cout<<p[i].pid<<"\t\t"<<p[i].arrival_time<<"\t\t"<<p[i].burst_time<<"\t\t"<<p[i].completion_time<<"\t\t"<<p[i].turnaround_time<<"\t\t"<<p[i].waiting_time;
		cout<<endl;
		
		}
		cout<<"\nAverage waiting time:"<<avgwt/n;
		cout<<"\nAverage turnaround time:"<<avgtat/n;
		return 0;
		
}