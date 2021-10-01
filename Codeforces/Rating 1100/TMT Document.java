import java.util.*;
public class TMT {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n= sc.nextInt();
            String s=sc.next();
            int [] a= new int[(2*n)/3];
            int [] b= new int [n/3];
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
            if(2*nm!=nt||s.charAt(0)=='M'||s.charAt(n-1)=='M')
            {
                System.out.println("NO");
            }
            else
            {
                int x=0;
                int y=nt-1;
                boolean cond=true;
                for (int i = 0; i <b.length; i++) {
                    if(b[i]>a[x] && x<=nt/2)
                    {
                        x++;
                    }
                    else
                    {
                        cond=false;

                    }
                    if(b[b.length-i-1]<a[y] )
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
