class Solution {
private:
    int cnt = 0;

    int dfs(TreeNode* root) {
        if (!root)
            return INT_MIN;

        int leftMax = dfs(root->left);
        int rightMax = dfs(root->right);

        int subtreeMax = max(root->val, max(leftMax, rightMax));

        if (root->val == subtreeMax)
            cnt++;

        return subtreeMax;
    }

public:
    int countDominantNodes(TreeNode* root) {
        dfs(root);
        return cnt;
    }
};