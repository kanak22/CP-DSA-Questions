class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq; //storing the frequency of every element in the array
        for (auto n : nums)
            freq[n]++;
        
        int maxi = 0;
        //iterating over the map
        for (auto [num, f] : freq) {
            // finding whether num+1 element exists in the array
            if (freq.find(num+1) != freq.end())
                maxi = max(maxi, f + freq[num+1]);
        }
        return maxi;
    }
};