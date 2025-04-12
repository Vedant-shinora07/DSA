// compare two strings..

#include<stdio.h>

int compare(char str1[], char str2[]) {
    int i=0;
    
    for(i=0;str1[i] != '\0', str2[i] != '\0';i++) {
        if(str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
    } 
    return str1[i] - str2[i];
}

int main() {
    char str1[] = "Hello";
    char str2[] = "World";

    int result = compare(str1,str2);

    if(result == 0) {
        printf("Strings are equal \n");
    }
    else if(result < 0) {
        printf("\"%s\" comes before \"%s\" in dictionary order\n",str1,str2);
    }
    else {
        printf("\"%s\" comes after \"%s\" in dictionary order\n",str1,str2);
    }
}