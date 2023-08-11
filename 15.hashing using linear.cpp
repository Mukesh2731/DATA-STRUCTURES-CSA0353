#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Hash table structure
typedef struct {
    int key;
    int value;
} HashEntry;

// Hash table array
HashEntry hashTable[SIZE];

// Initialize the hash table
void initHashTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i].key = -1;
        hashTable[i].value = -1;
    }
}

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert a key-value pair into the hash table using linear probing
void insert(int key, int value) {
    int index = hash(key);

    while (hashTable[index].key != -1) {
        index = (index + 1) % SIZE; // Move to the next slot
    }

    hashTable[index].key = key;
    hashTable[index].value = value;
}

// Search for a value in the hash table
int search(int key) {
    int index = hash(key);

    while (hashTable[index].key != -1) {
        if (hashTable[index].key == key) {
            return hashTable[index].value;
        }
        index = (index + 1) % SIZE; // Move to the next slot
    }

    return -1; // Key not found
}

// Display the hash table
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("[%d] -> Key: %d, Value: %d\n", i, hashTable[i].key, hashTable[i].value);
    }
}

int main() {
    initHashTable();

    insert(5, 50);
    insert(15, 150);
    insert(25, 250);
    insert(35, 350);

    display();

    int keyToSearch = 25;
    int result = search(keyToSearch);

    if (result != -1) {
        printf("Value for key %d: %d\n", keyToSearch, result);
    } else {
        printf("Key %d not found.\n", keyToSearch);
    }

    return 0;
}
