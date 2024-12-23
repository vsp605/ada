#include <stdio.h>
int gcd(int a,int b)
 {
    int min=(a<b)?a:b; 
    for (int i=min;i>0;i--) 
    { 
        if (a%i==0&&b%i==0)
         { 
            return i;
        }
    }
    return 1; 
}
int main()
 {
    int m,n,res; 
    printf("Enter two numbers:\n"); 
    scanf("%d %d",&m,&n); 
    res=gcd(m,n);
    printf("The GCD of  is: %d\n",res);
    return 0; 
}
