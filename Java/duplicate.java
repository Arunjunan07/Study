import java.util.*;
class duplicate{
	public static void main(String v[])
	{
		String s;
		Scanner o = new Scanner(System.in);
		StringBuffer sb=new StringBuffer();
		System.out.print("enter your String:");
		s=o.next();
		for (int i=0;i<s.length();i++)
		{
			char c=s.charAt(i);
			for (int j=0;j<=i;j++)
			{
				sb.append(c);
			}
			sb.append("\n");
		}
		System.out.println("Duplicated String :\n"+sb);
	}
}
