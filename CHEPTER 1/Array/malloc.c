// use of malloc -> sum of n numbers using malloc

#include<stdio.h>
#include<stdlib.h>

int main() {
    int *arr;
    int n, sum = 0;

    printf("Enter no of elements : ");
    scanf("%d",&n);

    arr = (int*)malloc(n*sizeof(int));

    if(arr == NULL) {
        printf("error! memory not allocated..");
        return 1;
    }

    printf("Enter element : ");
    for(int i=0; i<n; i++) {
        scanf("%d",&arr[i]);
        sum += arr[i];
    }
    printf("Sum = %d",sum);
    free(arr);

    return 0;
}