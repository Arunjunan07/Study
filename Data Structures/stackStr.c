#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stack{
    int data;
    char name[60];
    struct Stack* next;
};

typedef struct Stack node;
node* top = NULL;    

void push(int val,char name[]){
    node* newNode=(node*)malloc(sizeof(node));
    if(newNode==NULL){
        printf("Stack is Full");
        return;
    }
    newNode->data = val;
    strcpy(newNode->name,name);
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
    printf("Name : %s\n" ,del->name);
    free(del);
    return temp; 
    }
}

int peek(){
    if(top==NULL){
        printf("stack is Empty\n");
    }else{
    printf("Name : %s\n" ,top->name);
    return top->data;
    }
}

int main(){
     int choice,val;
     char name[50];
     while(1){
     	printf("\n1.Push\n2.Pop\n3.Peek\n");
     	printf("Enter a choice :");
     	
     	scanf("%d",&choice);
     	switch(choice){
     	  case 1:
     	  	printf("Enter the Value : ");
     	  	scanf("%d",&val);
     	  	printf("Enter the Name : ");
     	  	scanf("%s",name);
     	  	push(val,name);
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

