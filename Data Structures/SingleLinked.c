
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertAtBegin(int val) {
    struct Node* newNode = createNode(val);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    printf("Element inserted at the beginning\n");
}

void insertAtEnd(int val){
    struct Node* newNode = createNode(val);
    struct Node* temp = head;
    if(head == NULL){
        newNode=head;
        return;
    }
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    printf("Element inserted at the end\n");
}

void insertAtPos(int pos, int val) {
    if (pos == 0) {
        insertAtBegin(val);
        return;
    }
    struct Node* newNode = createNode(val);
    struct Node* temp = head;
    for (int i = 1; i < pos; i++) {
        if (temp == NULL) {
            printf("Invalid position\n");
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Element inserted at position %d\n", pos);
}

void deleteAtPos(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    if (pos == 0) {
        head = head->next;
        free(temp);
        printf("\nElement is deleted\n");
        return;
    }
    struct Node* prev = NULL;
    for (int i = 0; i < pos; i++) {
        if (temp == NULL) {
            printf("Invalid position\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    printf("\nElement is deleted\n");
}

void traverse() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
    } else {
        while (temp != NULL) {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void search(int val){
    struct Node *temp=head;
    while(temp!=NULL){
        if(temp->data == val){
            printf("ELement Found\n");
            return;
        }
        temp=temp->next;
    }
    printf("Element not Found\n");
}


int main() {
    int choice = 0, val = 0, pos = 0;
    
    while(1) {
        printf("\n-----------MENU------------\n");
        printf("1. Insertion at Beginning\n");
        printf("2. Insertion at End\n");
        printf("3. Insertion at Position\n");
        printf("4. Deletion at Position\n");
        printf("5. Display the Linked List\n");
        printf("6. Search the LinkedList\n");
        printf("----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an element to insert: ");
                scanf("%d", &val);
                insertAtBegin(val);
                break;
            case 2:
                printf("Enter an element to insert: ");
                scanf("%d", &val);
                insertAtEnd(val);
                break;    
            case 3:
                printf("Enter an element to insert: ");
                scanf("%d", &val);
                printf("Enter a position to insert: ");
                scanf("%d", &pos);
                insertAtPos(pos, val);
                break;
            case 4:
                printf("Enter a position to delete: ");
                scanf("%d", &pos);
                deleteAtPos(pos);
                break;
            case 5:
                printf("The Linked List : ");
                traverse();
                break;
            case 6:
                printf("Enter a element to Search: ");
                scanf("%d", &val);
                search(val);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}
