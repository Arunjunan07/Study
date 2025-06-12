import java.util.*;
class strarr{
	public static void main(String v[])
	{
		String name[]=new String[10];
		Scanner o = new Scanner(System.in);
		System.out.print("enter 5 names:");
		for (int i=0;i<5;i++)
		{
			name[i]=o.next();
			String x=name[i];
			if(x.charAt(0)=='r')
			  System.out.println(x);
		}
	}
}