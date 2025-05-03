#include<stdio.h>

int Binarysearch(int arr[], int size, int value) {
    int low = 0, high = size - 1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == value) return mid;
        else if(arr[mid] < value) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {10,20,30,40,50}; // must be sorted
    int size = sizeof(arr)/sizeof(arr[0]);
    int value = 30;

    int result = Binarysearch(arr,size,value);

    if(result != -1) {
        printf("element found at index %d", result);
    } else {
        printf("Element not found..");
    }
}