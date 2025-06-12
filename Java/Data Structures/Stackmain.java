import java.util.*;
 class stack1{
	Scanner o=new Scanner(System.in);
	int s[] = new int[10];
	int top;
	stack1(){
		top=-1;
	}
	void push(int item)
	{
		if(top==9)
			System.out.println("Stack is Full");
		else {
			s[++top]=item;
			System.out.println("The Item successfully added into the stack.....");
			}
	}
	void pop()
	{
		if(top>=0)
			System.out.println( s[top--]);
		else
			System.out.println("Stack is Empty");
	}
	void print()
	{
		for (int i=0 ;i<=top;i++)
			System.out.print("    "+s[i]+"\n");
		int free=(10-top-1);
		double freeper=(free/10.0)*100;
		System.out.println("Free Space Percentage:"+freeper);
	}	
}

public class Stackmain {
	public static void main(String arg[])
	{
		int item=0,choice,i=0;
		Scanner o=new Scanner(System.in);
		stack1 s1=new stack1();
		do{
		System.out.println("\n-----------MENU------------");
		System.out.println("1.PUSH operation");
		System.out.println("2.POP operation");
		System.out.println("3.DISPLAY the Status of the Stack");
		System.out.println("----------------------------");
		System.out.println("enter your Choice:");
		choice=o.nextInt();
		switch(choice)
		{
			case 1:
				System.out.println("Enter a element to push:");
				item=o.nextInt();
				s1.push(item);
				break;
			case 2:
				s1.pop();
				break;
			case 3:		
				System.out.println("the Stack is ");
				s1.print();
				break;
			default:
		}
		
	}	while(choice<5);

}
}	