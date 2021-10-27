/**
 * @file "reshape the matrix.cpp"
 * @author Vipul Kumar Singh
 * @brief  (https://leetcode.com/problems/reshape-the-matrix/)
 * @version 0.1
 * @copyright Copyright (c) 2021
 */
class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) // creation of vector type function using 2d matrix
    {
        int row = mat.size(), row1 = 0;
        int column = mat[0].size(), column1 = 0;

        /*
        Here ,
        the variable row is assigned the row size of the mat matrix
        the variable column is assigned the column size of the mat matrix
        */

        if (row * column != r * c) // edge case for better performance and to avoid errors if the size of two (2D matrix) are not same
            return mat;

        vector<vector<int>> v(r, vector<int>(c)); // creation of 2d matrix

        // traversing the matrix and perform the some specified actions
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                v[i][j] = mat[row1][column1];
                ++column1;

                if (row1 < row && column1 == column)
                {
                    ++row1;
                    column1 = 0;
                }
            }
        }

        return v;
    }
};

/*
   Constraints:
    
    m == mat.length
    n == mat[i].length
    1 <= m, n <= 100
    -1000 <= mat[i][j] <= 1000s
    1 <= r, c <= 300

  Some Test case :
  1 .  Input: mat = [[1,2],[3,4]], r = 2, c = 4
       Output: [[1,2],[3,4]]

  2.   Input: mat = [[1,2],[3,4]], r = 1, c = 4
       Output: [[1,2,3,4]]

  
 


*/