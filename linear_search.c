#include <stdio.h>
int main() {
    int n,a[20],key,flag=0;
    printf("Enter how many numbers in array:\n");
    scanf("%d",&n);
    if (n>20||n<1)
     {
        printf("Invalid number of elements.\n");
        return 1; 
    }
    printf("Enter elements in array:\n");
    for (int i=0;i<n;i++)
     {
        scanf("%d",&a[i]);
    }
    printf("Enter a key number to search:\n");
    scanf("%d",&key);
    for (int i=0;i<n;i++) 
    {
        if (key==a[i]) {
            printf("Key is found at position %d\n",i);
            flag=1;
            break;
        }
    }
    if (flag==0) {
        printf("Element not found\n");
    }
    return 0;
}
