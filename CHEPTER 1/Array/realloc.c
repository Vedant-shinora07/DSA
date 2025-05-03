// use of realloc -> add more numers using realloc

#include<stdio.h>
#include<stdlib.h>

int main() {
    int *arr;
    int n, new_n, sum = 0;

    printf("enter number of elements : ");
    scanf("%d", &n);

    arr = (int*)malloc(n*sizeof(int));

    if(arr == NULL) {
        printf("failed! memory not allocated..");
        return 1;
    }
    printf("\nEnter elements : ");
    for(int i=0; i<n; i++) {
        scanf("%d",&arr[i]);
        sum += arr[i];
    }
    printf("\nCurrent sum = %d",sum);

    printf("\nenter the new total number of elements : ");
    scanf("%d",&new_n);

    arr = (int*)realloc(arr, new_n*sizeof(int));

    if(arr == NULL) {
        printf("failed! memory not allocated..");
        return 1;
    }

    if(new_n > n) {
        printf("\nenter %d more elements : ",new_n - n);
        for(int i=n; i<new_n; i++) {
            scanf("%d",&arr[i]);
            sum += arr[i];
        }
        printf("\nTotal sum = %d",sum);
        free(arr);
    }
}