import java.util.*;
class Queue{
	int size=10;
	int Q[]=new int[size];
	int front,rear;
	Queue(){
		front=-1;
		rear=-1;
	}
	void enqueue(int item){
	if((front==0)&&(rear==size-1))
		System.out.println("Queue is Full");
	else{
		if(front==-1){
			front=0;
	}
	rear++;
	Q[rear]=item;
	System.out.println("An item is inserted on the Queue");
	}
	}
	void dequeue(){
		int element;
		if((front==-1)&&(rear==-1))
			System.out.println("Queue is Empty");
		else{
			element=Q[front];
			if(front>=rear){
				front=-1;
				rear=-1;
			}
			else{
				front++;
			}
			System.out.println(element+" is deleted");
		}
	}
	void display(){
		if(front==-1)
			System.out.println("Queue is Empty");
		else{
			System.out.println("\n Front Index ->"+front);
			System.out.println("Items ->");
			for (int i=front;i<=rear;i++)
				System.out.print("    "+Q[i]+"\n");
		}
	}
}
class queueop{
	public static void main(String arg[]){
		int item=0,choice,i=0;
		Scanner o=new Scanner(System.in);
		Queue q1=new Queue();
		do{
		System.out.println("\n-----------MENU------------");
		System.out.println("1.ENQUEUE operation");
		System.out.println("2.DEQUEUE operation");
		System.out.println("3.DISPLAY the Status of the Queue");
		System.out.println("----------------------------");
		System.out.println("enter your Choice:");
		choice=o.nextInt();
		switch(choice)
		{
			case 1:
				System.out.println("Enter a element to insert:");
				item=o.nextInt();
				q1.enqueue(item);
				break;
			case 2:
				q1.dequeue();
				break;
			case 3:		
				q1.display();
				break;
			default:
		}	
	} while(choice<5);
}
}