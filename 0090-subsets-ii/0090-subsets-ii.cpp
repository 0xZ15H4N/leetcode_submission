class Solution {
private:
    void solve(set<vector<int>>& ans, vector<int> output, vector<int> nums, int size,
               int index) {
        if (index >= size) {
            if (ans.find(output) == ans.end()) {
                ans.insert(output);
            }
            return;
        }
        // exclude
        solve(ans,output,nums,size,index+1);

        //include
        output.push_back(nums[index]);
        solve(ans,output,nums,size,index+1);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<vector<int>> final_;
        vector<int> output;
        int index = 0;
        int size = nums.size();
        solve(ans, output, nums, size, index);
        for(auto i : ans){
            final_.push_back(i);
        }
        return final_;
    }
};