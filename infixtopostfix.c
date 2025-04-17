#include <stdio.h>
#include <ctype.h>  // For isalnum()

char stack[20];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;
    else
        return -1;
}

int main() {
    int i;
    char a[20], c, x;

    printf("Enter infix expression: ");
    fgets(a, sizeof(a), stdin); // safer than gets()

    printf("Postfix expression is: ");
    for (i = 0; a[i] != '\0' && a[i] != '\n'; i++) {
        c = a[i];

        if (isalnum(c)) {
            printf("%c", c); // operand
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                printf("%c", pop());
            }
            pop(); // remove '(' from stack
        }
        else { // operator
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                printf("%c", pop());
            }
            push(c);
        }
    }

    while (top != -1) {
        printf("%c", pop());
    }

    return 0;
}

