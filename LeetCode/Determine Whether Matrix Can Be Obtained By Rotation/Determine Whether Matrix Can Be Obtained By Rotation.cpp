/**
 * @brief rotating the 2-D array for checking the element 
 * link to the question :: https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
 * 
 */

class Solution
{
public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        int size = mat.size(); //  to get the size of the Row of 2-D matrix
        int size1 = mat[0].size(); // to get the size of the Column of 2-D matrix
 
        bool ok = true;

        int temp = 0; // for storing temporary variable

        int t = 4; 
       
        /*  
        for the running of loop atmost 4 times as 90 X 4 = 360 degrees 
         so it can only be rotated four times as rotating 5 times make it same as 1st time rotation 
        */

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
                /*
                 use of predefined stl functions to reverses the elements of an matrix
                 */ 
            
            }
            

//          two of checking whether the matrix is same or not 
// first one is commented and second is used below 
//          for (int i = 0; i < size; i++)
//          {
//              for (int j = 0; j < size1; j++)
//              {
//                 if (mat[i][j] != target[i][j])
//                     {
//                       ok = false;
//                     }
//               }
//           }
            
            if (mat != target) // checking the elements of the matrix 
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