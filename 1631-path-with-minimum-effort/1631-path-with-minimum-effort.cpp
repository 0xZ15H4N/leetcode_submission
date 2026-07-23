
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> vis(rows,vector<int>(cols,1e9));
        q.push({0,{0,0}});   
        int dir[] = {-1,0,1,0,-1};
        vis[0][0] = 0;
        while(!q.empty()){
            int effort = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            q.pop();
            if(r == rows-1 && c == cols-1){
                return effort;
            }
            for(int i = 0; i < 4;i++){
                int nrow = r + dir[i];
                int ncol = c + dir[i+1];
                if(nrow >=0 && nrow < rows && ncol >=0 && ncol < cols){
                    int nEffort = max(effort,abs(heights[r][c] - heights[nrow][ncol]));
                    if(nEffort < vis[nrow][ncol]){
                        vis[nrow][ncol] = nEffort;
                        q.push({nEffort,{nrow,ncol}});
                    }    
                } 
            }
        }
        return 0;
    }
};