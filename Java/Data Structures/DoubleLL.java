import java.util.*;
class DLL {
	class Node{
		 int data;
		 Node prev;
		 Node next;
		 Node(int val) {
			data = val;
			
		}
	}
	Node head = null;  
	Node tail = null;
	public void addDLL(int data) {
		Node newNode = new Node(data);
		if(head == null) {
			head = newNode;  
            tail = newNode; 
			head.prev = null;
			tail.next = null;
		}
		else {
			tail.next = newNode;
			newNode.prev = tail;
			tail = newNode;
			tail.next = null;
		}
	}
	public void delAtBegin() 
	{
		if(head == null) {
			System.out.println("Doubly Linked List is empty");
			return;
		}
		else 
		{
			if(head != tail)
			{
				head = head.next;
			}
			else 
			{
				head = tail = null;
			}
		}
		System.out.println("\n element is deleted");	
	}
	public void display() {
		Node temp = head;
		if(head == null) {
			System.out.println("Doubly Linked List is empty");
			return;
		}
		System.out.println("\n Nodes in Doubly Linked List: ");
		while(temp != null) {
			System.out.print(temp.data + " ");
			temp = temp.next;
		}
	}
	public void search(int ele) {  
        int i = 0;  
        boolean flag = false;  
        Node temp = head;  
        if(head == null) {  
            System.out.println("List is empty");  
            return;  
        }  
        while(temp != null) {  
            if(temp.data == ele) {  
                flag = true;  
                break;  
            }  
            temp = temp.next;  
            i++;  
        }  
        if(flag)  
             System.out.println("Node is present in the list at the position : " + i);  
        else  
             System.out.println("Node is not present in the list");  
    }  
}
class DoubleLL {
public static void main(String[] args) 
	{
		int choice=0;
		Scanner o=new Scanner(System.in);
		DLL dList = new DLL();
		do{
			System.out.println("\n-----------MENU------------");
			System.out.println("1.Insertion at End");
			System.out.println("2.Deletion at Beginning");
			System.out.println("3.DISPLAY the Linked List");
			System.out.println("4.Searching an Element");
			System.out.println("----------------------------");
			System.out.println("enter your Choice:");
			choice=o.nextInt();
			switch(choice)
			{
			case 1:
				System.out.print("Enter a element to insert:");
				int val=o.nextInt();
				dList.addDLL(val);
				break;
			case 2:
				dList.delAtBegin();
				break;
			case 3:		
				dList.display();
				break;
			case 4:
				System.out.print("Enter a element to search:");
				int ele=o.nextInt();
				dList.search(ele);
				break;
			}
		} while(choice<5);
	}
}