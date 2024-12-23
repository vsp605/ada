#include<stdio.h>
int gcd(int m,int n)
{
	int t;
	if(m<n)
	{
		t=m;
	}
	else
	{
		t=n;
	}
	while(t>0)
	{
		if(m%t==0 && n%t==0)
		{
			return t;
		}
		t=t-1;
	}
	return t;
}
int main()
{
	int m,n,res;
	printf("Enter m and n\n");
	scanf("%d%d",&m,&n);
	res=gcd(m,n);
	printf("GCD of two number is :%d",res);
	return 0;
}

	
