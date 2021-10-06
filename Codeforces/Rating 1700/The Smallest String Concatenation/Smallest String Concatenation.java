// Problem Link: https://codeforces.com/contest/632/problem/C
import java.util.*;
import java.io.*;

public class CF632C {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

  public static void main(String[] args) throws IOException {
    int n = Integer.parseInt(br.readLine());
    String[] arr = new String[n];

    int maxLength = 0;

    for (int i = 0; i < n; i++) {
      arr[i] = br.readLine();
    }

    // The essence of our algorithm uses a comparator that is based on the order of two strings added together.
    // That is, we put string o1 before o2 in the final string IF (o1+o2) is smaller in natural String order than (o2+o1).
    Arrays.sort(arr, new Comparator<String>() {
      public int compare(String o1, String o2) {
        return (o1 + o2).compareTo(o2 + o1);
      }
    });

    // We then join the sorted array into a final string
    System.out.println(String.join("", arr));
  }
}