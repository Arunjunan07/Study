import java.util.*;
class CircularLinkedList{
	Node last;
	
	class Node{
		int data;
		Node next;
		Node(int val){
			data = val;
			next = null;
		}
	}
	CircularLinkedList(){
		last = null;
	}
	
	public void insertAtBegin(int val){
		Node newNode = new Node(val);
		if(last==null) {
			newNode.next = newNode;
			last = newNode;
		}
		else {
			newNode.next = last.next;
			last.next = newNode;
		}
	
	}
	
	public void insertAtEnd(int val){
		Node newNode = new Node(val);
		if(last==null) {
			newNode.next = newNode;
			last = newNode;
		}
		else {
			newNode.next = last.next;
			last.next = newNode;
			last=newNode;
		}
	
	}
	
	public void display() {
		if(last==null)
			return;
		Node temp = last.next;
		do{
			System.out.print(temp.data + " ");
			temp = temp.next;
		}while(temp!=last.next);
		
		
	}
	
	public int deleteAtBegin() {
		if(last==null) 
			System.out.println("Deletion attempted on empty list ");
		int temp = last.next.data;
		if(last.next==last)
			last = null;
		else
			last.next = last.next.next;
		
		return temp;
		
	}
	
	public void deleteAtEnd() {
		if(last==null) 
			System.out.println("Deletion attempted on empty list ");
		if(last.next==last)
			last = null;
		else {
			Node temp = last.next;
			while(temp.next!=last) {
				temp = temp.next;
			}
			temp.next = last.next;
			last = temp;
		}
			
	}
}
class circular {
public static void main(String[] args) 
	{
		int choice=0;
		int val;
		Scanner o=new Scanner(System.in);
		CircularLinkedList clist = new CircularLinkedList();
		do{
			System.out.println("\n-----------MENU------------");
			System.out.println("1.Insertion at Begin");
			System.out.println("2.Insertion at End");
			System.out.println("3.DISPLAY the Linked List");
			System.out.println("4.Delete At Begin");
			System.out.println("5.Delete at End");
			System.out.println("----------------------------");
			System.out.println("enter your Choice:");
			choice=o.nextInt();
			switch(choice)
			{
			case 1:
				System.out.print("Enter a element to insert:");
				val=o.nextInt();
				clist.insertAtBegin(val);
				break;
			case 2:		
				System.out.print("Enter a element to insert:");
				val=o.nextInt();
				clist.insertAtEnd(val);
				break;
			case 3:
				clist.display();
				break;
			case 4:
				clist.deleteAtBegin();
				break;
			case 5:
				clist.deleteAtEnd();
				break;
			}
		} while(choice<10);
	}
}