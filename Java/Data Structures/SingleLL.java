import java.util.*;
class SLL{
	Node head;
	
	class Node{
		int data;
		Node next;
		Node(int val){
			data=val;
			next=null;
		}
	}
	Linkedlist(){
		head=null;
	}
	public void InsertAtBegin(int val){
		Node newnode=new Node(val);
		if(head==null)
			head=newnode;
		else{
			newnode.next=head;
			head=newnode;
		}
		System.out.println("Element is inserted at beginning");
	}
	public void display(){
			Node temp=head;
			if(temp==null){
				System.out.println("List is Empty");
			}
			else{
				while(temp!=null){
				System.out.print(temp.data+" ");
				
				
				temp=temp.next;
				} 
			}
		}
	public void InsertAtPos(int pos,int val){
			if(pos==0)
			{
				InsertAtBegin(val);
				return;
			}
			Node Newnode=new Node(val);
			Node temp=head;
			for(int i=1;i<pos;i++)
				temp=temp.next;
			if(temp==null){
					System.out.println("Invalid position");
					return;
			}
			Newnode.next=temp.next;
			temp.next=Newnode;
			System.out.println("Element is inserted at "+pos);
		}
	public void DeleteAtPos(int pos){
		if(head==null){
			System.out.println("List is Empty");
		}
		if (pos==0){
			head=head.next;
			return;
		}
		Node temp=head;
		Node prev=null ;
		for(int i=0;i<pos;i++){
			prev=temp;
			temp=temp.next;
		}
		prev.next=temp.next;
		System.out.println("\nElement is Deleted");
	}
}

class SingleLL{
	public static void main(String s[])
	{
		int val=0,choice=0;
		int pos;
		Scanner o=new Scanner(System.in);
		SLL Slist=new SLL();
		do{
		System.out.println("\n-----------MENU------------");
		System.out.println("1.Insertion at Beginning");
		System.out.println("2.Insertion at Position");
		System.out.println("3.DISPLAY the Linked List");
		System.out.println("4.Deletion at Position");
		System.out.println("----------------------------");
		System.out.println("enter your Choice:");
		choice=o.nextInt();
		switch(choice)
		{
			case 1:
				System.out.print("Enter a element to insert:");
				val=o.nextInt();
				Slist.InsertAtBegin(val);
				break;
			case 2:
				System.out.print("Enter a element to insert:");
				val=o.nextInt();
				System.out.print("Enter a position to insert:");
				pos=o.nextInt();
				Slist.InsertAtPos(val,pos);
				break;
			case 3:		
				System.out.print("the Linked List is ");
				Slist.display();
				break;
			case 4:
				System.out.print("Enter a Position to delete:");
				pos=o.nextInt();
				Slist.DeleteAtPos(pos);
				break;
			default:
		}
	}	while(choice<5);
	}
}
