#include<stdio.h>

void selectionSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int min = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[min])
            min = j;
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
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