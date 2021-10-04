/*
    Approach: 
        1. First we will make the duplicate array of the given array.
        2. Then we will sort the duplicate array so that we can know the correct position of the element
        3. Then we will start iterating on the given array and if we found an element which is not in its correct position,
        we will swap it to its correct position and increase our counter by 1 for every swap.
        4. We will repeat the step 3 till we get all the desired elements on their correct places (i.e. till sorted duplicate array becomes equal to the given array after swappings)
*/

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n=nums.size();
	    int count=0;
        vector<int> temp = nums;
        /// sorting the temp vector (dupliacate of the given vector)
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();){

            /// checking if the current position of the element matches with the sorted vector or not
            if(nums[i]==temp[i]){ 
                i++;
                continue;
            }
            else{
                /// if the element is not on its correct position we will find its correct position
                /// We used lower_bound function which will give us the iterator to the correct position of the element inside sorted temp vector
                /// Note: lower_bound gives us the iterator so to convert it into int type we subtracted it with temp.begin() which is the iterator that points to the starting of temp vector
                int idx = lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();

                /// After finding the correct index we swap the array and increase our counter by 1
                swap(nums[i],nums[idx]);
                count++;
            }
        }
        return count;
	}
};