/*
Ques:
Given an array A of positive integers. Your task is to find the leaders in the array. An element 
of array is leader if it is greater than or equal to all the elements to its right side. 
The rightmost element is always a leader. */

/*Example
Input:
n = 6
A[] = {16,17,4,3,5,2}
Output: 2 5 17
Explanation: The first leader is 17 
as it is greater than all the elements
to its right.  Similarly, the next 
leader is 5. The right most element 
is always a leader so it is also 
included.Output order can be any unless it is not specified.


*/

//Solution

class LeadersInArray
{
    /* Java Function to print leaders in an array */
    void printLeaders(int arr[], int size)
    {
        int max_from_right =  arr[size-1];
  
        /* Rightmost element is always leader */
        System.out.print(max_from_right + " ");
      
        for (int i = size-2; i >= 0; i--)
        {
            if (max_from_right < arr[i])
            {          
            max_from_right = arr[i];
            System.out.print(max_from_right + " ");
            }
        }   
    }
 
    /* Driver program to test above functions */
    public static void main(String[] args)
    {
        LeadersInArray lead = new LeadersInArray();
        int arr[] = new int[]{16, 17, 4, 3, 5, 2};
        int n = arr.length;
        lead.printLeaders(arr, n);
    }
}

//output 2 5 17
//Time complexity O(n)