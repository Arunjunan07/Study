#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

void traverse(struct node *head)
{
  struct node *temp = head;
  while(temp!=NULL){
    printf("%d   ",temp->data);
    temp=temp->next;
    }
}    
struct node* createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int main()
{
  struct node *head=createNode(10);
  struct node *node1=createNode(20);
  struct node *node2=createNode(30);
  head->next=node1;	
  node1->next=node2;
  traverse(head);
  
  printf("\n");
  return 0;
}
