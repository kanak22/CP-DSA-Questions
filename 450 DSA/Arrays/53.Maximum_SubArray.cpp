#include "bits/stdc++.h"
class Solution
{
public:
    int maxSubArray(vector<int> &n)
    {
        int sum = 0, maxn = INT_MIN;
        for (int i = 0; i < n.size(); i++)
        {
            sum = sum + n[i];
            maxn = max(sum, maxn);
            if (sum < 0)
            {
                if (n[i] < 0)
                    sum = 0;
            }
        }
        return maxn;
    }
};
