/*
Question Link : https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1
Given a matrix of size r*c. Traverse the matrix in spiral form.
Example 1:
Input:
r = 4, c = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
*/

class Solution
{
    //Function to return a list of integers denoting spiral traversal of matrix.
    static ArrayList<Integer> spirallyTraverse(int matrix[][], int r, int c)
    {
        // code here
        ArrayList<Integer> al = new ArrayList<Integer>();
        int i,ri = 0,ci = 0;
        while(ri < r && ci < c)
        {
            // row
            for(i=ci;i<c;i++)
                al.add(matrix[ri][i]);
            ri++;
            
            // column
            for(i = ri; i < r;i++)
                al.add(matrix[i][c-1]);
            c--;
            
            // row
            if(ri < r)
                for(i=c-1;i>ci-1;i--)
                    al.add(matrix[r-1][i]);
               
            r--; 
            // column
            if(ci<c)
                for(i=r-1;i>ri-1;i--)
                    al.add(matrix[i][ci]);
            ci++;
        }
        return al;
    }
}
