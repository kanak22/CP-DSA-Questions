/*
APPROACH TOWARDS THE PROBLEM:

1. The easiest way which requires more time is sorting the array, the time complexity will be O(n log n) (we ignore this method in this post).
2. Another way is to use more space, but we can get O(n) time, which is faster than the sorting approach. 
3. Thinking about the definition of H-index, the max number of h is the number of paper we have. 
4. So we could use a map (or vector in my case), to store: if current paper has i citations, we add map[i] by 1. 
5. Note that if citation is more than the number of papers, we added 1 to the last index of the map.
6. In this way, for each key i in our map, we only need to add the sum of all values afer i to the end, we will know how many papers are there have more then i citations. 
7. The maximum i is what we want.

*/
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int ssum = 0;
        int sz = citations.size();
        vector<int> mp(sz + 1, 0);

        for (int i = 0; i < sz; ++i)
        {
            mp[min(sz, citations[i])] += 1;
        }

        for (int i = sz; i >= 0; --i)
        {
            ssum += mp[i];
            if (ssum >= i)
            {
                return i;
            }
        }
        return 0;
    }
};
