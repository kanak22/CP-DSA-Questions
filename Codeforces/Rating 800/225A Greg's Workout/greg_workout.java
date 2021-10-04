import java.util.*;
import java.io.*;

public class greg_workout {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int chest = 0;
        int biceps = 0;
        int back = 0;
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            if (i % 3 == 0) {
                chest += x;
            } else if (i % 3 == 1) {
                biceps += x;
            } else {
                back += x;
            }
        }
        int max = (int) Math.max(chest, (int) Math.max(biceps, back));
        if (max == chest) {
            System.out.println("chest");
        } else if (max == biceps) {
            System.out.println("biceps");
        } else {
            System.out.println("back");
        }
    }
}
