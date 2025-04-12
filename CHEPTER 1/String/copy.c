// copy string..

#include <stdio.h>

int copy(char str[], char dest[])
{
    int i = 0;
    for (i=0;str[i] != '\0';i++)
    {
        dest[i] = str[i];
    }
    dest[i] = '\0';
}

int main()
{
    
    char str[] = "Hello World!";
    char dest[50];

    copy(str, dest);

    printf("Copied string : %s ", dest);
}