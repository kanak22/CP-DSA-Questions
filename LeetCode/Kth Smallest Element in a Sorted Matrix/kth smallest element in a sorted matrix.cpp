class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        // Here the idea is, to store all elements of the given 2d matrix vector in another separate vector v.
        // After that, we will use sorting, in order to achieve the required answer in O(1).
        
        vector<int> v;
        
        // Storing all elements in vector v
        for(int i = 0;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix[0].size();j++)
                v.push_back(matrix[i][j]);
        }
        // Sorting it to have the required kth smallest element in O(1).
        sort(v.begin(),v.end());
        
        // Returning the answer
        return v[k-1];
    }
};
