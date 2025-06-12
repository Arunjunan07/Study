import java.util.*;
class insert{
	public static void main (String s[])
	{
		Scanner o=new Scanner(System.in);
		int[] arr;
		System.out.print("Enter the value of n:");
		int n=o.nextInt();
		arr = new int[n];
		System.out.print("Enter the Array Elements:");
		for(int i=0;i<n;i++)
			arr[i]=o.nextInt();
		System.out.println("The Array Elements are:");
		for(int j=0;j<n;j++)
			System.out.print(arr[j]+"\t");
		int newArr[] = new int[n+1]; 
		int len=newArr.length;
		System.out.println("\n"+"Enter a postition value:");
		int index=o.nextInt();
		System.out.print("Enter a value to be inserted:");
		int value=o.nextInt();
		int j = 0;   
        for(int i = 0; i<len; i++) {  
		if(i==index) {  
			newArr[i] = value;  
		}
		else { 
			newArr[i] = arr[j];  
			j++;  
			} 
		}
		System.out.println("Array after adding value: ");
		for (int k=0;k<len;k++)
			System.out.print(newArr[k]+"\t");  
	
	}
}