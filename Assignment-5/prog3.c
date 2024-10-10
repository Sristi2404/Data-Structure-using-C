#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the circular queue

int queue[MAX];
int front = -1, rear = -1;

// Function to check if the circular queue is full
int isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

// Function to check if the circular queue is empty
int isEmpty() {
    return front == -1;
}

// Function to insert an element into the circular queue (Enqueue)
void enqueue(int value) {
    if (isFull()) {
        printf("Circular Queue is full! Cannot insert element.\n");
    } else {
        if (isEmpty()) {
            front = rear = 0;  // Initialize front and rear if inserting the first element
        } else if (rear == MAX - 1 && front != 0) {
            rear = 0;  // Wrap around the rear to the beginning of the array
        } else {
            rear++;
        }
        queue[rear] = value;
        printf("Inserted %d into the circular queue.\n", value);
    }
}

// Function to delete an element from the circular queue (Dequeue)
void dequeue() {
    if (isEmpty()) {
        printf("Circular Queue is empty! Cannot dequeue element.\n");
    } else {
        printf("Deleted %d from the circular queue.\n", queue[front]);
        if (front == rear) {
            front = rear = -1;  // Reset the queue if it becomes empty
        } else if (front == MAX - 1) {
            front = 0;  // Wrap around the front to the beginning of the array
        } else {
            front++;
        }
    }
}

// Function to return the front element of the circular queue (Peep)
void peep() {
    if (isEmpty()) {
        printf("Circular Queue is empty! No front element to display.\n");
    } else {
        printf("The front element is: %d\n", queue[front]);
    }
}

// Function to display all elements of the circular queue
void display() {
    if (isEmpty()) {
        printf("Circular Queue is empty! No elements to display.\n");
    } else {
        printf("Circular Queue elements: ");
        if (front <= rear) {
            for (int i = front; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        } else {
            for (int i = front; i < MAX; i++) {
                printf("%d ", queue[i]);
            }
            for (int i = 0; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nCircular Queue Operations Menu:\n");
        printf("1. Enqueue (Insert an element)\n");
        printf("2. Dequeue (Remove an element)\n");
        printf("3. Peep (Return the front element)\n");
        printf("4. Display the circular queue\n");
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
