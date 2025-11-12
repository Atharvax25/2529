#include <stdio.h>
#include <conio.h>

#define MAX 100

void bubbleSort(float arr[], int n) {
    int i, j;
    float temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void main() {
    float percent[MAX];
    int n, i;

    clrscr();

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("\nEnter first year percentages of students:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &percent[i]);
    }

    bubbleSort(percent, n);

    printf("\nPercentages in Ascending Order:\n");
    for (i = 0; i < n; i++) {
        printf("%.2f\t", percent[i]);
    }

    printf("\n\nTop Five Scores:\n");
    if (n < 5) {
        for (i = n - 1; i >= 0; i--)
            printf("%.2f\t", percent[i]);
    } else {
        for (i = n - 1; i >= n - 5; i--)
            printf("%.2f\t", percent[i]);
    }

    getch();
}
