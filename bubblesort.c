#include <stdio.h>
#include <time.h>
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {         
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
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
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("Given array is: \n");
    printArray(arr, arr_size);
    clock_t start_time = clock();
    bubbleSort(arr, arr_size);
    clock_t end_time = clock();
    printf("\nSorted array is: \n");
    printArray(arr, arr_size);
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nTime taken for BubbleSort: %f seconds\n", time_taken);
    return 0;
}

