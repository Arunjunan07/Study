import java.util.*;
class count{
	public static void main(String v[])
	{
		int con=1;
		String S;
		Scanner o = new Scanner(System.in);
		System.out.print("enter your title:");
		S=o.nextLine();
		for (int i=0;i<S.length();i++)
		{
			char c = S.charAt(i);
			if(c==' ')
				con++;
		}
		System.out.println("output :"+con);
	}
}		