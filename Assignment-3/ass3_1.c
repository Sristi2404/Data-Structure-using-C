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
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list
struct Node* createLinkedList() {
    struct Node* head = NULL;
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
        } else {
            struct Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    return head;
}

// Function to display the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert at the beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert at the end
void insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Function to insert before a given node
struct Node* insertBeforeNode(struct Node* head, int target, int data) {
    if (head == NULL) return NULL;
    
    if (head->data == target) {
        struct Node* newNode = createNode(data);
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != target) {
        temp = temp->next;
    }

    if (temp->next != NULL) {
        struct Node* newNode = createNode(data);
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        printf("Node not found.\n");
    }
    return head;
}

// Function to insert after a given node
void insertAfterNode(struct Node* head, int target, int data) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp != NULL) {
        struct Node* newNode = createNode(data);
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        printf("Node not found.\n");
    }
}

// Function to delete the first node
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete the last node
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Function to delete after a given node
void deleteAfterNode(struct Node* head, int target) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp != NULL && temp->next != NULL) {
        struct Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        free(nodeToDelete);
    } else {
        printf("Node not found or no node after it.\n");
    }
}

// Function to delete the entire linked list
struct Node* deleteLinkedList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
    printf("Linked list deleted.\n");
    return NULL;
}

// Main function with menu-driven options
int main() {
    struct Node* head = NULL;
    int choice, data, target;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Linked List\n");
        printf("2. Display Linked List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert Before a Node\n");
        printf("6. Insert After a Node\n");
        printf("7. Delete from Beginning\n");
        printf("8. Delete from End\n");
        printf("9. Delete After a Node\n");
        printf("10. Delete Entire List\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = createLinkedList();
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
                insertAtEnd(head, data);
                break;
            case 5:
                printf("Enter the target node value: ");
                scanf("%d", &target);
                printf("Enter data to insert before node %d: ", target);
                scanf("%d", &data);
                head = insertBeforeNode(head, target, data);
                break;
            case 6:
                printf("Enter the target node value: ");
                scanf("%d", &target);
                printf("Enter data to insert after node %d: ", target);
                scanf("%d", &data);
                insertAfterNode(head, target, data);
                break;
            case 7:
                head = deleteFromBeginning(head);
                break;
            case 8:
                head = deleteFromEnd(head);
                break;
            case 9:
                printf("Enter the target node value: ");
                scanf("%d", &target);
                deleteAfterNode(head, target);
                break;
            case 10:
                head = deleteLinkedList(head);
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
