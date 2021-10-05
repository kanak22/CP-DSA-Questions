//solution

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector <int> arr;  // initializing a vector array of name arr
        for(int i=0; i<nums.size(); i++){  //using the for loop to iterate through the array
            arr.push_back(nums[nums[i]]); // adding the required elements in the array
        }
        return arr; //returning the array to the function call
    }
};