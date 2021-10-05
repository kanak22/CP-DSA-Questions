#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//Getting elements of an array  using  function
void get(int arr[],int size)
{cout<<"Enter the elements of the array:\n";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    
}
//Displaying elements of the array
void disp(int arr[],int size)
{
    cout<<"The array is:\n";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
//Function to find the minimum element while iterating an array and keeping track of a number 
//when the value of the variable which we hold now ,if happened to be greater than the current iterating value
// the value will be replaced so at the end of the iteration we would get the minimum element of the array
int min_ele(int arr[],int size)
{
    int min_ele=INT_MAX;
    for(int i=0;i<size;i++)
    {
        if(min_ele>arr[i])
        {
            min_ele=arr[i];
        }
    }
    return min_ele;
}
//Function to find the minimum element while iterating an array and keeping track of a number 
//when the value of the variable which we hold now ,if happened to be lesser than the current iterating value
// the value will be replaced so at the end of the iteration we would get the maximum element of the array
int max_ele(int arr[],int size)
{
    int max_ele=INT_MIN;
    for(int i=0;i<size;i++)
    {
        if(max_ele<arr[i])
        {
            max_ele=arr[i];
        }
    }
    return max_ele;
}

int main(){
    int size;
    cout<<"Enter the size of the array:\n";
    cin>>size;
    int arr[size];
    get(arr,size);
    disp(arr,size);
    //Printing the minimum and maximum value of the array
    cout<<"The minimum element in the array is: "<<min_ele(arr,size)<<"\n";
    cout<<"The maximum element in the array is: "<<max_ele(arr,size)<<"\n";
    return 0;
    
}
/* Sample Input and Sample Ouput
Enter the size of the array:

10

Enter the elements of the array:
22 13 45 10 2 -10 6 56 99 10

The array is:

22 13 45 10 2 -10 6 56 99 10 

The minimum element in the array is: -10

The maximum element in the array is: 99

*/

