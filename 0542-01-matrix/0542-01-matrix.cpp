class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> dist(rows,vector<int>(cols,0));
        vector<vector<int>> vis(rows,vector<int>(cols,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,-1,0,1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;

            dist[row][col] = steps;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nRow  = row + delRow[i];
                int nCol  = col + delCol[i];
                if(nRow >=0 && nRow < rows && nCol >=0 && nCol < cols && vis[nRow][nCol] == 0){
                    q.push({{nRow,nCol},steps+1});
                    vis[nRow][nCol] = 1;
                }

            }
        }
        return dist;
    }
};