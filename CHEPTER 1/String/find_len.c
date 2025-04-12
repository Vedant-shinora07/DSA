// find string length

#include <stdio.h>

int findlen(char str[])
{
    int i;
    for(i=0;str[i] != '\0';i++) {}
    return i;
}

int main()
{
    char str[] = {"Hello World!"};
    printf("Length of the string is %d\n", findlen(str));
}