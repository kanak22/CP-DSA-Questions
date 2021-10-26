// Java program to print largest contiguous array sum
import java.io.*;
import java.util.*;
 

class KadaneAlgorithm
{
    public static void main (String[] args)
    {
        int [] a = {74,-72,94,-53,-59,-3,-66,36,-13,22,73,15,-52,75};
        System.out.println("Maximum contiguous sum is " +
                                       maxSubArraySum(a));
    }
 
    static int maxSubArraySum(int a[])
    {
        int size = a.length;
        int max = Integer.MIN_VALUE, sum = 0;
 
        for (int i = 0; i < size; i++)
        {
            sum = sum + a[i];
            if (max <sum)
                max = sum;
            if (sum < 0)
                sum = 0;
        }
        return max;
    }
}