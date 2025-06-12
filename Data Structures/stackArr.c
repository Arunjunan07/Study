#include<stdio.h>

#define max 10

int arr[max];
int top = -1;

void push(int val){
  if(top == max-1)
    printf("Stack is Full");
  arr[++top] = val;
}

int pop(){
  if(top == -1)
    printf("Stack is Empty");
  return arr[top--];
}

int peek(){
  if(top == -1)
    printf("Stack is Empty");
  return arr[top];  
}
int main()
{
  printf(" %d ",peek());
  printf(" %d ",pop());
  push(6);
  push(5);
  push(10);
  printf("%d ",pop());
  printf("%d ",peek());
  return 0;
}
