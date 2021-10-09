/**
 * @file Determine Whether Matrix Can Be Obtained By Rotation.cpp
 * @author Vipul Kumar Singh ( https://github.com/vipul-2003/ACM-PROJECT)
 * @brief  (https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/)
 * @version 0.1
 * @date 2021-10-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

class Solution
{
public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        int size = mat.size();
        int size1 = mat[0].size();

        bool ok = true;

        int temp = 0; // for storing temporary variable

        int t = 4; //  for the running of loop atmost 4 times

        while (t > 0)
        {

            // for  the transpose of the matrix
            for (int i = 0; i < size; i++)
            {
                for (int j = i; j < size1; j++)
                {
                    temp = mat[i][j];
                    mat[i][j] = mat[j][i];
                    mat[j][i] = temp;
                }

                reverse(mat[i].begin(), mat[i].end());
            }

            // //  for the checking of the numbers
            // for (int i = 0; i < size; i++)
            // {
            //     for (int j = 0; j < size1; j++)
            //     {
            //         if (mat[i][j] != target[i][j])
            //         {
            //             ok = false;
            //         }
            //     }
            // }
            
            if (mat != target)
            {
                ok = false ;
            }

            if (ok)
                return true;

            t--;
            ok = true;
        }

        return false;
    }
};