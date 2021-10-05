// Problem Link: https://codeforces.com/contest/701/problem/C
import java.util.*;
import java.io.*;

public class CF701C {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static String s;

  public static void main(String[] args) throws IOException {
    int n = Integer.parseInt(br.readLine());
    s = br.readLine();
    TreeMap<String, Integer> origMap = new TreeMap<String, Integer>();

    // We use a TreeMap to store the number of occurrences of each Pokemon type
    for (int i = 0; i < n; i++) {
      String curr = s.substring(i, i + 1);
      if (origMap.containsKey(curr)) {
        int count = origMap.get(curr);
        origMap.put(curr, count + 1);
      } else {
        origMap.put(curr, 1);
      }
    }

    // We use two-pointer method; one pointer for the Left pointer and another for the Right
    int L = 0;
    int R = 0;

    int ans = Integer.MAX_VALUE;

    // Our method is going through the possible ranges of L and R where we're able to catch all Pokemon types,
    // and taking the range length (R - L + 1). We then take the minimum among all the valid range lengths.

    // We use a new TreeMap to store the number of occurrences as we go through the String
    TreeMap<String, Integer> map = new TreeMap<String, Integer>();
    // We have a flag for which direction Sergei B. is going
    boolean isGoingRight = true;

    while (R < n && L < n) {
      // We move the R pointer first
      if (isGoingRight) {
        String curr = s.substring(R, R + 1);
        if (map.containsKey(curr)) {
          int count = map.get(curr);
          map.put(curr, count + 1);
        } else {
          map.put(curr, 1);
        }

        // Once we finish the R pointer (we catch all types), we then go to the L pointer
        if (map.size() == origMap.size()) {
          ans = Math.min(ans, R - L + 1);
          isGoingRight = false;
        } else {
          R++;
        }
      } else {
        // The difference with moving the L pointer is that we have to "exclude" the letter which
        // the L pointer "exited" from
        String curr = s.substring(L, L + 1);
        int count = map.get(curr);
        if (count > 1) {
          map.put(curr, count - 1);
        } else {
          ans = Math.min(ans, R - L + 1);
          map.remove(curr);
          isGoingRight = true;
          R++;
        }
        L++;
      }
    }

    System.out.println(ans);
  }

}