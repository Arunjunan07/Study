/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/

import java.util.*;
class abc
{
  int itemno,i=0,j=0;
  String itemname;
  float price;
  int quantity;
  float billamt;
  static float total;
  
void ipp()
{
    Scanner f=new Scanner(System.in);
    System.out.print("ENTER ITEM NUMBER : ");
    itemno=f.nextInt();
    System.out.print("ENTER ITEM NAME : ");	
    itemname=f.next();
	System.out.print("ENTER PRICE : ");
    price=f.nextFloat();
	System.out.print("ENTER QUANTITY : ");
    quantity=f.nextInt();
	billamt=price*quantity;
	total+=billamt;
    
}
void print()
{
  System.out.println("\nITEM NUM :"+itemno+"\n"+"ITEM NAME :"+itemname+"\n"+"PRICE :"+price+"\n"+"QUANTITY :"+quantity+"\n"+"BILL_AMOUNT :"+billamt);
}

void jk()
{	
	System.out.println("\n"+"TOTAL:"+total+"\n");
	if ((total>1000) && (total<3000))
	{	
		System.out.println("you won RS.100 discount");
		i++;
	}
	if(total>5000){
		System.out.println("you won RS.500 discount");
		j++;
	    
	}
	else
	{	
		System.out.println("no coupon.. you've to purchase more than RS.1000");
	}		
}
void ahd()
{	
    if (i==1){
		total=total-100;
		System.out.print("FINAL PRICE :"+total);
    }
	if (j==1){
		total=total-500;
		System.out.print("FINAL PRICE :"+total);
	}
}	
		
}
class supermarket
{
  public static void main(String gy[])
  {
     
     abc a1=new abc();
	 abc a2=new abc();
	 abc a3=new abc();
	 System.out.println("ITEM 1");
     a1.ipp();
	 System.out.println("ITEM 2");
	 a2.ipp();
	 System.out.println("ITEM 3");
	 a3.ipp();
	 a1.print();
	 a2.print();
	 a3.print();
	 a3.jk();
	 a3.ahd();
  }
}