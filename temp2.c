#include <stdio.h>
int main() {
    int n,a[20],key;
    printf("Enter how many numbers in array:\n");
    scanf("%d",&n);
    printf("Enter elements in array:\n");
    for (int i=0;i<n;i++)
     {
        scanf("%d",&a[i]);
    }
    printf("Enter a key number to search:\n");
    scanf("%d",&key);
    int result=linearsearch(a,n,key);
    if (result!=-1) 
    {
        printf("Key %d found at index %d.\n",key,result);
    }
     else
     {
        printf("Key %d not found in the array.\n",key);
    }
    return 0;
}
int linearsearch(int a[],int n,int key)
{
	int flag=0;
	for (int i=0;i<n;i++) 
    {
        if (key==a[i]) {
            return i;
            flag=1;
            break;
        }
    }
    if (flag==0) {
        return -1;
    }
    return 0;
}
	
