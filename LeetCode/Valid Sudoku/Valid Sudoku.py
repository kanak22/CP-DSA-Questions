class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        centers = [[1,1],[1,4],[1,7],[4,1],[4,4],[4,7],[7,1],[7,4],[7,7]]
        for i in range(9):                        #Check the rows for duplicate
            horizontal = list(filter((".").__ne__, board[i]))
            if len(horizontal) != len(set(horizontal)):
                return False                       #Duplicate found 
        vert_board = list(zip(*board))
        for i in range(9):                       #Check the cols for duplicate
            vertical = list(filter((".").__ne__, vert_board[i]))
            if len(vertical) != len(set(vertical)):
                return False                       #Duplicate found 

        for _ in centers:                          #Check the inner grid
            i,j = _
            arr = []
            for m in range(-1,2):
                for n in range(-1,2):
                    arr.append(board[i+m][j+n])
            arr = list(filter((".").__ne__, arr))      #Remove the empty cells 
            if len(arr) != len(set(arr)):
                return False
        return True
