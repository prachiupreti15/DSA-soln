class Solution {
public:
    long long ans = 0;

    void dfs(TreeNode* root, int level, long long pos,
             vector<long long>& firstPos) {

        if (!root) return;

        if (level == firstPos.size())
            firstPos.push_back(pos);

        long long curr = pos - firstPos[level];

        ans = max(ans, curr + 1);

        dfs(root->left, level + 1, 2 * curr + 1, firstPos);
        dfs(root->right, level + 1, 2 * curr + 2, firstPos);
    }

    int widthOfBinaryTree(TreeNode* root) {
        vector<long long> firstPos;
        dfs(root, 0, 0, firstPos);
        return (int)ans;
    }
};