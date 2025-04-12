// Concatenation of strings ("Merge two strings..")

#include <stdio.h>

int Concat(char str1[], char str2[])
{
    int i = 0, j = 0;

    for( i=0; str1[i] != '\0'; i++) {}
    for( j=0; str2[j] != '\0';i++, j++) {
        str1[i] = str2[j];
    }
    str1[i] = '\0';
}

int main()
{
    char str1[] = {"Hello, "};
    char str2[] = {"world!"};

    Concat(str1, str2);

    printf("Concatenated string is %s\n", str1);
}