// use of calloc -> sum of n numbers using calloc

#include<stdio.h>
#include<stdlib.h>

int main() {
    int *arr;
    int n, sum = 0;

    printf("enter number of element : ");
    scanf("%d",&n);

    arr = (int*)calloc(n, sizeof(int));

    if(arr == NULL) {
        printf("Error! memory not allocated..");
    }

    printf("enter elements : ");
    for(int i=0; i<n; i++) {
        scanf("%d",&arr[i]);
        sum += arr[i];
    }
    printf("Sum = %d",sum);
    free(arr);
}