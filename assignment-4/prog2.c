/*Write a Menu driven C program to accomplish the following functionalities in circular
doubly linked list.
a) Create a circular doubly linked list.
b) Display the elements of a circular doubly linked list.
c) Insert a node at the beginning of a circular doubly linked list.
d) Insert a node at the end of a circular doubly linked list.
e) Delete a node from the beginning of a circular doubly linked list.
f) Delete a node from the end of a circular doubly linked list.
g) Delete a node after a given node of a circular doubly linked list.
h) Delete the entire circular doubly linked list.*/
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a circular doubly linked list node
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = newNode; // Circular reference
    return newNode;
}

// Function to create a circular doubly linked list
struct Node* createCircularDoublyLinkedList(int data) {
    return createNode(data);
}

// Function to display the elements of the circular doubly linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Circular Doubly Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* last = (*head)->prev;
    newNode->next = *head;
    newNode->prev = last;
    last->next = newNode;
    (*head)->prev = newNode;
    *head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* last = (*head)->prev;
    newNode->next = *head;
    newNode->prev = last;
    last->next = newNode;
    (*head)->prev = newNode;
}

// Function to delete a node from the beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* last = (*head)->prev;
    struct Node* temp = *head;

    if (*head == last) { // Only one node in the list
        free(temp);
        *head = NULL;
    } else {
        last->next = (*head)->next;
        (*head)->next->prev = last;
        *head = (*head)->next;
        free(temp);
    }
}

// Function to delete a node from the end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* last = (*head)->prev;
    struct Node* temp = last;

    if (*head == last) { // Only one node in the list
        free(temp);
        *head = NULL;
    } else {
        last->prev->next = *head;
        (*head)->prev = last->prev;
        free(temp);
    }
}

// Function to delete a node after a given node
void deleteAfterNode(struct Node* head, int target) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        if (temp->data == target) {
            struct Node* nodeToDelete = temp->next;
            if (nodeToDelete == head) {
                printf("Cannot delete the head node.\n");
                return;
            }
            temp->next = nodeToDelete->next;
            nodeToDelete->next->prev = temp;
            free(nodeToDelete);
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Node with value %d not found.\n", target);
}

// Function to delete the entire circular doubly linked list
void deleteEntireList(struct Node** head) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* nextNode;

    do {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while (temp != *head);

    *head = NULL;
    printf("Entire list deleted.\n");
}

// Menu-driven main function
int main() {
    struct Node* head = NULL;
    int choice, data, target;

    while (1) {
        printf("\n--- Circular Doubly Linked List Menu ---\n");
        printf("1. Create Circular Doubly Linked List\n");
        printf("2. Display\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete After a Node\n");
        printf("8. Delete Entire List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data for the first node: ");
                scanf("%d", &data);
                head = createCircularDoublyLinkedList(data);
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 4:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 5:
                deleteFromBeginning(&head);
                break;
            case 6:
                deleteFromEnd(&head);
                break;
            case 7:
                printf("Enter target node data after which to delete: ");
                scanf("%d", &target);
                deleteAfterNode(head, target);
                break;
            case 8:
                deleteEntireList(&head);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
