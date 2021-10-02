/*

In this problem, we have to check how many kangaroos can go in another's kangaroo
pocket. 

Because of the constraints given we can sort and divide the kangaroos into two groups
and we can safely assume that first half of the kangaroos do not hold other kangaroos.

Now all we have to check is that how many kangaroos in the second half can hold kangaroos 
in the first half and subtract it from total no of kangaroos.


*/

import java.util.*;
public class Kangaroos {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int t = sc.nextInt();			// No. of kangaroos	
        int [] arr= new int [t];			
        for (int i = 0; i < arr.length; i++) {
            arr[i]=sc.nextInt();			// Size of Kangaroos
        } 
        Arrays.sort(arr);				// Sorting kangaroos by size in ascending order
        int sp=t/2;				// Splitting kangaroos in two sets
        int ans=t;				// Initially all kangaroos are visible

        for (int i = 0; i < arr.length/2; i++) {
            for(;;){
            if (2*arr[i]<=arr[sp]) {			// Checking if the current kangaroo can fit into kangaroo from second half
                sp++;
                ans--;				// No of Visible kangaroos gets decreased by one.
                break;
            }
            
            else
            sp++;
            
            if(sp==arr.length)
            {
                break;
            }
        }
        if(sp==arr.length)
            {
                break;
            }
        }
        System.out.println(ans);			// Priniting Visible kangaroos
    }
}



/*

For more detailed explaination refer: http://codeforces.com/blog/entry/9944.

*/