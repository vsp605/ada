#include <stdio.h>
int gcd(int m, int n)
 {
    int min=(m<n)?m:n;
    for(int i=min;i>0;i--)
     {
        if (m%i==0&&n%i==0)
         {
            return i;
        }
    }
    return 1;
}
int main() {
    int m,n,res;
    printf("Enter m and n:\n");
    scanf("%d%d",&m,&n);
    res = gcd(m,n);
    printf("GCD of two numbers is: %d\n",res);
    return 0;
}

