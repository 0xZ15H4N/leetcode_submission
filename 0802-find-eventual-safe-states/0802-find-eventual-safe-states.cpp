class Solution {
private:
    bool dfs(int Node, vector<vector<int>>& graph, vector<int>& vis,
             vector<int>& pathVis, vector<int>& check) {
        vis[Node] = 1;
        pathVis[Node] = 1;
        for (auto i : graph[Node]) {
            if (!vis[i]) {
                if (dfs(i, graph, vis, pathVis, check) == true) {
                    return true;
                }
            } else if (pathVis[i]) {
                return true;
            }
        }
        check[Node] = 1;
        pathVis[Node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int Nodes = graph.size();
        vector<int> vis(Nodes, 0);
        vector<int> pathVis(Nodes, 0);
        vector<int> check(Nodes, 0);
        vector<int> ans;
        for (int i = 0; i < Nodes; i++) {
            if (!vis[i]) {
                dfs(i, graph, vis, pathVis, check);
            }
        }
        for (int i = 0; i < Nodes; i++) {
            if (check[i] == 1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};