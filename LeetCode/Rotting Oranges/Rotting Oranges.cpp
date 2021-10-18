class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0,freshCount=0; 
        
        int dir[5] = {-1,0,1,0,-1}; 
        
        // using a dir array which is useful to travel in four directions i.e top left bottom right
        
            
        queue<pair<int,pair<int,int>>> q;

        // using queue to apply bfs on grid used type of queue as pair<int,pair<int,int>>
        // so in queue three things are stored first the mintime and then row and column index of the grid cell

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){ // initially push all the rotten oranges in queue and mark it visited i.e grid[i][j] = -1
                    grid[i][j] = -1;
                    q.push({0,{i,j}});
                }
                if(grid[i][j] == 1)freshCount++; // keeping track of count of fresh oranges in freshCount variable
            }
        }

        // here logic applied is to apply bfs and in each one unit time for each rotten orange 
        // make adjacent neighbouring fresh oranges rotten and push the rotten orange cell
        // row and column index and mintime+1 in queue and repeat the process until all adjacent
        // fresh oranges are rotten 
        
        while(!q.empty()){
            int qsize = q.size();
            
            for(int i=0;i<qsize;i++){
                ans = q.front().first;
                int row = q.front().second.first;
                int col = q.front().second.second;
                q.pop();
                
                for(int i=0;i<4;i++){
                    int newrow = row + dir[i];
                    int newcol = col + dir[i+1];
                    
                    if(newrow < 0 || newcol < 0 || newrow == n || newcol == m)continue; // condition to check if adjacent cell of grid is within the boundary of grid

                    if(grid[newrow][newcol] == 1){   // if fresh orange found make it rotten mark it as visited and push it in queue
                        freshCount--;
                        grid[newrow][newcol] = -1;
                        q.push({mintime+1,{newrow,newcol}});  
                    }
                }
            }
            
        }

        // return ans only if all the fresh oranges are rotten otherwise return -1

        return (freshCount == 0)?ans:-1; 
    }
};

