class Solution {
private:
    bool dfs(int start,vector<vector<int>>& graph,vector<int>&vis){
        vis[start] = 1;
        for(auto i : graph[start]){
            if(vis[i] == 0){
                if(dfs(i,graph,vis) == true){
                    return true;
                }
            }else if(vis[i] == 1){
                return true;
            }
        }
        vis[start] = 2;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,0);
        vector<int>ans;
        for(int i = 0 ; i < n;i++){
            if(vis[i]== 0){
                dfs(i,graph,vis);
            }
        }
        for(int i = 0; i < n;i++){
            if(vis[i] == 2){
                ans.push_back(i);
            }
        }
        return ans;
    }
};