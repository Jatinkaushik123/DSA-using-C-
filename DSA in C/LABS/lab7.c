#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Global head pointer
struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// 1. Insertion at the beginning
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    if (newNode == NULL) return;

    newNode->next = head;
    head = newNode;
    printf("Inserted %d at the beginning.\n", value);
}

// 2. Insertion at the end
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (newNode == NULL) return;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d at the end.\n", value);
}

// 3. Deletion by value
void deleteNode(int value) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    // If head node itself holds the value to be deleted
    if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        printf("Deleted %d from the list.\n", value);
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list.\n", value);
}

// 4. Traversal by value
void traverseNode(int value) {
    if (head)
}