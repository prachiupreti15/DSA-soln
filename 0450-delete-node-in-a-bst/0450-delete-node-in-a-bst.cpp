class Solution {
public:
    TreeNode* searchNode(TreeNode* root, int key, TreeNode*& parent) {

        if (!root)
            return nullptr;

        if (root->val == key)
            return root;

        if (key < root->val) {
            parent = root;
            return searchNode(root->left, key, parent);
        }

        parent = root;
        return searchNode(root->right, key, parent);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        TreeNode* parent = nullptr;
        TreeNode* keyNode = searchNode(root, key, parent);

        if (!keyNode)
            return root;

        if (!keyNode->left && !keyNode->right) {

            if (!parent) {
                delete root;
                return nullptr;
            }

            if (parent->left == keyNode)
                parent->left = nullptr;
            else
                parent->right = nullptr;

            delete keyNode;
        }

        else if (keyNode->left && !keyNode->right) {

            TreeNode* child = keyNode->left;

            if (!parent) {
                delete keyNode;
                return child;
            }

            if (parent->left == keyNode)
                parent->left = child;
            else
                parent->right = child;

            delete keyNode;
        }

        else if (!keyNode->left && keyNode->right) {

            TreeNode* child = keyNode->right;

            if (!parent) {
                delete keyNode;
                return child;
            }

            if (parent->left == keyNode)
                parent->left = child;
            else
                parent->right = child;

            delete keyNode;
        }

        else {

            TreeNode* newRoot = keyNode->left;

            TreeNode* curr = newRoot;

            while (curr->right)
                curr = curr->right;

            curr->right = keyNode->right;

            if (!parent)
                root = newRoot;
            else if (parent->left == keyNode)
                parent->left = newRoot;
            else
                parent->right = newRoot;

            delete keyNode;
        }

        return root;
    }
};