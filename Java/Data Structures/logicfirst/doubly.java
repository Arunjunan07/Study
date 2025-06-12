import java.util.*;
 class DoublyLinkedList {
	Node head;
	Node tail;
	
	class Node{
		int data;
		Node prev;
		Node next;	
		
		Node(int val){
			data = val;
			next = null;
			prev = null;
		}
	}
	
	DoublyLinkedList(){
		head = null;
		tail = null;
	}
	
	public void insertAtBegin(int val){
		Node newNode = new Node(val);
		newNode.next = head;
		if(head==null) {
			tail = newNode;
		}
		else { 
			head.prev = newNode;	
		}	
		head = newNode;
		
	}
	
	public void display() {
		if(head==null)
			System.out.println("List is empty");
		Node temp = head; //start from head
		while(temp != null) { //null implies end of list
			System.out.print(temp.data + " ");
			temp = temp.next; //jump
		}
		
	}
	
	public void displayRev() {
		if(head==null)
			System.out.println("List is empty");
		Node temp = tail; //start from head
		while(temp != null) { //null implies end of list
			System.out.print(temp.data + " ");
			temp = temp.prev; //jump
		}
		
	}
	
	public void insertAtPos(int pos,int val) {
		if(pos==0)
		{
			insertAtBegin(val);
			return;
		}
		
		Node newNode = new Node(val);
		Node temp = head;
		for(int i=1;i<pos;i++) { //jump to prev node
			temp = temp.next;
			if(temp==null) 
				System.out.println("Invalid Pos " + pos);
		}
		
		//reassign pointers
		newNode.next = temp.next;
		newNode.prev = temp;
		
		if(temp==tail)
			tail=newNode;
		else
			temp.next.prev = newNode;
		temp.next = newNode;
				
	}
	
	public void deleteAtPos(int pos) {
		
		if(head==null) 
			System.out.println("Deletion attempted on empty list ");
	
		if(pos==0) {
			head = head.next;
			if(head==null)
				tail=null;
			else
				head.prev = null;
			return;
		}
		
		Node temp = head;
		Node prev = null;
		
		//jump till node to be deleted
		for(int i=1;i<=pos;i++) {
			prev = temp; //keep track of prev node
			temp = temp.next; //jump to next node
			if(temp==null)
				System.out.println("Invalid position ");
				
		}
		
		prev.next = temp.next; //reassign pointers
		if(temp.next==null)
			tail = prev;
		else
			temp.next.prev = prev;
	}
}
class doubly {
public static void main(String[] args) 
	{
		int choice=0;
		int val,pos;
		Scanner o=new Scanner(System.in);
		DoublyLinkedList dlist = new DoublyLinkedList();
		do{
			System.out.println("\n-----------MENU------------");
			System.out.println("1.Insertion at Begin");
			System.out.println("2.DISPLAY Reverse the Linked List");
			System.out.println("3.DISPLAY the Linked List");
			System.out.println("4.insert At Position Linked List");
			System.out.println("5.Delete at Position the Linked List");
			System.out.println("----------------------------");
			System.out.println("enter your Choice:");
			choice=o.nextInt();
			switch(choice)
			{
			case 1:
				System.out.print("Enter a element to insert:");
				val=o.nextInt();
				dlist.insertAtBegin(val);
				break;
			case 2:
				dlist.displayRev();
				break;
			case 3:		
				dlist.display();
				break;
			case 4:
				System.out.print("Enter a element to insert:");
				val=o.nextInt();
				System.out.print("Enter a position to insert:");
				pos=o.nextInt();
				dlist.insertAtPos(pos,val);
				break;
			case 5:
				System.out.print("Enter a element to insert:");
				val=o.nextInt();
				dlist.deleteAtPos(val);
				break;
			}
		} while(choice<10);
	}
}