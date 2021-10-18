/* 
APPROACH TOWARDS THE SOLUTION:

1. Create a map with structure (word -> frequency of word).
2. Get the frequency of each string
3. Add each string/int pair in our frequency map to a vector so we may sort by frequency.
4. Create a local function to be used to sort our string/int pairs.
5. Recalling, partial_sort runs at time complexity n*log(m) time complexity where m is the distance between arguments 1 and 2, which in this case is k, so time complexity is n*log(k).
6. Lastly, Push top k frequent words to output vector and return.
*/
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq_map; // A map with structure { word -> frequency of word }
        vector<pair<string, int>> vec; // Used to later sort our top k map entries.
        
        // Get the frequency of each string.
        for (string word : words)
            freq_map[word]++;
        
        // Add each string/int pair in our frequency map
        // to a vector so we may sort by frequency.
        for (auto word : freq_map)
            vec.push_back(word);
        
        // A local function to be used to sort our string/int pairs.
        auto compare_function = [](pair<string, int> a, pair<string, int> b) {
            if (a.second == b.second)
                return a.first.compare(b.first) < 0;
            return a.second > b.second;
        };
        
        // partial_sort runs at time complexity n*log(m) time complexity
        // where m is the distance between arguments 1 and 2,
        // which in this case is k, so time complexity is n*log(k).
        partial_sort(vec.begin(),
                     vec.begin() + k,
                     vec.end(),
                     compare_function);
        
        // Push top k frequent words to output vector and return.
        vector<string> output;
        for (int i = 0; i < k; i++)
            output.push_back(vec[i].first);
        
        return output;
    }
};
