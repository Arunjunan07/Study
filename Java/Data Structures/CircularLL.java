import java.util.*;
 class CLL {  
        class Node{  
            int data;  
            Node next;  
            Node(int val) {  
                data = val;  
            }  
        }  
        Node head = null;  
        Node tail = null;   
        public void addCll(int data){  
            Node newNode = new Node(data);  
            if(head == null) {  
                head = newNode;  
                tail = newNode;  
                newNode.next = head;  
            }  
            else {  
                tail.next = newNode;  
                tail = newNode;  
                tail.next = head;  
            }  
        }  
        public void delAtFirst() {
			if (head == null) {
				System.out.println("Doubly Linked List is empty");
				return;
			} 
			else {
				if (head != tail) 
				{
					head = head.next;
					tail.next = head;
				}
				else 
				{
					head = tail = null;
				}
			}
			System.out.println("\n element is deleted");	
		}  
        public void print() {  
            Node temp = head;  
            if(head == null) {  
                System.out.println("List is empty");
				return;
            }  
            else {  
                System.out.println("\n Nodes of the circular linked list: ");  
                 do{  
                    System.out.print(" "+ temp.data);  
                    temp = temp.next;  
                }while(temp != head);  
                System.out.println();  
            }  
        }
		public void search(int ele) {  
        Node temp = head;  
        int i = 0;  
        boolean flag = false;  
        if(head == null) {  
            System.out.println("List is empty");  
        }  
        else {  
             do{    
                if(temp.data == ele) {  
                    flag = true;  
                    break;  
                }  
                temp = temp.next;  
                i++;  
            } while(temp != head);  
             if(flag)  
                 System.out.println("Element is present in the list at the position : " + i);  
            else  
                 System.out.println("Element is not present in the list");  
        }  
    }  
}
class CircularLL
{		
	public static void main(String[] args) 
	{
		int choice=0;	
		Scanner o=new Scanner(System.in);
		CLL clist=new CLL();
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
				clist.addCll(val);
				break;
			case 2:
				clist.delAtFirst();
				break;
			case 3:		
				clist.print();
				break;
			case 4:
				System.out.print("Enter a element to search:");
				int ele=o.nextInt();
				clist.search(ele);
				break;
			}
		} while(choice<5); 
	}
}		