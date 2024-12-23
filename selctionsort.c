#include <stdio.h>
#include <time.h> 
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = {64, 25, 12, 22, 11, 90};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("Given array is: \n");
    printArray(arr, arr_size);
    clock_t start_time = clock();
    selectionSort(arr, arr_size);
    clock_t end_time = clock();
    printf("\nSorted array is: \n");
    printArray(arr, arr_size);
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nTime taken for SelectionSort: %f seconds\n", time_taken);
    return 0;
}

