import java.util.*;
class date{
    public static void main(String[] args) {
      int dd,mm,yyyy;
	  int max=0;
        Scanner s=new Scanner(System.in);
        System.out.print("Enter Date :");
        dd=s.nextInt();
        System.out.print("Enter Month :");
        mm=s.nextInt();
        System.out.print("Enter Year :");
        yyyy=s.nextInt();
        if((mm>=1) && (mm<=12))
		{
			if(mm==2)
			{
				if(yyyy%4==0)
					max=29;
				else
					max=28;
			}	
			else if((mm==1) || (mm==3) || (mm==5) || (mm==7) || (mm==8) || (mm==10) || (mm==12))
				max=31;
			else if((mm==4) || (mm==6) || (mm==9) || (mm==11))
				max=30;
			if(dd<=max)
			{
				System.out.println("Valid input");
				System.out.println("\nEntered Date :"+dd+"/"+mm+"/"+yyyy);
            }
			else
				System.out.println("INVALID DAY INPUT");
		}
		else
			System.out.println("Wrong Month Input");
		
	}
}
