class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        for(int i = digits.size()-1;i>=0;i--)
        {
            int d = digits[i];
            
            digits[i] = (d + c) % 10;
            c = (d+c)/10;
        }
        if(c != 0)
        {
            digits.emplace(digits.begin(),c);
        }
        return digits;
    }
};
