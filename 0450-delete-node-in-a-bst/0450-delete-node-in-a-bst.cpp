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
    TreeNode* deleteNode(TreeNode* root, int x) {
        if(!root) return NULL;
        
        if(root->val > x){
            root->left = deleteNode(root->left, x);
            return root;
        } else if(root->val < x){
            root->right = deleteNode(root->right, x);
            return root;
        } else {
            // leaf node
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            
            // 1st child exist
            else if(!root->right) { // left child exist
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            else if(!root->left) { // right child exits
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            
            // 2nd child exist
            else {
                // find the greatest element from left
                TreeNode *child = root->left;
                TreeNode *parent = root;
                
                // right most node tak pahuchana h
                while(child->right){
                    parent = child;
                    child = child->right;
                } 
                
                if(root != parent) {
                    parent->right = child->left;
                    child->left = root->left;
                    child->right = root->right;
                    delete root;
                    return child;
                } else {
                    child->right = root->right;
                    delete root;
                    return child;
                }
            }
        }
    }
};