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
    TreeNode *first = NULL, *middle = NULL, *last = NULL, *prev = NULL;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        // Detect violation
        if (prev && root->val < prev->val) {
            // First violation
            if (!first) {
                first = prev;
                middle = root;
            }
            // Second violation
            else {
                last = root;
            }
        }

        // mark this node as previous
        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN);

        inorder(root);

        // Two nodes are non-adjacent
        if (first && last) {
            swap(first->val, last->val);
        }
        // Two nodes are adjacent
        else if (first && middle) {
            swap(first->val, middle->val);
        }
    }
};
