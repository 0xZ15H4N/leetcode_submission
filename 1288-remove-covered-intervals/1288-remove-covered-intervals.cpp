class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {
                if (a[0] == b[0])
                    return a[1] > b[1];
                return a[0] < b[0];
            });

        int count = 0;
        int farthestEnd = -1;

        for (auto &interval : intervals) {
            if (interval[1] > farthestEnd) {
                count++;
                farthestEnd = interval[1];
            }
        }

        return count;
    }
};