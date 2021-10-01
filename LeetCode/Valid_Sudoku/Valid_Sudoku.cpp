#include <bits/stdc++.h> //skip this when using in Leetcode as solution

using namespace std; //skip this when using in Leetcode as solution

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size();
        int rowsMarked[9][9] = {0};
        int colsMarked[9][9] = {0};
        int threeMarked[9][9] = {0};
        
        
        // int c = 0;
        // int box = 0;
        for(int i = 0; i < row; i++){
            for(int j=0 ;j<col; j++){
                
                //if there is a number already stored
                if(board[i][j] != '.'){
                    
                    //finding that number and make it as index by -1.
                    int number = board[i][j] - '0' - 1;
                    
                    //finding the box number.
                    int box = (i / 3)*3 + (j / 3);
                    
                    //if the row, col, 3*3 matrix already have that number return false
                    if(rowsMarked[i][number] == 1 || colsMarked[j][number] == 1 || threeMarked[box][number] == 1)
                        return false;
                    
                    //if not having then mark it 1
                    else
                        rowsMarked[i][number] = colsMarked[j][number] = threeMarked[box][number] = 1;
                }
            }
        }
        return true;
    }
};