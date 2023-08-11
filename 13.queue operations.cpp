#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

void initializeQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(struct Queue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}

int isEmpty(struct Queue *queue) {
    return (queue->front == -1);
}

void enqueue(struct Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = value;
        printf("%d enqueued to the queue.\n", value);
    }
}

int dequeue(struct Queue *queue) {
    int value;
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        value = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front++;
        }
        return value;
    }
}

void display(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements:\n");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    display(&queue);

    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));

    display(&queue);

    enqueue(&queue, 40);

    display(&queue);

    return 0;
}
