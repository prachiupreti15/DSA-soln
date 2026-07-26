/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> ans;
    unordered_set<int> del;

    TreeNode* Delete(TreeNode* root, bool isRoot) {
        if (!root) return nullptr;

        bool deleted = del.count(root->val);

        root->left = Delete(root->left, deleted);
        root->right = Delete(root->right, deleted);

        if (deleted) {
            return nullptr;
        }

        if (isRoot) {
            ans.push_back(root);
        }

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

        for (int x : to_delete) {
            del.insert(x);
        }

        Delete(root, true);

        return ans;
    }
};