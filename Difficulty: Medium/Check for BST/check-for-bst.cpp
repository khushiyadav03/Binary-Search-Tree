/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root, vector<int>& ans){
        if(!root) return;
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
  
    bool isBST(Node* root) {
        // code here
        vector<int> ans;
        inorder(root, ans);
        for(int i = 1; i<ans.size(); i++){
            if(ans[i] <= ans[i-1]){
                return 0;
            }
        }
        return 1;
    }
};