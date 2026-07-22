class Solution {
private:
    bool dfs(int start,vector<vector<int>>& graph,vector<int>&vis,vector<int>&pathVis,vector<int>&check_arr){
        vis[start] = 1;
        pathVis[start] = 1;
        for(auto i : graph[start]){
            if(!vis[i]){
                if(dfs(i,graph,vis,pathVis,check_arr) == true){
                    return true;
                }
            }else if(pathVis[i]){
                return true;
            }
        }
        check_arr[start]=1;
        pathVis[start] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,0);
        vector<int>pathVis(n,0);
        vector<int>check_arr(n,0);
        vector<int>ans;
        for(int i = 0 ; i < n;i++){
            if(!vis[i]){
                dfs(i,graph,vis,pathVis,check_arr);
            }
        }
        for(int i = 0; i < n;i++){
            if(check_arr[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};