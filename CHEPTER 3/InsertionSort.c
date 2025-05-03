#include<stdio.h>

void selectionSort(int arr[], int n) {
   for(int i=1; i<n; i++) {
    int temp = arr[i];
    int j = i-1;

    while(j>=0 && arr[j] > temp) {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = temp;
   }
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {13,2,34,54,43,32,67,65};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array without sorting :\n");
    printArray(arr, n);

    selectionSort(arr,n);

    printf("array after sorting :\n");
    printArray(arr, n);
}