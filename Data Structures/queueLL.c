#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}node;

node* front = NULL;
node* rear = NULL;

node* createQueue(int val){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode; 
};

void enqueue(int val){
    node* newNode = createQueue(val);
    if(newNode == NULL){
        printf("Overflow\n");
        return;
    }
    if(rear==NULL) //adding the first element of the Q
        front = newNode;
    else
        rear->next = newNode;
    rear = newNode;
    printf("\nEnqueued %d",val);
}

int dequeue(){
    if(front==NULL){
        printf("Underflow");
    }

    node* del = front;
    front = front->next;
    if(front==NULL) //when last element in the Q is delete
        rear = NULL;
    int temp = del->data;
    free(del);
    return temp;

}
int peek(){
    if(front==NULL){
        printf("Underflow");
    }
    return front->data;
}

int main(){

    enqueue(5);
    enqueue(7);
    enqueue(8);

    printf("\npeek %d " , peek());

    printf("\nDequeued %d " , dequeue());
    printf("\nDequeued %d " , dequeue());
    printf("\nDequeued %d " , dequeue());

    enqueue(5);
    enqueue(7);

    printf("\nDequeued %d " , dequeue());
    printf("\nDequeued %d " , dequeue());



}
