#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
   int class;
   char name[50];
   struct node *next;
 };
 
struct node *head = NULL;
struct node *headP = NULL;
struct node *headM = NULL;
struct node *headH = NULL;
struct node *headHS = NULL;

 struct node* createNode(int val,char name[]) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->class = val;
    strcpy(newNode->name,name);
    newNode->next = NULL;
}

void insert(struct node **head,int val,char name[]) {
    struct node *newNode = createNode(val,name);
    if(head == NULL){
       *head=newNode;
    }else{
    	newNode->next=*head;
    	*head=newNode;
    }
}

void traverse(struct node **head) {
    struct node *temp = *head;
    while(temp!=NULL){
    	printf("class : %d \t name : %s \n",temp->class,temp->name);
    	temp=temp->next;
    }
}
void split() {
    struct node *temp = head;
    while(temp!=NULL){
    	if(temp->class >= 1 && temp->class <=5){
    	     insert(&headP,temp->class,temp->name);
    	}
    	else if(temp->class >= 6 && temp->class <=8){
    	     insert(&headM,temp->class,temp->name);
    	}
    	else if(temp->class >= 9 && temp->class <=10){
    	     insert(&headH,temp->class,temp->name);
        }
        else if(temp->class >= 11 && temp->class <=12){
    	     insert(&headHS,temp->class,temp->name);
        }
        temp=temp->next;
        
    }
}

void result() {
    printf("Primary Teachers\n");
    traverse(&headP);
    printf("Middle Teachers\n");
    traverse(&headM);
    printf("Higher Teachers\n");
    traverse(&headH);
    printf("Higher Sec. Teachers\n");
    traverse(&headHS);
}
 	
int main()
{
     int class;
     char name[50];
     int choice;
     while(1){
     	printf("1.insert\n2.display\n3.Split\n4.Result\n5.Exit\n");
     	printf("Enter a choice :");
     	
     	scanf("%d",&choice);
     	switch(choice){
     	  case 1:
     	  	printf("Enter the class : ");
     	  	scanf("%d",&class);
     	  	printf("Enter teacher's name :");
     	  	scanf("%s",name);
     	  	insert(&head,class,name);
     	  	break;
     	  
     	  case 2:
     	  	traverse(&head);
     	  	break;
     	  case 3:
     	  	split();
     	  	break;	
     	  case 4:
     	  	result();
     	  	break;
     	  case 5:
     	  	exit(0);
     	  	break;	
       }
   }
}
     
     
     
     
     
     
     
     
     
           
