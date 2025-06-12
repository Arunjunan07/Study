#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct {
 int front, rear;
 int ticket[MAX];
} Queue;

int waitlist[MAX];
int Count;

void initializeQueue(Queue* q) {
 q->front = q->rear = -1;
}

int isQueueFull(Queue* q) {
 return (q->rear + 1) % MAX == q->front;
}

int isQueueEmpty(Queue* q) {
 return q->front == -1;
}

void enqueue(Queue* q, int tick) {
 if(isQueueFull(q)){
        printf("Ticket is Full");
        return;
    }
 if(q->front==-1)
        q->front++;
 q->ticket[++(q->rear)] = tick;
}

int dequeue(Queue* q) {
 if (isQueueEmpty(q)) {
  printf("Queue is empty. No ticket to cancel.\n");
  return -1;
 }
 if (q->front == q->rear) {
  q->front = q->rear = -1; // Queue is now empty
 } else
  return q->ticket[(q->front)++];

}

void displayQueue(Queue* q) {
 if (isQueueEmpty(q)) {
  printf("No ticket booked.\n");
  return;
 }
 printf("Booked tickets: ");
 for (int i = q->front; i != q->rear; i++) {
  printf("%d ", q->ticket[i]);
 }
 printf("%d\n", q->ticket[q->rear]);
}

void addToWaitlist(int tick) {
 if (Count < MAX) {
  waitlist[Count++] = tick;
  printf("Added ticket %d to waitlist.\n", tick);
 } else {
  printf("Waitlist is full. Cannot add ticket %d.\n", tick);
 }
}

void cancelticket(Queue* q) {
 int tick = dequeue(q);
 if (tick != -1) {
  printf("Cancelled ticket %d.\n", tick);
  if (Count > 0) {
   int waittick = waitlist[0];
   for (int i = 0; i < Count - 1; i++) {
    waitlist[i] = waitlist[i + 1];
   }
   Count--;
   enqueue(q, waittick);
   printf("Allotted ticket %d from waitlist.\n", waittick);
  }
 }
}

int main() {
 Queue q;
 int choice, tick;

 initializeQueue(&q);
 Count = 0;

 do {
  printf("\n1. Book tickets\n2. Cancel ticket\n3. Display tickets\n4. Exit\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
  case 1:
   printf("Enter ticket number to book: ");
   scanf("%d", &tick);
   if (!isQueueFull(&q)) {
    enqueue(&q, tick);
   } else {
    addToWaitlist(tick);
   }
   break;
  case 2:
   cancelticket(&q);
   break;
  case 3:
   displayQueue(&q);
   break;
  case 4:
   printf("Exiting...\n");
   break;
  default:
   printf("Invalid choice! Please try again.\n");
  }
 } while (choice != 4);

 return 0;
}