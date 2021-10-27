class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.size() == 0) return false;
        
        int m = matrix.size();// number of rows
        int n = matrix[0].size();// number of columns
        
        int elements = (m * n) -1; //total elements present in the matrix
        int low , high;
        int i, j;

        low = 0;
        high = elements;
        //binary searching used 
        while(low <= high) {
            int mid = (high + low) / 2;
            i = mid / n; // getting the row number.
            j = mid % n; // getting the column number.
                        
            if(matrix[i][j] == target) //target is the element to be searched for inside the matrix
                return true;
            else if(target < matrix[i][j]) {
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return false;
    }
};