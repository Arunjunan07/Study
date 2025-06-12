import java.util.*;
class arraydel
{
	public static void main(String arg[])
	{
		Scanner o =new Scanner(System.in);
		int n,pos;
		System.out.print("Enter the number of Elements:");
		n=o.nextInt();
		int[] a=new int[n];
		System.out.print("Enter the Elements:");
		for(int i=0;i<n;i++)
			a[i]=o.nextInt();
		System.out.print("Enter the position of the number which is to be deleted:");
		pos=o.nextInt();
		for(int i=pos; i<n-1;i++)
		{
			a[i]=a[i+1];
		}
		n=n-1;
		System.out.println("After Deleting an Element");
		System.out.print("The Array is\n");
		for(int i=0;i<n;i++)
			System.out.println("a["+i+"]="+a[i]);
	}
}