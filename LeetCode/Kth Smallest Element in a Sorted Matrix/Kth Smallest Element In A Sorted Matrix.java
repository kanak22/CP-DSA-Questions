class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int m = matrix.length, n = matrix[0].length;  // m = rows n = columns
        int low = matrix[0][0], high = matrix[m-1][n-1]; 
        //Using Binary Search
        //The mid is just a value calculated by using low and high, 
        //not a true element in the matrix, so when count < k, it means that the mid 
        //is small, let low = mid + 1 to find the true element in matrix one by one. 
        //And when count > k, it means that the mid is big enough, let high = mid to 
        //ensure the element we need is between low and high(mid). And when count = k, 
        //it means that there are k elements less than or equal to mid in the matrix, 
        //but we don't know whether the element we need is equal to mid. 
        //So let high = mid, it can ensure that the element we need is between low and high(mid).
        
        while(low < high){
            int mid = (high - low)/2 + low;
            int count = 0;
            int j = n - 1;
            for(int i = 0; i < m; i++){
                while(j >= 0 && matrix[i][j] > mid)
                    j--;
                count += j + 1;
            }
            if(count < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
}