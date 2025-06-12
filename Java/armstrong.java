import java.util.*;
class armstrong
{
    public static void main(String w[])
	{
		int n;
		int s=0;
		Scanner p=new Scanner(System.in);
		System.out.print("enter a number:");
		n=p.nextInt();
		int n1=n;
		while(n>0)
		{
			int t=n%10;
			s+=(t*t*t);
			n=n/10;
		}
		if(n1==s)
			System.out.println("it is Armstrong Number");
		else
			System.out.println("it is not Armstrong Number");
	}
}
	