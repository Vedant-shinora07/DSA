#include<stdio.h>

int recursive(int arr[], int size, int value, int index) {
    if(index == size) return -1; // base case
    if(arr[index] == value) return index;

        recursive(arr, size, value, index + 1);
}

int main() {
    int arr[] = {10,20,30,40,50};
    int size = sizeof(arr)/sizeof(arr[0]);

    int value = 10;

    int result = recursive(arr, size, value, 0);

    if(result != -1) {
        printf("Element %d found at index %d",value,result);
    } else {
        printf("Element not found.!");
    }
}