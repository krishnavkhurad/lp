#include<iostream>
using namespace std;
int main()
{
	int n,f,i,flag,r=0,c=0,j;
	cout<<"enter the string length  : "<< endl;
	cin>>n;
	cout<<"enter the number of frames  : "<< endl;
	cin>>f;
	int p[n],fr[f];
	cout<<"enter the page values  : "<< endl;
	for(i=0;i<n;i++)
	{
		cin>>p[i];
	}
	for(i=0;i<f;i++)
	{
		fr[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<f;j++)
		{
			flag=0;
			if(p[i]==fr[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			fr[r]=p[i];
			r++;
			if(r==f)
			{
				r=0;
			}
			c++;	
		}
	}
	cout<<"no. of faults  :"<<c<<endl;
	cout<<"no. of hits  :"<<(n-c)<<endl;
}
