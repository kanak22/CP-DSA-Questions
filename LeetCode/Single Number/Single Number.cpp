class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a=0;
        for(int i=0;i<nums.size();i++)
        {
            a^=nums[i]; //xor operator gives the single number (it returns 0 when xored with same numbers and the number itself when xored with 0)
        }
        return a;
    }
};
