import java.util.*;

class num

{
    public static void main(String[] args)
	{
    int n,r,w;
	  Scanner s=new Scanner(System.in);
    System.out.print("Enter a Two Digit Number :");
    n=s.nextInt();
	  r=n%10;
	  w=n/10;
	  if((n>20) || (n==10))
	  {
	  switch(w)
	  {
		case 1:
			System.out.println("ten");
			break;
		case 2:
			System.out.println("twenty");
			break;
		case 3:
			System.out.println("thirty");
			break; 
		case 4:
			System.out.println("forty");
			break;
		case 5:
			System.out.println("fifty");
			break;
		 case 6:
			System.out.println("sixty");
			break;
		case 7:
			System.out.println("seventy");
			break;
		case 8:
			System.out.println("eighty");
			break;
		case 9:
			System.out.println("ninety");
			break;
	  }
		switch(r)
	  {
		case 1:
			System.out.println("one");
			break;
		case 2:
			System.out.println("two");
			break;
		case 3:
			System.out.println("three");
			break; 
		case 4:
			System.out.println("four");
			break;
		case 5:
			System.out.println("five");
			break;
		 case 6:
			System.out.println("six");
			break;
		case 7:
			System.out.println("seven");
			break;
		case 8:
			System.out.println("eight");
			break;
		case 9:
			System.out.println("nine");
			break;
	  }
	  }
	  if((n<=11) && (n<=20))
	  {
		switch(n)
	  {
		case 11:
			System.out.println("eleven");
			break;
		case 12:
			System.out.println("twelve");
			break;
		case 13:
			System.out.println("thirteen");
			break;
		case 14:
			System.out.println("fourteen");
			break; 
		case 15:
			System.out.println("fivteen");
			break;
		case 16:
			System.out.println("sixteen");
			break;
		 case 17:
			System.out.println("seventeen");
			break;
		case 18:
			System.out.println("eighteen");
			break;
		case 19:
			System.out.println("nighteen");
			break;
		case 20:
			System.out.println("twenty");
			break;
	  }
	  }
	}
}