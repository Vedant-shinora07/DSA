// count Vowels and Constants..

#include <stdio.h>
#include <ctype.h>

int count(char str[], int *vowels, int *constants)
{
    *vowels = 0, *constants = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = tolower(str[i]);
        if (ch >= 'a' && ch <= 'z')
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                (*vowels)++;
            }
            else
            {
                (*constants)++;
            }
        }
    }
}

int main()
{
    int vowels, constants;
    char str[] = {"Hello World"};

    count(str, &vowels, &constants);
    printf("There are %d vowels and %d constants", vowels, constants);
}