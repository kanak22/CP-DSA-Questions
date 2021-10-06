import java.util.*;
import java.lang.*;
import java.io.*;
class hacker
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    Scanner sk=new Scanner(System.in);
	    int n=sk.nextInt();
	    int m=sk.nextInt();
	    int mini=0;
	    int maxi=0;
      int rem=n%m;
      int s=n/m;

      maxi=((n-m+1)*(n-m))/2;
      mini=s*(m*s-m+rem+rem);
      System.out.print(mini/2+" "+maxi);
	}
}
