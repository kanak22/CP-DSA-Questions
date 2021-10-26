class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> m;
        
        for(int i=0; i<nums.size(); i++)
        {
            //increase the value at the array element value index of the map
            m[nums[i]]++;
            //if the frequency of the element is more than one return true
            if(m[nums[i]] >= 2)
                return true;
        }
        
        return false;
    }
};
