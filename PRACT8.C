#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 5  // Maximum number of orders

int queue[MAX];
int front = -1, rear = -1;

void placeOrder(int order) {
    if (rear == MAX - 1) {
        printf("\nOrder list is full! Cannot accept more orders.\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = order;
        printf("\nOrder %d placed successfully.\n", order);
    }
}

void serveOrder() {
    if (front == -1 || front > rear) {
        printf("\nNo orders to serve.\n");
    } else {
        printf("\nOrder %d served.\n", queue[front]);
        front++;
        if (front > rear)
            front = rear = -1;
    }
}

void displayOrders() {
    int i;
    if (front == -1)
        printf("\nNo pending orders.\n");
    else {
        printf("\nCurrent Orders in Queue:\n");
        for (i = front; i <= rear; i++)
            printf("Order %d\n", queue[i]);
    }
}

void main() {
    int choice, orderNo = 1;
    clrscr();

    while (1) {
        printf("\n--- Pizza Parlor Order System ---\n");
        printf("1. Place Order\n");
        printf("2. Serve Order\n");
        printf("3. Display Pending Orders\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                placeOrder(orderNo++);
                break;
            case 2:
                serveOrder();
                break;
            case 3:
                displayOrders();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    getch();
}
