#include <stdio.h>
#include <time.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);  for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++; 
            swap(&arr[i], &arr[j]); 
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1); 
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = {6545,12, 11, 13, 5, 6,8,8,7,6,87,42,75,5,541,7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("Given array is: \n");
    printArray(arr, arr_size);
    clock_t start_time = clock();
    quickSort(arr, 0, arr_size - 1);
    clock_t end_time = clock();
    printf("\nSorted array is: \n");
    printArray(arr, arr_size);
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nTime taken for QuickSort: %f seconds\n", time_taken);
    return 0;
}
