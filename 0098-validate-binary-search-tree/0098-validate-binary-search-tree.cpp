class Solution {
public:
    bool BST(TreeNode* root, long long& prev) {
        if (!root) return true;

        if (!BST(root->left, prev)) return false;

        if (root->val <= prev) return false;

        prev = root->val;

        return BST(root->right, prev);
    }

    bool isValidBST(TreeNode* root) {
        long long prev = LLONG_MIN;
        return BST(root, prev);
    }
};
