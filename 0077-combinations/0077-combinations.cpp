class Solution {
private:
    void subsequence_of_array(vector<vector<int>>& ans,
                                                     vector<int> output, int& n,
                                                     int& m, int index) {
        if (output.size() == m) {
            ans.push_back(output);
            return;
        }
        for (int i = index; i <=n; i++) {
            output.push_back(i);
            subsequence_of_array(ans, output, n, m,i + 1);
            output.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int>output;
        subsequence_of_array(ans,output,n,k,1);
        return ans;
    }
};