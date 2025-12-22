/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
    void largest(Node* root, int& k, int& ans){
        if(!root) return;
        
        largest(root->right, k, ans);
        k--;
        if(k == 0){
            ans = root->data;
        }
        if(k < 0) {
            return;
        }
        largest(root->left, k, ans);
    }
  
    int kthLargest(Node *root, int k) {
        // Your code here
        int ans = 0;
        largest(root, k, ans);
        return ans;
        
    }
};