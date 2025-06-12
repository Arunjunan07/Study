#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
    int data;
    struct Stack* next;
}node;

node* top = NULL;

void push(int val){
    node* newNode=(node*)malloc(sizeof(node));
    if(newNode==NULL){
        printf("Stack is Full");
        return;
    }
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

int pop(){
    if(top==NULL){
        printf("stack is Empty");
    }else{
    node *del = top;
    top = top->next;
    int temp = del->data;
    free(del);
    return temp;
    }
}

int peek(){
    if(top==NULL)
        printf("stack is Empty");
    else
        return (top)->data;
}

int main(){
    int choice,val;
    while(1){
     	printf("\n1.Push\n2.Pop\n3.Peek\n");
     	printf("Enter a choice :");
     	scanf("%d",&choice);
     	
     	switch(choice){
     	  case 1:
     	  	printf("Enter the Value : ");
     	  	scanf("%d",&val);
     	  	push(val);
     	  	break;
     	  
     	  case 2:
     	  	printf("Popped  %d\n",pop());
     	  	break;
     	  case 3:
     	    printf("Top : %d\n",peek());
     	  	break;	
        }
    }
    return 0;
}

