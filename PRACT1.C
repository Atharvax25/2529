#include <stdio.h>
#include <conio.h>

#define MAX 100

int linearSearch(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

void main() {
    int rollNumbers[MAX];
    int n, key, result, i;

    clrscr();

    printf("Enter the number of students who attended the training: ");
    scanf("%d", &n);

    printf("\nEnter the roll numbers of students:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &rollNumbers[i]);
    }

    printf("\nEnter the roll number to search: ");
    scanf("%d", &key);

    result = linearSearch(rollNumbers, n, key);

    if (result != -1)
        printf("\nStudent with roll number %d attended the training program.", key);
    else
        printf("\nStudent with roll number %d did NOT attend the training program.", key);

    getch();
}
