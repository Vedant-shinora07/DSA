// Insert value at a specific position in an array

#include <stdio.h>

void insert(int arr[], int *size, int pos, int value)
{
    for (int i = *size; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*size)++;
}

int main()
{
    int arr[10] = {10, 20, 30, 40, 50};
    int size = 5;

    printf("Original Array : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insert(arr, &size, 2, 99);
    printf("After Insertion : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}