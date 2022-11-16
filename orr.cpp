#include<iostream>
using namespace std;
class opr
{
	public :
	int oprr(int p[],int fr[],int f, int n, int index)
	{
		int res=-1,farthest = index,i,j;
		for(i=0;i<f;i++)
		{
			for(j=index;j<n;j++)
			{
				if (fr[i] == p[j])
				{
					if (j >farthest)
					{
						farthest = j;
						res =i;
					}
					break;
				}
				
			}
			if(j==n)
				return i;	
		}
		if(res == -1)
			return 0;
		else 
			return res;
	}
};
int main()
{
	opr x;
	int n,j,k,i,flag,f,c=0,index=0;;
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
	}
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=0;j<f;j++)
		{
			if(p[i]==fr[j])
			{
				flag=1;
				break;
			}
		}
		if (flag==0)
		{
			if(index < f)
			{
				fr[index]=p[i];
				index ++;
			}
			else
			{
				j=x.oprr(p,fr,f,n,i+1);
				fr[j]=p[i];
				
			} 
			c++;
		}
	}
	cout<<"................"<<c;
}
