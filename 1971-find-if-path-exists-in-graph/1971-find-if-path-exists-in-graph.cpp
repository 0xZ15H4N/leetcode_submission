class Solution {
private:
    bool solve(int start, int end, vector<vector<int>>& edges,
               vector<int>& vis) {
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            if (front == end) {
                return true;
            }
            for (auto it : edges[front]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return false;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> vis(n, 0);
        return solve(source, destination, adj, vis);
    }
};