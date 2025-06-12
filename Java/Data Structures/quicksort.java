import java.util.*;
class quicksort{
  public void quickSort(int[] arr,int low,int high)
  {
    if (low>=high)
        return;
    int start = low;
    int end=high;
    int mid=(start+end)/2;
    int pivot = arr[mid];
    while(start <= end){
      while(arr[start]<pivot)
          start++;
      while(arr[end]>pivot)
          end--;
    if(start<= end) {
      int temp= arr[start];
      arr[start]=arr[end];
      arr[end]= temp;
      start++;
      end--;
    }
    }
    quickSort(arr,low,end);
    quickSort(arr,start,high);
  }
  public static void main(String k[])
  {
    quicksort s= new quicksort();
    int[] a={5,8,4,3,7,6,2,9,5};
    s.quickSort(a,0,a.length-1);
    System.out.println(Arrays.toString(a));
  }
}