#include<stdio.h>
#include<stdlib.h>

int partition(int arr[], int st, int end) {
    int pivot = arr[end];
    int idx = st -1;

    for(int j=st; j< end; j++) {
        if(arr[j] < pivot) {
            idx++;
            int temp = arr[j];
            arr[j] = arr[idx];
            arr[idx] = temp;
        }
    }
    idx++;
    int temp = arr[end];
    arr[end] = arr[idx];
    arr[idx] = temp;
    return idx;
}

void quickSort(int arr[], int st, int end) {
    if(st < end) {
        int pIdx = partition(arr, st, end);
        quickSort(arr, st, pIdx-1);
        quickSort(arr, pIdx+1, end);
    }
}



int main() {
    int arr[] = {23,65,7,45,99,11,6,9,54};
    int size = sizeof(arr)/ sizeof(arr[0]);

    printf("Sorted array : ");

    quickSort(arr,0,size-1);
    for(int i=0;i<size;i++) {
        printf("%d ",arr[i]);
    }
}