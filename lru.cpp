#include<iostream>
using namespace std;
int main ()
{
	int n,j,k,i,flag,f,c=0;
	cout<<"enter the string length  : "<< endl;
	cin>>n;
	cout<<"enter the number of frames  : "<< endl;
	cin>>f;
	int p[n],fr[f],fcount[f];
	cout<<"enter the page values  : "<< endl;
	for(i=0;i<n;i++)
	{
		cin>>p[i];
	}
	for(i=0;i<f;i++)
	{
		fr[i]=-1;
		fcount[i]=0;
	}
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=0;j<f;j++)
		{
		if(p[i]==fr[j])
		{
			flag=1;
			fcount[j]=i+1;
		}
		} 
		if(flag==0)
		{
			int min=0;
			for(k=0;k<f-1;k++)
			{
				if(fcount[min]>fcount[k+1])
				{
					min=k+1;
				}
			}
			fr[min]=p[i];
			fcount[min]=i+1;
			c++;
		}
	}
	cout<<"no of page faults :"<<c<<endl;
}
