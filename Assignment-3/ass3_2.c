/*Write a Menu driven C program to accomplish the following functionalities in circular
linked list.
a) Create a circular linked list.
b) Display the elements of a circular linked list.
c) Insert a node at the beginning of a circular linked list.
d) Insert a node at the end of a circular linked list.
e) Delete a node from the beginning of a circular linked list.
f) Delete a node from the end of a circular linked list.
g) Delete a node after a given node of a circular linked list.
h) Delete the entire circular linked list.*/
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = newNode; // Circular link
    return newNode;
}

// Function to create a circular linked list
struct Node* createCircularLinkedList() {
    struct Node* head = NULL;
    struct Node* last = NULL;
    int n, data;

    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);
    if (n <= 0) return head;

    for (int i = 0; i < n; i++) {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        struct Node* newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
            last = head;
        } else {
            last->next = newNode;
            last = newNode;
        }
        last->next = head; // Make it circular
    }

    return head;
}

// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Function to insert at the beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;

    return head;
}

// Function to insert at the end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

    return head;
}

// Function to delete a node from the beginning
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* temp = head;
    if (head->next == head) {
        free(head);
        return NULL;
    }

    while (temp->next != head) {
        temp = temp->next;
    }

    struct Node* toDelete = head;
    temp->next = head->next;
    head = head->next;
    free(toDelete);

    return head;
}

// Function to delete a node from the end
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    if (head->next == head) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }

    struct Node* toDelete = temp->next;
    temp->next = head;
    free(toDelete);

    return head;
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
            struct Node* toDelete = temp->next;
            if (toDelete == head) {
                printf("No node after %d (target is the last node).\n", target);
                return;
            }
            temp->next = toDelete->next;
            free(toDelete);
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Target node not found.\n");
}

// Function to delete the entire circular linked list
struct Node* deleteCircularLinkedList(struct Node* head) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }

    struct Node* temp = head;
    do {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    } while (temp != head);

    printf("Circular linked list deleted.\n");
    return NULL;
}

// Main function with menu-driven options
int main() {
    struct Node* head = NULL;
    int choice, data, target;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Circular Linked List\n");
        printf("2. Display Circular Linked List\n");
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
                head = createCircularLinkedList();
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 4:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 5:
                head = deleteFromBeginning(head);
                break;
            case 6:
                head = deleteFromEnd(head);
                break;
            case 7:
                printf("Enter the target node value: ");
                scanf("%d", &target);
                deleteAfterNode(head, target);
                break;
            case 8:
                head = deleteCircularLinkedList(head);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
