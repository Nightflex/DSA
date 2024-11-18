#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

// Function to check precedence of operators
int precedence(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0;
}

// Function to convert infix to postfix
void infixToPostfix(char *infix, char *postfix) {
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];  // If operand, add to postfix
        } else if (infix[i] == '(') {
            push(infix[i]);           // Push '(' to stack
        } else if (infix[i] == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();  // Pop till '('
            }
            pop();                     // Remove '('
        } else {  // Operator
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }
    while (top != -1) {
        postfix[j++] = pop();  // Pop remaining operators
    }
    postfix[j] = '\0';
}

// Function to reverse a string
void reverse(char *exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

// Function to convert infix to prefix
void infixToPrefix(char *infix, char *prefix) {
    reverse(infix);  // Step 1: Reverse infix expression
    for (int i = 0; i < strlen(infix); i++) {
        if (infix[i] == '(') infix[i] = ')';  // Step 2: Replace '(' with ')'
        else if (infix[i] == ')') infix[i] = '(';
    }
    char postfix[MAX];
    infixToPostfix(infix, postfix);  // Step 3: Convert to postfix
    reverse(postfix);                // Step 4: Reverse postfix to get prefix
    strcpy(prefix, postfix);
}

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    gets(infix);

    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);

    infixToPrefix(infix, prefix);
    printf("Prefix: %s\n", prefix);

    return 0;
}