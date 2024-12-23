#include <stdio.h>
int gcd(int m, int n) 
{
    if (m<0)m=-m;
    if (n<0)n=-n;
    while (n!=0)
     {
        int t=n;
        n=m%n;
        m=t;
    }
    return m;
}
int main() 
{
    int m,n,res;
    printf("Enter m and n:\n");
    scanf("%d%d",&m,&n);
    res = gcd(m,n);
    printf("GCD of two numbers is: %d\n",res);
    return 0;
}
