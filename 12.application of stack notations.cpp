#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX_STACK_SIZE - 1;
}

void push(Stack *s, int value) {
    if (!isFull(s)) {
        s->data[++(s->top)] = value;
    } else {
        printf("Stack is full. Cannot push %d.\n", value);
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    } else {
        printf("Stack is empty.\n");
        return -1;
    }
}

int evaluatePostfix(char *expression) {
    Stack stack;
    initialize(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        }
    }

    return pop(&stack);
}

int main() {
    char postfixExpression[] = "62+5*8-";
    int result = evaluatePostfix(postfixExpression);
    printf("Result of %s is %d\n", postfixExpression, result);
    return 0;
}
