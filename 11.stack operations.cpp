#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Initialize stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Check if stack is empty
int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

// Check if stack is full
int isFull(struct Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Push an element onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Peek at the top element of the stack
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    printf("Top element: %d\n", peek(&stack));

    return 0;
}
