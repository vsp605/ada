#include <stdio.h>
#include <time.h> 
void merge(int arr[], int left, int mid, int right)
 {
    int n1 = mid - left + 1; 
    int n2 = right - mid; 
    int leftArr[n1], rightArr[n2];
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) 
        {
            arr[k] = leftArr[i];
            i++;
        } else 
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < n1)
     {
        arr[k] = leftArr[i];
        i++;
        k++;
    } while (j < n2)
     {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int left, int right)
 {
    if (left < right) 
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
void printArray(int arr[], int size)
 {
    for (int i = 0; i < size; i++)
     {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
 {
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    clock_t start_time = clock();
    printf("Given array is \n");
    printArray(arr, arr_size);
    mergeSort(arr, 0, arr_size - 1);
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nTime taken to sort the array: %f seconds\n", time_taken);
    return 0;
}
