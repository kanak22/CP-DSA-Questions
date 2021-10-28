// Java program to print largest contiguous array sum
import java.io.*;
import java.util.*;
 

class KadaneAlgorithm
{
    public static void main (String[] args)
    {
        //given Input array
        int [] a = {74,-72,94,-53,-59,-3,-66,36,-13,22,73,15,-52,75};
        System.out.println("Maximum contiguous sum is " +
                                       maxSubArraySum(a));
    }
 
    static int maxSubArraySum(int a[])
    {
        int size = a.length;
        // max calculate the maximum sum so far
        // sum calculate the running sum of array
        int max = Integer.MIN_VALUE, sum = 0;
 
        for (int i = 0; i < size; i++)
        {
            sum = sum + a[i];
            //if running sum is greater than maximum sum update it
            if (max <sum)
                max = sum;
            // if sum is -ve than start for new subarray with sum=0
            if (sum < 0)
                sum = 0;
        }
        return max;
    }
}

// output for above input=156
// Time complexity O(n)