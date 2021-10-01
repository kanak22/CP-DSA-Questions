/*Idea:
The main idea here is to use two pointer approach to do the task
two pointers declared one referrring to front of an array and other one reffering to the back of the array
until the front pointer is less than the rear pointer this code will run along and swap values
*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//function to display the array
void disp ( int arr[],int size)
{
    cout<<"The array is:\n";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
//function to swap two values using call by refernce method
void swap(int &value_1,int &value_2)
{
    int temp;
    temp=value_1;
    value_1=value_2;
    value_2=temp;
}
//reversing the array using two pointer approach
void reverse(int a[],int size)
{int i=0;
int j=size-1;
int temp;
    while(i<j)    {
        swap(a[i],a[j]);
        ++i;
        --j;
    }
   
    
}
int main()
{
   int size;
   cout<<"Enter the size of the array:\n";
   cin>>size;
   int arr[size];
   cout<<"Enter the elements of the array:\n";
   for(int i=0;i<size;i++)
   {
       cin>>arr[i];
   }
   cout<<"Before reversing:\n";
   disp(arr,size);
   reverse(arr,size);
   cout<<"After reversing:\n";
   disp(arr,size);
   
   

    return 0;
}

/*
Sample input output:
Enter the size of the array:

5

Enter the elements of the array:

1 2 3 4 5

Before reversing:

The array is:

1 2 3 4 5 

After reversing:

The array is:

5 4 3 2 1 



*/
