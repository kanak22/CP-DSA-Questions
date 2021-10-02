public class Main {

public static void reverse(int[] arr,int n) {
     for(int i=0; i<n/2; i++){
      int j= arr[i];
      arr[i] = arr[n-i-1];
      arr[n-i-1] = j;
    }

    /*printing the reversed array*/
    System.out.println("Reversed array is: \n");
    for (int k = 0; k < n; k++) {
        System.out.print(arr[k] + " ");
    }
}
public static void main(String[ ] args) {
    int [] arr = {10, 20, 30, 40, 50};
    reverse(arr, arr.length);

}