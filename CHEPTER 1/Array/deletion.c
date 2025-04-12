// Deletion in an array
// Time complexity : O(n)

#include<stdio.h>

void Delete(int arr[], int *size, int pos) {
    for(int i=pos; i<*size-1;i++) {
        arr[i] = arr[i+1];
    }
    (*size)--;
}

int main() {
    int arr[5] = {10,20,30,40,50};
    int size = 5;

    printf("Original array : ");
    for(int i=0;i<size;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    Delete(arr,&size,2);

    printf("array after deletion : ");
    for(int i=0;i<size;i++) {
        printf("%d ",arr[i]);
    }
}