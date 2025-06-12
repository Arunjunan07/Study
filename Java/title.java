import java.util.*;
class title{
	public static void main(String v[])
	{
		String name;
		Scanner o = new Scanner(System.in);
		System.out.print("enter your title:");
		name=o.next();
		char S=name.charAt(0);
		String S1=S+"";
		String n2=S1.toUpperCase();
		String X=name.replaceFirst(S1,n2);
		System.out.println("output :"+X);
	}
}