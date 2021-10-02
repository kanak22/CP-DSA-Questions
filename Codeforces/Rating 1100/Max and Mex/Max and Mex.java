/* 

Since in this problem we have to count distinct elements present in the Set S after 
k operations, we can simplify it by using HashSet.

First We will add all elements in the set and according to the value of k we have to
calculate the solution.

If k is 0 then that means we have to do 0 operations therefore we have to print distinct
elements in the given array.

Now if the value of k is positive then we have to check if there all elements are present
between 0 and max , if present then we will have to print max+k+1 as mex will become 
max+1 k times.

If not then we have to add (max+mex)/2 in the set and print it's size.
{Since max would always be greater than mex , therefore ceil((max+mex)/2)
would always be greater than mex, therefore mex wouldn't get added even after
k operations.}




*/



import java.util.*;
import java.io.*;
public class MaxAndMex {
    public static void main(String[] args) throws Exception{
        FastScanner sc= new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int t=sc.nextInt();
        while(t-->0){					//Loop for Test cases
            long n=sc.nextLong();				//No. of elements in Set
            long k=sc.nextLong();				//Opeartions that can be Done
            HashSet <Long> set =new HashSet<>();		
            long max =0;					
            for (int i = 0; i <n; i++) {
                long x=sc.nextLong();
                if (!set.contains(x)) {
                set.add(x);}				//Adding elements in set
                max=Math.max(x, max);			//Finding out Max element in the given set
            }
                
            
            if(k==0)					//If no of operations is zero then print the size of set
            {
                out.println(set.size());
                continue;
            }
            if(!set.contains((long)0))
            {
                set.add((long)(max+1)/2);
                k--;
            }
             long mex=max+1;
             for (long i = 0;i<max; i++) {
                 if(!set.contains(i))
                 {
                     mex=i;
                     break;
                 }
             }
             if (mex+1==max) {				
                 out.println(set.size());
                 continue;
             }
             if(mex>max)				// If mex>max (OR max+1==mex) then print the elements present in the set +k
             {
                 out.println(set.size()+k);
             }
             else
             {
                 set.add((mex+max+1)/2);
                 out.println(set.size());			// else mex < max print size of set by adding one element
             }
            
        


        }
        out.close();
    
    }

    // Class used for Fast I/O

    static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try { 
                                        st=new StringTokenizer(br.readLine());				               
                                } catch (IOException e) {}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}
}


/*

For more information kindly refer to : https://codeforces.com/blog/entry/88533

*/