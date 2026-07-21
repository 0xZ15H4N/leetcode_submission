class Solution {
private:
    void dfs(vector<int>adjLs[],vector<int>&vis,int node){
       vis[node] = 1;
       for(auto adjNode : adjLs[node]){
            if(!vis[adjNode]){
                dfs(adjLs,vis,adjNode);
            }
       }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int row = isConnected.size();
        int col = isConnected[0].size();
        vector<int>adjLs[row];
        vector<int>vis(row,0);

        for(int i = 0; i<row;i++){
            for(int j= 0; j <col;j++){
                if(i != j && isConnected[i][j]){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        for(int i =0 ; i< row; i++){
            if(!vis[i]){
                count++;
                dfs(adjLs,vis,i);
            }
        }
        return count;
    }
};