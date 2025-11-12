#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void createList(int n) {
    struct Node *newNode, *temp;
    int data, i;

    head = (struct Node *)malloc(sizeof(struct Node));

    if (head == NULL) {
        printf("Unable to allocate memory.");
        return;
    }

    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;

    temp = head;

    for (i = 2; i <= n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Unable to allocate memory.");
            break;
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
    }
}

void addNode() {
    struct Node *newNode, *temp;
    int data;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Unable to allocate memory.");
        return;
    }

    printf("Enter data to insert at end: ");
    scanf("%d", &data);

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void displayList() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    printf("Linked List Elements:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main() {
    int n, choice;

    clrscr();

    printf("Enter total number of nodes: ");
    scanf("%d", &n);

    createList(n);

    while (1) {
        printf("\n\n--- Linked List Menu ---\n");
        printf("1. Add Node\n");
        printf("2. Display List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNode();
                break;
            case 2:
                displayList();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    getch();
}
