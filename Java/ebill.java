import java.util.*;
class bill
{
	int code,units;
	double price;
	String cus_name;
	
	void input()
	{
		Scanner f=new Scanner(System.in);
		System.out.print("ENTER CODE: ");
		code=f.nextInt();
		System.out.print("ENTER CUSTOMER NAME : ");
		cus_name=f.next();
		System.out.print("ENTER THE UNITS THAT YOU CONSUMED : ");
		units=f.nextInt();
	}

    void cal()
	{
		double cost=0;
		if(units<=100)
		{
			System.out.print("YOU CONSUME LESS THAN 100.. SO NO NEED TO PAY ");
		}		
        if(units<200)
		{
			if(units<=100 && units<=200)
			{
				cost+=units*1.5;
			}
			cost=price;
			System.out.println("YOUR EB AMOUNT : "+price);
		}
		if(units<500)
		{
			if(units<=100 && units<=200)
			{
				cost+=units*2;
			}
			if(units<=200 && units<=500)
			{
				cost+=units*3;
				
			}
			price=cost;				
			System.out.println("YOUR EB AMOUNT : "+price);	
		}			
		if(units>500)
		{
			if(units<=100 && units<=200)
			{
				cost+=units*3.5;
			}
			if(units<=200 && units<=500)
			{
				cost+=units*4.6;
			}
			else
			{
				cost+=units*6.6;
			}	
			cost=price;	
			System.out.println("YOUR EB AMOUNT : "+price);
		}			
	}
}
	
class ebill
{
  public static void main(String y[])
  {
    bill a=new bill();
	a.input();
	a.cal();
  }
}  
	