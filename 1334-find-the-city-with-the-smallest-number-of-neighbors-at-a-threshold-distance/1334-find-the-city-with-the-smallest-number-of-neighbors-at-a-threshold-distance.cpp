class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adjLs(n,vector<int>(n,1e9));
        for (auto i : edges) {
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            adjLs[u][v] = wt;
            adjLs[v][u] = wt;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    adjLs[i][j] = 0;
                }
            }
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (adjLs[i][k] != 1e9 && adjLs[k][j] != 1e9) {
                        adjLs[i][j] =
                            min(adjLs[i][j], adjLs[i][k] + adjLs[k][j]);
                    }
                }
            }
        }
        int count = INT_MAX;
        int city = -1;

        for (int i = 0; i < n; i++) {
            int temp_count = 0;

            for (int j = 0; j < n; j++) {
                if (adjLs[i][j] <= distanceThreshold)
                    temp_count++;
            }

            if (temp_count <= count) {
                count = temp_count;
                city = i;
            }
        }
        return city;
    }
};