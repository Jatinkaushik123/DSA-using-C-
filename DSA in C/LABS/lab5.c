#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Size of the queue

int queue[MAX];
int front = -1;
int rear = -1;

// Function declarations
void enqueue();
void dequeue();
void peek();
void display();

int main() {
    int choice;
    
    while(1) {
        printf("\n--- Queue Menu (Array Implementation) ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter between 1 to 5.\n");
        }
    }
    return 0;
}

// Function to insert an element into the queue
void enqueue() {
    int val;
    // Check for Overflow condition
    if (rear == MAX - 1) {
        printf("Overflow! Queue is full.\n");
    } else {
        printf("Enter the element to insert: ");
        scanf("%d", &val);
        
        // If queue is initially empty
        if (front == -1 && rear == -1) {
            front = 0;
            rear = 0;
        } else {
            rear++;
        }
        queue[rear] = val;
        printf("Inserted %d successfully.\n", val);
    }
}

// Function to delete an element from the queue
void dequeue() {
    // Check for Underflow condition
    if (front == -1 || front > rear) {
        printf("Underflow! Queue is empty.\n");
        // Reset pointers if queue becomes empty
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    } else {
        printf("Deleted element is: %d\n", queue[front]);
        front++;
        
        // Reset pointers if queue becomes empty after deletion
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}

// Function to view the front element without deleting it
void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element is: %d\n", queue[front]);
    }
}

// Function to display all elements in the queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}