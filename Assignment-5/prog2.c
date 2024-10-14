/*Write a Menu driven C program to accomplish the following functionalities in Queue using
Linked List:
e. Insert an element into the queue using a Linked List (Enqueue Operation).
f. Delete an element from the queue using a Linked List (Dequeue Operation).
g. Return the value of the FRONT element of the queue (without deleting it from the
queue) using a Linked List (Peep operation).
h. Display the elements of a queue using a Linked List.*/
#include <stdio.h>
#include <stdlib.h>

// Node structure for the queue
struct Node {
    int data;
    struct Node* next;
};

// Front and Rear pointers of the queue
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to check if the queue is empty
int isEmpty() {
    return front == NULL;
}

// Function to insert an element into the queue (Enqueue)
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed! Cannot insert element.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty()) {
        front = rear = newNode;  // Both front and rear will point to the new node if the queue is empty
    } else {
        rear->next = newNode;    // Insert the new node at the end of the queue
        rear = newNode;
    }
    printf("Inserted %d into the queue.\n", value);
}

// Function to delete an element from the queue (Dequeue)
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue element.\n");
    } else {
        struct Node* temp = front;
        printf("Deleted %d from the queue.\n", front->data);
        front = front->next;  // Move the front pointer to the next node

        if (front == NULL) {
            rear = NULL;  // If the queue becomes empty, reset rear as well
        }
        free(temp);  // Free the memory of the dequeued node
    }
}

// Function to return the front element of the queue (Peep)
void peep() {
    if (isEmpty()) {
        printf("Queue is empty! No front element to display.\n");
    } else {
        printf("The front element is: %d\n", front->data);
    }
}

// Function to display all elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty! No elements to display.\n");
    } else {
        struct Node* temp = front;
        printf("Queue elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue (Insert an element)\n");
        printf("2. Dequeue (Remove an element)\n");
        printf("3. Peep (Return the front element)\n");
        printf("4. Display the queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peep();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

