/*Write a Menu driven C program to accomplish the following functionalities in Queue using
an Array:
a. Insert an element into the queue using an array (Enqueue Operation).
b. Delete an element from the queue using an array (Dequeue Operation).
c. Return the value of the FRONT element of the queue (without deleting it from the
queue) using an array (Peep operation).
d. Display the elements of a queue using an array.*/
#include <stdio.h>

#include <stdlib.h>
#define MAX 5
int queue[MAX],front = -1, rear = -1;
 

// Function to check if the queue is full
int isFull() {
    return (rear == MAX - 1);
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1 || front > rear);
}

// Function to insert an element into the queue (Enqueue)
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full! Cannot insert element.\n");
    } else {
        if (front == -1) {
            front = 0;  // Initialize front if it's the first element
        }
        rear++;
        queue[rear] = value;
        printf("Inserted %d into the queue.\n", value);
    }
}

// Function to delete an element from the queue (Dequeue)
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue element.\n");
    } else {
        printf("Deleted %d from the queue.\n", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1;  // Reset the queue when it becomes empty
         }
    }
}

// Function to get the front element of the queue (Peep)
void peep() {
    if (isEmpty()) {
        printf("Queue is empty! No front element to display.\n");
    } else {
        printf("The front element is: %d\n", queue[front]);
    }
}

// Function to display all the elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty! No elements to display.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
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

