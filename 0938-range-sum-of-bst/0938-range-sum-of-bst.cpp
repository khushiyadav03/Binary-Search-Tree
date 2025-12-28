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
    void find(TreeNode* root, int low, int high, vector<int>& ans){
        if(!root) return;

        if(root->val > low && root->val > high){
            return find(root->left, low, high, ans);
        } else if(root->val < low && root->val < high){
            return find(root->right, low, high, ans);
        } else {
            find(root->left, low, high, ans);
            ans.push_back(root->val);
            find(root->right, low, high, ans);
        }
    }

    int sum(vector<int>& ans){
        int s = 0;
        for(int n : ans){
            s += n;
        }
        return s;
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> ans;
        int s = 0;
        find(root, low, high, ans);
        return sum(ans);
    }
};