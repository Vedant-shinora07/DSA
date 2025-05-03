#include<stdio.h>

int recursive(int arr[], int low, int high, int value) {
    if(low > high) return -1;

    int mid = (low + high)/2;

    if(arr[mid] == value) return mid;
    else if(arr[mid] < value) return recursive(arr, mid+1, high, value);
    else return recursive(arr, low, mid-1, value);
}

int main() {
    int arr[] = {10,20,30,40,50};
    int size = sizeof(arr)/sizeof(arr[0]);

    int value = 30;

    int result = recursive(arr, 0, size-1, value);

    if(result != -1) {
        printf("Element %d found at index %d",value, result);
    } else {
        printf("Element not found..!");
    }
}