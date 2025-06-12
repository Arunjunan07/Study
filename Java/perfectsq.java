import java.util.*;
class perfectsq
{
	public static void main(String e[])
	{
	double s;
	int a;
	Scanner q=new Scanner(System.in);
	System.out.println("Enter a number:");
	a=q.nextInt();
	s=Math.sqrt(a);
	if(a==s*s)
		System.out.println("it is a perfect square");
	else
		System.out.println("it is not a perfect square");
	}
}
	
	