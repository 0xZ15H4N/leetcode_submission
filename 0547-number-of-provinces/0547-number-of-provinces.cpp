class Solution {
private:
    void dfs(vector<vector<int>>&adjLs,vector<int>&vis,int node){
        vis[node] = 1;
        for(auto it: adjLs[node]){
            if(!vis[it]){
                dfs(adjLs,vis,it);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        // convert adj Matrix -> adj List
        vector<vector<int>> adjLs(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n ;j++){
                if(i!=j && isConnected[i][j] ==1){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        int count = 0;
        vector<int> vis(n,0);
        for(int i = 0 ; i < n; i++){
            if(!vis[i]){
                count++;
                dfs(adjLs,vis,i);
            }
        }
        return count;
    }
};