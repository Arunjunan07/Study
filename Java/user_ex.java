import java.util.*;
class age_ex extends Exception
{
String t;
age_ex(String t1)
{
	t=t1;
}
public String toString()
{
return(t);
}
}


class user_ex{
  public static void main(String m[])  
  {
	Scanner q = new Scanner(System.in);
	System.out.print("enter age:");
	int age= q.nextInt();
	try{
		if(age<0)
		   throw new age_ex("age is not valid");
		else
		   System.out.println("Age :"+age);
	}
	catch(age_ex e){
		System.out.println("error occured :"+e);
	}
	System.out.print("Program ended");
  }
}

