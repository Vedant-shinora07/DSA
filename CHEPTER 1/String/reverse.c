// Reverse a string..

#include <stdio.h>
#include <string.h>

void reverseString(char str[])
{
    int right = strlen(str) - 1;
    for (int left = 0; left < right; left++, right--)
    {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
    }
}
int main()
{
    char str[] = {"vedant"};
    reverseString(str);
    printf("Reversed string is %s ", str);
}