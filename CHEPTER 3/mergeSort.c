#include<stdio.h>

void merge(int arr[], int st, int mid, int end) {
    int temp[100];
    int i = st, j = mid+1, k = 0;

    while(i<=mid && j<=end) {
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++; k++;
        } else {
            temp[k] = arr[j];
            j++; k++;
        } 
    }
    while(i <= mid) {
        temp[k] = arr[i];
        i++; k++; 
    }
    while(j <= end) {
        temp[k] = arr[j];
        j++; k++;
    }

    for(int idx = 0; idx < k; idx++) {
        arr[st + idx] = temp[idx];
    }
}

void mergeSort(int arr[], int st, int end) {
    if(st < end) {
        int mid = st + (end - st)/2;
        mergeSort(arr, st, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, st, mid, end);
    }
}

int main() {
    int arr[] = {12,35,31,8,32,7};
    int size = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, size-1);
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
}