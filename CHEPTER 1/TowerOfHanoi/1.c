#include<stdio.h>

void TowerOfHanoi(int n, char source, char aux, char dest) {
    if(n == 1) {
        printf("Move disk 1 from %c to %c\n",source, dest);
        return;
    }

    TowerOfHanoi(n-1, source, dest, aux);

    printf("Move disk %d from %c to %c\n",n,source,dest);

    TowerOfHanoi(n-1, aux,source, dest);
}

int main() {
    int n;

    printf("Enter the number of disks : ");
    scanf("%d",&n);

    printf("steps to solve tower of Hanoi for %d disks :\n ",n);

    TowerOfHanoi(n,'A','B','C');
}