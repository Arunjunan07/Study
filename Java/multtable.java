import java.util.*;
public class multtable {

    public static void main(String[] args) {

        int num; 
		Scanner p=new Scanner(System.in);
		System.out.print("enter a number:");
		num=p.nextInt();
        for(int i = 1;i<10; i++)
        {
            System.out.println(num +" * "+ i+" = "+num*i);
			
        }
    }
}
