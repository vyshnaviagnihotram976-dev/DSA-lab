//AIM: to convert infix expression to postfix expression using stack in c
/*
Algorithm:
Initialize:

Create an empty stack for operators.

Create an empty string for POSTFIX.

Scan INFIX from left to right:

Case 1: If the symbol is an operand, add it to POSTFIX.

Case 2: If the symbol is '(', push it onto the stack.

Case 3: If the symbol is ')',
→ Pop and add all operators from the stack to POSTFIX until '(' is found.
→ Pop and discard '('.

Case 4: If the symbol is an operator (op1),
→ While the stack is not empty and the precedence of the top of the stack (op2) ≥ op1,
pop op2 from the stack and add it to POSTFIX.
→ Push op1 onto the stack.

After scanning the expression:

Pop all remaining operators from the stack and add them to POSTFIX.

End

*/


#include <stdio.h>
#include <ctype.h>   // for isalpha() and isdigit()
#include <string.h>
#define MAX 100
typedef struct {
    char arr[MAX];
    int top;
} Stack;
void init(Stack *s) {
    s->top = -1;
}
int isEmpty(Stack *s) {
    return s->top == -1;
}
int isFull(Stack *s) {
    return s->top == MAX - 1;
}
void push(Stack *s, char c) {
    if (!isFull(s)) {
        s->arr[++(s->top)] = c;
    }
}
char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return '\0';  // stack empty
}
char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[s->top];
    }
    return '\0';
}
// Function to return precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
    return 0;
}
// Check if character is operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}
void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    init(&s);
    int k = 0;  // Index for postfix
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        // If operand (letter or digit), add to postfix
        if (isalnum(c)) {
            postfix[k++] = c;
        }
        // If '(', push to stack
        else if (c == '(') {
            push(&s, c);
        }
        // If ')', pop and output until '('
        else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s);  // Remove '(' from stack
        }
        // If operator
        else if (isOperator(c)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(c)) {
                if (c == '^' && peek(&s) == '^') {
                    // Right associative operator '^' should not pop same precedence operator
                    break;
                } else {
                    postfix[k++] = pop(&s);
                }
            }
            push(&s, c);
        }
    }

    // Pop all remaining operators
    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0';  // Null-terminate postfix string
}

int main() {
    char infix[MAX];
    char postfix[MAX];
    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0';  // Remove trailing newline
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
