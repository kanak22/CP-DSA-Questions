class Solution {

public int[][] matrixReshape(int[][] mat, int r, int c) {        
    //If mat array length is not equal to future matrix length return current array
    if(mat.length * mat[0].length != r*c){
        return mat;
    }        
    int x =0,y=0;
    var newArray = new int[r][c];        
    for(int i=0;i<mat.length;i++){
        for(int j=0;j<mat[0].length;j++){                
            newArray[x][y]= mat[i][j];                
            y++;
            //If column reaches to max then assign new row and set column from start
            if(y==c){
                x++;
                y=0;
            }
			
        }
    }
    return newArray;
    }  
}

