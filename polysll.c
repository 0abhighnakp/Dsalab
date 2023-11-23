#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int expo;
    struct Node* next;
};

void readpoly(struct Node** poly) {
    int i;
    int cont;
	
	do{
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter coefficient : ");
        scanf("%d", &(newNode->coeff));

        printf("Enter exponent : ");
        scanf("%d", &(newNode->expo));

        newNode->next = NULL;

        if (*poly == NULL) {
            *poly = newNode;
        } else {
            struct Node* current = *poly;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
       printf("\nDo you wanna add more terms?\n Type 1 for yes and 0 for no\n");
       scanf("%d",&cont);
    }while(cont!=0);
}

void display(struct Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    struct Node* current = poly;

    while (current != NULL) {
        printf("%dx^%d", current->coeff, current->expo);
        if (current->next != NULL) {
            printf(" + ");
        }
        current = current->next;
    }

    printf("\n\n");
}

void add(struct Node** result, struct Node* poly1, struct Node* poly2) {
    struct Node* temp;

    while (poly1 != NULL || poly2 != NULL) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->next = NULL;

        if (poly1 != NULL && poly2 != NULL) {
            if (poly1->expo == poly2->expo) {
                temp->coeff = poly1->coeff + poly2->coeff;
                temp->expo = poly1->expo;
                poly1 = poly1->next;
                poly2 = poly2->next;
            } else if (poly1->expo > poly2->expo) {
                temp->coeff = poly1->coeff;
                temp->expo = poly1->expo;
                poly1 = poly1->next;
            } else {
                temp->coeff = poly2->coeff;
                temp->expo = poly2->expo;
                poly2 = poly2->next;
            }
        }
         else if (poly1 != NULL) {
            temp->coeff = poly1->coeff;
            temp->expo = poly1->expo;
            poly1 = poly1->next;
        } 
        else {
            temp->coeff = poly2->coeff;
            temp->expo = poly2->expo;
            poly2 = poly2->next;
        }

        if (*result == NULL) {
            *result = temp;
        } else {
            struct Node* current = *result;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = temp;
        }
    }
}

int main() {
    struct Node* poly1 = NULL;
    printf("Enter the first polynomial:\n");
    readpoly(&poly1);
    display(poly1);

    struct Node* poly2 = NULL;
    printf("Enter the second polynomial:\n");
    readpoly(&poly2);
    display(poly2);

    struct Node* result = NULL;
    add(&result, poly1, poly2);
    printf("Result:\n");
    display(result);

    
    return 0;
}
