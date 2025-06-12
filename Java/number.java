import java.util.*;
class num
{
	static int x;
	Scanner s;
void ip()
{
		s=new Scanner(System.in);
		System.out.print("enter an integer:");
		x=s.nextInt();
}
void jk()
{
	if(x>=0)
		{
			System.out.print("the number is postive");
		}
	else
		{	
			System.out.print("the number is negative");
		}	
}
}
class number
{
	public static void main(String s[])
	{
		num n1 = new num();
		n1.ip();
		n1.jk();	
		
	}
}
	