class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adjLs[n];
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,INT_MAX);
        for(auto i : flights){
            adjLs[i[0]].push_back({i[1],i[2]});
        }
        dist[src] = 0;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stop = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if(stop > k){
                continue;
            }
            for(auto iter : adjLs[node]){
                int adjNode = iter.first;
                int edW = iter.second;
                if(cost + edW < dist[adjNode] && stop <= k){
                    dist[adjNode] = cost+ edW;
                    q.push({stop+1,{adjNode,dist[adjNode]}});
                }
            }
        }
        if(dist[dst] == INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};