#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void PUSH(struct Node **head,int data){
    
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    
    newNode->data=data;
    printf("%d is inserted",data);
    
    if(*head==NULL){
       newNode->next=NULL;
       *head=newNode;
       return;
    }
    newNode->next=*head;
    *head=newNode;
}

void POP(struct Node **head){
    
    if(*head==NULL){
        printf("Stack is empty");
        return;
    }
    printf("%d is removed",(*head)->data);
    struct Node *temp=*head;
    *head=(*head)->next;
    free(temp);
}

void PEEK(struct Node **head){
    if(*head==NULL){
        printf("Stack is empty");
        return;
    }
    printf("Element at the top:%d",(*head)->data);
}

void display(struct Node *node){
    if(node==NULL){
        printf("Stack is empty");
        return;
    }
    printf("Stack:\n");
    while(node!=NULL){
        printf("\n%d ",node->data);
        node=node->next;
    }
}

int main(){
        struct Node *head=NULL;
        int x,op;
        do{
           printf("\nMENU\n");
           printf("1.PUSH\n2.POP\n3.PEEK\n4.display\n5.EXIT\n");
           printf("\nChoose an operation: ");
           scanf("%d",&op);
           
           switch(op){
                case 1:
                   printf("\nEnter element to push: ");
                   scanf("%d",&x);
                   PUSH(&head,x);
                   break;
                case 2:
                   POP(&head);
                   break;
                case 3:
                   PEEK(&head);
                   break;
                case 4:
                   display(head);
                   break;
                case 5:
                   printf("\nEXITED");
                   break;
                default:
                   printf("\nINVALID OPERATION\n");
              }
         }while(op!=5);
         return 0;
}
