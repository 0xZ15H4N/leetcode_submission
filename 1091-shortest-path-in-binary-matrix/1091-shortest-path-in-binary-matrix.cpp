class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid.size() == 1 && grid[0][0] == 0){
            return 1;
        }
        if(grid[0][0]){
            return -1;
        }
        int dirRow[] = {-1, 0, 1, 0, 1, -1, 1, -1};
        int dirCol[] = {0, -1, 0, 1, 1, -1, -1, 1};
        int N = grid.size(); // rows
        int M =  grid[0].size(); // cols
        queue<pair<int, pair<int, int>>>q; 
        // why not taking pq cause it will already be in ascending
        // order cause we are moving 1 unit in all direction
        vector<vector<int>>dist(N,vector<int>(M,INT_MAX));
        dist[0][0] = 1; // its not talking about minimum path , its taking about minimum cell visited so we take 1 not 0;
        q.push({1, {0, 0}});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(int i = 0 ; i < 8; i++){
                int newr = r + dirRow[i];
                int newc = c + dirCol[i];

                if(newr >=0 && newr < N && newc >= 0 && newc < M && grid[newr][newc] == 0 && dis + 1 < dist[newr][newc]){
                    dist[newr][newc] = dis+1;
                    if(newr == N-1 && newc == M-1){
                        return dis+1;
                    }
                    q.push({dis+1,{newr,newc}});
                }
            }
        }
        return -1;
    }
};