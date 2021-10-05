// leetcode question: https://leetcode.com/problems/first-missing-positive/

// This problem can be solved using cyclic sort :
// We perform cyclic sort on the array and find the fist number that in in the wrong index this iis our missing number
class Solution {
    public int firstMissingPositive(int[] arr) {
        int i = 0;
        while(i<arr.length){
            if(arr[i]>0&&arr[i]<=arr.length&&arr[i]!=(i+1)&&arr[i]!=arr[arr[i]-1]){ // checking if the number is at its correct index or not : if not then swap it with it's correct index
                int temp = arr[arr[i]-1]; // swap with the correct position
                arr[arr[i]-1] = arr[i];
                arr[i]=temp;
            }else{ // is the number is negative or if the number is already at its correct index we simply ignore it 
                i++;
            }
        }
        // find the first number that is at a wrong index and return the number that was supposed to be at this index : this is our answer
        for(i=0;i<arr.length;i++) if(arr[i]!=(i+1)) return i+1;
        // if all the numbers are at their correct index then the missing number is the very last number
        return arr.length+1;
    }
}