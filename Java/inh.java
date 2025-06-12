import java.util.*;

class stu
{
    int rno;
    String na;
    int credit;

    Scanner o=new Scanner(System.in);
    
    void ip()
    {
       System.out.println("give rno na");
       rno=o.nextInt();
       na=o.next();
       
    }
}


class stuart extends stu
{
    int onjob;
    
    void ipa()
    {
       System.out.println("give No of days went for onthe job training...");
       onjob=o.nextInt();
       
       if(onjob==0)
          credit=0;
       if (  (onjob>10)&& (onjob<=15) )
            credit=2;
       if (onjob>15)
            credit=4;
             
       
    }
    
    void opa()
    {
        System.out.println("Credit of Arts students:"+rno+na+credit);
    }
    
}


class stusci extends stu
{
    int onli;
    
    void ips()
    {
       System.out.println("give period -weeks of online course...");
       onli=o.nextInt();
       
       if(onli==0)
          credit=0;
       if (onli==4)
            credit=2;
       if (onli==8)
            credit=4;
             
       
    }
    
    void ops()
    {
        System.out.println("Credit of Science students:"+rno+na+credit);
    }
    
}


public class  inh {
    public static void main(String args[]) {
      
      stuart s1=new stuart();
      s1.ip();
      s1.ipa();
      
      
      stusci s2=new stusci();
      s2.ip();
      s2.ips();
      
      s1.opa();
      s2.ops();
      

      
    }
}
