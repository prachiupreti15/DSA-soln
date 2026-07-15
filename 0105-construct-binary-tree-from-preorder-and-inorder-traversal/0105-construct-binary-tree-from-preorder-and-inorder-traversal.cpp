class Solution {
public:

    unordered_map<int, int> inorderFreq;

    int preIdx = 0;

    TreeNode* build(vector<int>& preorder, int left, int right) {

        if (left > right) return nullptr;

        int rootVal = preorder[preIdx++];
        TreeNode* newRoot = new TreeNode(rootVal);

        int mid = inorderFreq[rootVal];

        newRoot->left = build(preorder, left, mid - 1);
        newRoot->right = build(preorder, mid + 1, right);

        return newRoot;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = inorder.size();

        for (int i = 0; i < n; i++) {
            inorderFreq[inorder[i]] = i;
        }

        return build(preorder, 0, n - 1);
    }
};