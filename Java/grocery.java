import java.util.Scanner;
class abc
{
	int itemno;
	String itemname;
	int quantity;
	float price;
	
	void ipp()
	{
		Scanner o=new Scanner(System.in);
		System.out.println("Enter itemno,itemname,quantity,price....");
		itemno=o.nextInt();
		itemname=o.next();
		quantity=o.nextInt();
		price=o.nextFloat();
	}
    void opp()
    {
		System.out.println("item no="+itemno+"\n"+"item name="+itemname+"\n"+"quantity="+"\n"+"price=");
	}
}


class qwerty
{
   public static void main(String s[])
   {
      abc item =new abc();
      item.ipp();
      item.opp();
   }
}
   