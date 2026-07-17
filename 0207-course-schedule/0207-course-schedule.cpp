class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjLs(numCourses);
        vector<int> inDegree(numCourses, 0);
        queue<int> q;
        vector<int> topo;

        // created an adjency list
        for (int i = 0; i < prerequisites.size(); i++) {
            adjLs[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (int i = 0; i < numCourses; i++) {
            for (auto it : adjLs[i]) {
                inDegree[it]++;
            }
        }
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) { // no indegree
                q.push(i);
            }
        }

        while (!q.empty()) {
            int top = q.front();
            q.pop();
            topo.push_back(top);
            for (auto it : adjLs[top]) {
                inDegree[it]--;
                if (inDegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        if (topo.size() == numCourses) {
            return true; // no cycle detected
        } 
        return false;
    }
};