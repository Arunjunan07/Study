import java.util.*;
class factorial
{
    public static void main(String w[])
	{
		int n,i;
		int fact=1;
		Scanner p=new Scanner(System.in);
		System.out.print("enter a number:");
		n=p.nextInt();
		for(i=1;i<=n;i++)
		{
			fact=fact*i;
		}
		System.out.println("the factorial of "+n+" is "+fact);
	}
}	