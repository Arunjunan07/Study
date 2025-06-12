import java.util.*;
class inssort{
   void InsertionSort(int arr[])
  {
  for(int i=1;i<arr.length;i++){
    for(int j=i;j>0;j--){
      if(arr[j]<arr[j-1])
      {
        int temp=arr[j];
        arr[j]=arr[j-1];
        arr[j-1]=temp;
      }
      else
        break;
    }
}
}
  public static void main(String m[])
  {
    inssort s = new inssort();
    int[] arr={10,8,7,1,12,5};
    s.InsertionSort(arr);
    System.out.println(Arrays.toString(arr));
}
}