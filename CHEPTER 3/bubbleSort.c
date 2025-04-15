#include<stdio.h>

void BubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j< n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main() {
   int arr[] = {10, 34, 56, 6, 23, 65};
   int n = sizeof(arr) / sizeof(arr[0]);

   printf("array without sorting\n");
   printArray(arr, n);

   BubbleSort(arr, n);

    printf("array after sorting\n");
   printArray(arr, n);
}
