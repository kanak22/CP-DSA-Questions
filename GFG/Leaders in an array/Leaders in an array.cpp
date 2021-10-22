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

#include <iostream>
#include <cmath>
using namespace std;


void leaders(int arr[], int n) //function which will print leaders in an array
{
	int curr_ldr = arr[n - 1];   //initialise the variable curr_ldr with last element of an array

	cout<<curr_ldr<<" ";

	for(int i = n - 2; i >= 0; i--)
	{
		if(curr_ldr < arr[i])  //making comparisons
		{
			curr_ldr = arr[i];

			cout<<curr_ldr<<" "; //printing the curr_ldr
		}
	}
}



int main() {

    int n;
    cin>>n;  //taking input of number of elements in an array
    int arr[n];//declaration of an array
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];  //taking input of array elements
    }

      leaders(arr, n); //calling function to find leader of an array
    
}
