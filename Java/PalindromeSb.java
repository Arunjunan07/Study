public class PalindromeSb
{
   public static void main(String[] args)
   {
      String strInput = "nayana";
      StringBuffer sb = new StringBuffer(strInput);
      sb.reverse();
      String str = sb.toString();
      if(strInput.equals(str))
      {
         System.out.println(str + " string is palindrome.");
      }
      else
      {
         System.out.println(str + " string is not palindrome.");
      }
   }
}