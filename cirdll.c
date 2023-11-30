#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertNode(struct Node** head, int data, int pos) {
    struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;

    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
        return;
    }

    if (pos == 1) { 
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        int currentpos = 0;
        while (temp != NULL && currentpos <pos) {
            temp = temp->next;
            currentpos++;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

void deleteNode(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if ((*head)->next == *head) { 
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* temp = *head;
    int currentpos = 1;
    while (temp != NULL && currentpos < pos) {
        temp = temp->next;
        currentpos++;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    if (temp == *head) {
        *head = temp->next;
    }

    free(temp);
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    int op, x, position;
    do {
        printf("\nMENU\n");
        printf("1.Insert at any position\n2.Delete at any position\n3.Display\n4.Exit\n");

        printf("Enter choice: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter node data: ");
                scanf("%d", &x);
                printf("Enter node position: ");
                scanf("%d", &position);
                insertNode(&head, x, position);
                break;
            case 2:
                printf("Enter node position: ");
                scanf("%d", &position);
                deleteNode(&head, position);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (op != 4);

    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

