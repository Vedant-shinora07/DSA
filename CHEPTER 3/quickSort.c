#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int st, int end) {
    int pivot = arr[end];
    int idx = st - 1;

    for(int j=st; j< end ; j++) {
        if(arr[j] <= pivot) {
            idx++;
            swap(&arr[idx], &arr[j]);
        }
    }
    idx++;
    swap(&arr[idx], &arr[end]);
    return idx;
}

void quickSort(int arr[], int st, int end) {
    if(st < end) {
        int pIdx = partition(arr, st, end);
        quickSort(arr, st, pIdx - 1);
        quickSort(arr, pIdx + 1, end);
    }
}

int main() {
    int arr[] = {23,45,43,65,1,5,76};
    int size = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, size-1);

    for(int i=0; i< size; i++) {
        printf("%d ",arr[i]);
    }
}