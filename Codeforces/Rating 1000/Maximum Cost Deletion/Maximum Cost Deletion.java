/*
In this problem we have to erase a character(s) from the String so that we can Maximise the cost which is calculated by 
folmula a*l+b.


The value of a*n will always be there irrespective of the nature of a. Therefore we can only optimize this code w.r.t. nature of b.

Suppose the value  b is positive , so we can delete characters one by one such that we can get the maximum score.

If b is negative then we have to delete Smallest subsequence of Zero or One to Maximize our cost.
 
 
 For more Detailed solution refer to editorial : https://codeforces.com/blog/entry/92864   (Problem B)

*/
import java.util.*;
import java.io.*;
public class MaximumCostDeletion{
    public static void main(String[] args) {
        FastReader fr = new FastReader();
        PrintWriter out = new PrintWriter(System.out);
        Scanner sc= new Scanner (System.in);
        
        //Code From Here----
        int t=fr.nextInt();
        while (t-->0) {
            int n=fr.nextInt();                          // Taking the length of String
            int a=fr.nextInt();	             // Taking value of a	
            int b=fr.nextInt();	             // Taking value of b	
            String s=fr.next();	             // Taking String
            if (b>=0) {		             // if b is positive then printing max value i.e. (a+b)*n
                out.println((a+b)*n);

            }
            else
            {
                int O=0;
                int Z=0;
                char prev='2';
                for (int i = 0; i < s.length(); i++) {           // Calculating the no of subsequence of 1's and 0's 
                    if(prev==s.charAt(i)) continue;
                    prev=s.charAt(i);
                    if(s.charAt(i)=='0')
                    Z++;
                    else O++;
                } 
                out.println((a*n)+(b*(Math.min(Z+1,O+1))));  // Calculating ans such that cost gets maximized by taking the smallest no of subsequence 
					  // and multiplying by it.	
            }
        }        




        
        out.flush();
        sc.close();
    }

    //This RadixSort() is for long method

    public static long[] radixSort(long[] f){ return radixSort(f, f.length); }
	public static long[] radixSort(long[] f, int n)
	{
		long[] to = new long[n];
		{
			int[] b = new int[65537];
			for(int i = 0;i < n;i++)b[1+(int)(f[i]&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < n;i++)to[b[(int)(f[i]&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < n;i++)b[1+(int)(f[i]>>>16&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < n;i++)to[b[(int)(f[i]>>>16&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < n;i++)b[1+(int)(f[i]>>>32&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < n;i++)to[b[(int)(f[i]>>>32&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < n;i++)b[1+(int)(f[i]>>>48&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < n;i++)to[b[(int)(f[i]>>>48&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		return f;
	}

	// Fast Radixsort() for int[]  {radixSort2}

	public static int[] radixSort2(int[] a)
	{
		int n = a.length;
		int[] c0 = new int[0x101];
		int[] c1 = new int[0x101];
		int[] c2 = new int[0x101];
		int[] c3 = new int[0x101];
		for(int v : a) {
			c0[(v&0xff)+1]++;
			c1[(v>>>8&0xff)+1]++;
			c2[(v>>>16&0xff)+1]++;
			c3[(v>>>24^0x80)+1]++;
		}
		for(int i = 0;i < 0xff;i++) {
			c0[i+1] += c0[i];
			c1[i+1] += c1[i];
			c2[i+1] += c2[i];
			c3[i+1] += c3[i];
		}
		int[] t = new int[n];
		for(int v : a)t[c0[v&0xff]++] = v;
		for(int v : t)a[c1[v>>>8&0xff]++] = v;
		for(int v : a)t[c2[v>>>16&0xff]++] = v;
		for(int v : t)a[c3[v>>>24^0x80]++] = v;
		return a;
	}


	// For Fast Input  ----
    
    
	static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader()
		{
			br = new BufferedReader(
				new InputStreamReader(System.in));
		}

		String next()
		{
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				}
				catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() { return Integer.parseInt(next()); }

		long nextLong() { return Long.parseLong(next()); }

		double nextDouble()
		{
			return Double.parseDouble(next());
		}

		String nextLine()
		{
			String str = "";
			try {
				str = br.readLine();
			}
			catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}



    
}
