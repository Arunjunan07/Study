import java.util.*;
class delete{
	public static void main(String v[])
	{
		String s;
		Scanner o = new Scanner(System.in);
		StringBuffer sb = new StringBuffer();
		System.out.print("enter your string:");
		s=o.nextLine();
		for (int i =0 ;i<s.length();i++)
		{
			char c =s.charAt(i);
			if((c!='a')&&(c!='e')&&(c!='i')&&(c!='o')&&(c!='u'))
				sb.append(c+" ");
		}
	System.out.println("removed String :"+sb);
	}
}