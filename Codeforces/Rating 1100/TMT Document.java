/*
We have to check weather we can make TMT in a given String by using partiton.
For this we can store the location of T's and M's in the array and check if we 
have T behind and forward for each M.
*/


import java.util.*;
public class TMT {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {                      // For TestCases
            int n= sc.nextInt();
            String s=sc.next();
            int [] a= new int[(2*n)/3];      // Array for storing Index of T's
            int [] b= new int [n/3];         // Array for storing the index of M's
            int nm=0;
            int nt=0;
            for (int i = 0; i <n; i++) {
                if(s.charAt(i)=='T')
                {
                 if(nt<2*(n/3))
                 {
                    a[nt]=i;                        
                 }   
                 nt++;
                 
                }   
                else
                {
                    if(nm<n/3)
                    {
                        b[nm]=i;
                    }
                 nm++; 
                 
                }
            }
            if(2*nm!=nt||s.charAt(0)=='M'||s.charAt(n-1)=='M')      // Checking if the No of T's are twice of number of M's or if the String starts/ends with M if true print NO
            {
                System.out.println("NO");
            }
            else
            {
                int x=0;
                int y=nt-1;
                boolean cond=true;
                for (int i = 0; i <b.length; i++) {
                    if(b[i]>a[x] && x<=nt/2)       // Checking No of T's Before M (Basically removing T before M) 
                    {
                        x++;                    
                    }
                    else
                    {
                        cond=false;

                    }
                    if(b[b.length-i-1]<a[y] )   // Checking No of T's after M (Basically removing T after M)
                    {
                        y--;
                    }

                    else 
                    {
                        cond=false;
                    }
                    
                }
                if(cond)
                System.out.println("YES");
                else
                System.out.println("NO");
            }
            

        }
    }
}

/*

For More Detailed Explaination :https://codeforces.com/blog/entry/89644

*/
