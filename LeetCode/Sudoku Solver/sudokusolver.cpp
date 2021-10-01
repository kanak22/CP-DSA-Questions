class Solution {
public:
    bool ans = false;
    vector<vector<char>> finans;
    bool issafe(int r,int c,vector<vector<char>>& board,char ch){
        for(int i=0; i<9; i++){
            if(board[i][c] == ch){
                return false;
            }
        }
        for(int i=0; i<9; i++){
            if(board[r][i] == ch){
                return false;
            }
        }
        
        r = r/3 * 3;
        c = c/3 * 3;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[i+r][j+c] == ch){
                    return false;
                }
            }
        }
        return true;        
    }
    
    void func(int r,int c,vector<vector<char>>& board){
        if(r == 9){
            ans = true;
            finans = board;
            return;
        }
        int nextr, nextc;
        if(c == 8){
            nextr = r + 1;
            nextc = 0;
        }
        else{
            nextr = r;
            nextc = c + 1;
        }
        
        if(board[r][c] == '.'){
            for(char ch = '1'; ch <= '9' ; ch++){
                if(issafe(r,c,board,ch)){
                    board[r][c] = ch;
                    func(nextr,nextc,board);
                    board[r][c] = '.';
                }
            }
        }
        else{
            func(nextr,nextc,board);
        }
        return;
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        func(0,0,board);  
        board = finans;
        return;
    }
};