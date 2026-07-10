/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;

    void collect(TreeNode* root, int dist) {
        if (!root || dist < 0) return;

        if (dist == 0) {
            ans.push_back(root->val);
            return;
        }

        collect(root->left, dist - 1);
        collect(root->right, dist - 1);
    }

    int dfs(TreeNode* root, TreeNode* target, int k) {
        if (!root) return -1;

        if (root == target) {
            collect(root, k);
            return 0;
        }

        int left = dfs(root->left, target, k);

        if (left != -1) {
            if (left + 1 == k) {
                ans.push_back(root->val);
            } else {
                collect(root->right, k - left - 2);
            }
            return left + 1;
        }

        int right = dfs(root->right, target, k);

        if (right != -1) {
            if (right + 1 == k) {
                ans.push_back(root->val);
            } else {
                collect(root->left, k - right - 2);
            }
            return right + 1;
        }

        return -1;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, target, k);
        return ans;
    }
};