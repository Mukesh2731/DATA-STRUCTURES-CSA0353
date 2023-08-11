#include <stdio.h>
#include <stdlib.h>

// Structure to define a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to delete a node with a specific value from the linked list
void deleteNode(struct Node **head, int data) {
    struct Node *current = *head;
    struct Node *prev = NULL;

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found in the linked list.\n");
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Element %d deleted from the linked list.\n", data);
}

// Function to display the linked list
void display(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;

    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 9);

    printf("Linked list: ");
    display(head);

    deleteNode(&head, 7);
    printf("Linked list after deletion: ");
    display(head);

    return 0;
}
