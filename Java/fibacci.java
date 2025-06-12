import java.util.*;
class fibacci
{
    public static void main(String[] args) {

        int count, num1 = 0, num2 = 1;
		Scanner q=new Scanner(System.in);
		System.out.println("Enter a number:");
		count=q.nextInt();
        System.out.print("Fibonacci Series of "+count+" numbers:");

        for (int i = 1; i <= count; i++)
        {
            System.out.print(num1+" ");
            int sum = num1 + num2;
			if(sum%2!=0)
			{	
            num1 = num2;
            num2 = sum;
			}
        }
    }
}