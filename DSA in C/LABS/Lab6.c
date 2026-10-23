#include <stdio.h>
#include <stdlib.h>

// Structure to represent a customer node in the priority queue
typedef struct Node {
    int id;
    int priority;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int id, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->id = id;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a customer based on priority (lower value = higher priority)
// If priorities are equal, it maintains FIFO order.
void enqueue(Node** head, int id, int priority) {
    Node* newNode = createNode(id, priority);

    // If queue is empty or new customer has higher priority than the head
    if (*head == NULL || priority < (*head)->priority) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse the list to find the appropriate position
    Node* current = *head;
    while (current->next != NULL && current->next->priority <= priority) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to remove and return the customer ID at the front
int dequeue(Node** head) {
    if (*head == NULL) {
        return -1; // Queue is empty
    }
    Node* temp = *head;
    int id = temp->id;
    *head = (*head)->next;
    free(temp);
    return id;
}

int main() {
    Node* pq = NULL;
    int n, id, priority;

    printf("Enter total number of customers: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter Customer ID and Priority (lower value = higher priority) for each:\n");
    for (int i = 0; i < n; i++) {
        printf("Customer %d (ID Priority): ", i + 1);
        scanf("%d %d", &id, &priority);
        enqueue(&pq, id, priority);
    }

    // Serving the first four customers
    int servedCount = 4;
    printf("\n--- Serving First 4 Customers ---\n");
    for (int i = 1; i <= servedCount; i++) {
        int servedId = dequeue(&pq);
        if (servedId != -1) {
            printf("Customer %d served: ID = %d\n", i, servedId);
        } else {
            printf("Customer %d: Queue became empty!\n", i);
        }
    }

    // Finding the customer who gets serviced immediately after the first four (the 5th customer)
    int nextCustomer = dequeue(&pq);
    printf("\n---------------------------------\n");
    if (nextCustomer != -1) {
        printf("Customer ID to get service after the first four customers: %d\n", nextCustomer);
    } else {
        printf("There are no customers left in the queue after the first four.\n");
    }

    // Clean up any remaining nodes
    while (pq != NULL) {
        dequeue(&pq);
    }

    return 0;
}