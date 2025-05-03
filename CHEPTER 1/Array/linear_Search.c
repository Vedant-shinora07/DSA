// find an element in an array (linear search)
// Time complexity : O(n)

#include<stdio.h>

int search(int arr[], int size, int value) {
    for(int i=0;i<size;i++) {
        if(arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[5] = {10,20,30,40,50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int value = 50;

    int index = search(arr,size,value);

    if(index != -1) {
        printf("Element %d found at index %d",value,index);
    } else {
        printf("Element not found in the array");
    }
    
}