/**
 * @file "reshape the matrix.cpp"
 * @author Vipul Kumar Singh 
 * @brief  (https://leetcode.com/problems/reshape-the-matrix/)
 * @version 0.1
 * @copyright Copyright (c) 2021
 */
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int row = mat.size()  , row1 = 0;
        int column = mat[0].size() , column1 = 0;
        
       
      if (row* column != r*c) //edge case for better performance and to avoid errors 
          return mat;
 
        
        vector <vector <int> > v (r , vector<int> (c ));
        
        for (int i = 0 ; i < r ; i ++)
        {
            for ( int j = 0 ; j < c ; j++)
            {
                v[i][j] = mat[row1][column1];
                ++column1;
                
                if (row1 < row && column1 == column )
                {
                    ++row1;
                    column1 = 0;
                }
            }
        }
        
        return v ;
        
        
    }
};