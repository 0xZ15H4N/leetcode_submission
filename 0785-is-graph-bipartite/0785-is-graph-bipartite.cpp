class Solution {
private : 
    bool check(int start ,vector<vector<int>>& graph,vector<int>& vis){
        int Nodes = graph.size();
        // will use 0 or 1 for coloring the nodes , -1 means no color
        queue<int> q;
        q.push(start);
        vis[start] = 0;
        while (!q.empty()) {
            int currNode = q.front();
            q.pop();
            for (auto adjNode : graph[currNode]) {
                if (vis[adjNode] == -1) { // not visited yet
                    vis[adjNode] = !vis[currNode]; 
                    q.push(adjNode);
                }
                else if (vis[adjNode] == vis[currNode]) {
                    return false;
                } // both same color
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int Nodes = graph.size();
        vector<int>vis(Nodes,-1);
        for(int i = 0; i < Nodes; i++){
            if(vis[i] == -1){
                if(check(i,graph,vis) == false){
                    return false;
                }
            }
        }
        return true;
    }
};