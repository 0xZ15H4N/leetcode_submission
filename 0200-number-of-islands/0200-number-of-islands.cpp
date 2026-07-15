class Solution {
private:
    void bfs(int row, int col, int rows, int cols, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1; // first time
        while (!q.empty()) {
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();
            int dRow[] = {-1, 0, 1, 0};
            int dCol[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int nRow = currRow + dRow[i];
                int nCol = currCol + dCol[i];

                if (nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols &&
                    grid[nRow][nCol] == '1' && !vis[nRow][nCol]) {

                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        int count = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    bfs(row, col, rows, cols, grid, vis);
                    count++;
                }
            }
        }
        return count;
    }
};