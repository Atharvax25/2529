#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = c;
}

char pop() {
    if (top == -1)
        return '\0';
    else
        return stack[top--];
}

int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')')
        return 1;
    if (open == '{' && close == '}')
        return 1;
    if (open == '[' && close == ']')
        return 1;
    return 0;
}

int checkParenthesis(char expr[]) {
    int i;
    char ch, temp;

    for (i = 0; expr[i] != '\0'; i++) {
        ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[')
            push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') {
            temp = pop();
            if (!isMatchingPair(temp, ch))
                return 0;
        }
    }

    if (top == -1)
        return 1;
    else
        return 0;
}

void main() {
    char expr[MAX];
    clrscr();

    printf("Enter an expression: ");
    gets(expr);

    if (checkParenthesis(expr))
        printf("\nExpression is well parenthesized.");
    else
        printf("\nExpression is NOT well parenthesized.");

    getch();
}
