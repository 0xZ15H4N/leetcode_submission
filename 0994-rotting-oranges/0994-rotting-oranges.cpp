class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        // considering queue with pair which contain a pair and timer
        queue<pair<pair<int,int>,int>>q;  
        vector<vector<int>> vis(rows,vector<int>(cols,0));
        // pushing all the rotten oranges in the queue
        for(int i = 0 ; i < rows;i ++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2){
                    q.push(make_pair(make_pair(i,j),0));
                }
            }
        }
        // only tracks the max Time
        int timer = 0;
        vector<int> dirRow = {-1,0,1,0};
        vector<int> dirCol = {0,-1,0,1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int tm = q.front().second;
            timer = max(timer,tm);
            vis[row][col] = 1;
            q.pop();
            for(int i= 0; i < 4 ; i++){
                int nRow = row + dirRow[i];
                int nCol = col + dirCol[i];
                if(nRow >= 0 && nRow < rows && nCol >=0 && nCol < cols && !vis[nRow][nCol] && grid[nRow][nCol] == 1){
                    vis[nRow][nCol] = 1;
                    grid[nRow][nCol] = 2;
                    q.push(make_pair(make_pair(nRow,nCol),tm+1));
                }
            }
            
        }
        for(int i = 0 ; i < rows;i ++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        
        return timer;

    }
};