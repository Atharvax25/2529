#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int value) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

int height(struct node* root) {
    int lheight, rheight;
    if (root == NULL)
        return 0;
    lheight = height(root->left);
    rheight = height(root->right);
    if (lheight > rheight)
        return (lheight + 1);
    else
        return (rheight + 1);
}

int findMin(struct node* root) {
    struct node* current = root;
    while (current != NULL && current->left != NULL)
        current = current->left;
    return current->data;
}

void mirror(struct node* root) {
    struct node* temp;
    if (root == NULL)
        return;
    mirror(root->left);
    mirror(root->right);
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int search(struct node* root, int key) {
    if (root == NULL)
        return 0;
    if (root->data == key)
        return 1;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void main() {
    struct node* root = NULL;
    int i, n, val, key;

    clrscr();

    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);

    printf("Enter values to insert in BST:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("\nInorder traversal of BST: ");
    inorder(root);

    printf("\n\nEnter a new value to insert: ");
    scanf("%d", &val);
    root = insert(root, val);

    printf("Inorder traversal after insertion: ");
    inorder(root);

    printf("\n\nNumber of nodes in longest path (Height) = %d", height(root));

    printf("\nMinimum value in the tree = %d", findMin(root));

    /* Search BEFORE mirror */
    printf("\n\nEnter value to search: ");
    scanf("%d", &key);

    if (search(root, key))
        printf("\nValue %d found in the tree.", key);
    else
        printf("\nValue %d not found in the tree.", key);

    /* Now mirror and show */
    mirror(root);
    printf("\n\nBST after swapping left and right pointers (Mirror): ");
    inorder(root);

    getch();
}
