class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int n=matrix.size();
        int m=matrix[0].size();
        
        //intializing the 4 variables
        int sr=0;
        int er=n-1;
        int sc=0;
        int ec=m-1;
        int size=m*n;
        int count=0;
        
        while(sr<=er && sc<=ec)
        {
            for(int col=sc;col<=ec && count<size;col++)
            {
                result.push_back(matrix[sr][col]);
                count++;
            }
            for(int row=sr+1;row<=er && count<size;row++)
            {
                result.push_back(matrix[row][ec]);
                count++;
            }
            for(int col=ec-1;col>=sc && count<size;col--)
            {
                result.push_back(matrix[er][col]);
                count++;
            }
            for(int row=er-1;row>=sr+1 && count<size;row--)
            {
                result.push_back(matrix[row][sc]);
                count++;

            }
            
            if (sr == er-1 || sc == ec-1)
                break;
            
            sr++;
            er--;
            sc++;
            ec--;
        }
        return result;
    }
};
