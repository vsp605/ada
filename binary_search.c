#include <stdio.h>
int binarySearch(int arr[], int size, int key) 
{
    int l=0;
    int h=size-1;
    while (l<=h) {
        int mid=l+(h-l)/2;
        if (arr[mid]==key) {
            return mid;
        }
        if (arr[mid]<key) {
            l=mid+1;
        } else {
            h= mid-1;
        }
    }
    return -1;
}
int main() {
    int n,key;
    printf("Enter the number of elements in the array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements in the array:\n");
    for (int i=0; i<n;i++)
     {
        scanf("%d",&arr[i]);
    }
    printf("Enter the key to search for:\n");
    scanf("%d",&key);
    int result=binarySearch(arr,n,key);
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

