// check if a string is palindrome..

#include<stdio.h>
#include<string.h>

int palindrome(char str[]) {
    int left = 0, right = strlen(str) - 1;

    for(left = 0;left < right; left++,right--){
        if(str[left] != str[right]) {
            return 0;
        }
    } return 1;
}

int main() {
    char str[] = {"madam"};

    if(palindrome(str)) {
        printf("\"%s\" is a palindrome ",str);
    } else {
        printf("\"%s\" is not a palindrome ",str);
    }   
}