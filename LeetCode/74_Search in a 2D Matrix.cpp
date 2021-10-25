class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.size() == 0) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int t = (m * n) -1;
        int low , high;
        int i, j;

        low = 0;
        high = t;

        while(low <= high) {
            t = (high + low) / 2;
            i = t / n; // get the row number.
            j = t % n; // get the column number.
                        
            if(matrix[i][j] == target)
                return true;
            else if(target < matrix[i][j]) {
                high = t-1;
            }else{
                low = t+1;
            }
        }
        return false;
    }
};