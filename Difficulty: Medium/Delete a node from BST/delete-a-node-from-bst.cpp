/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    Node* delNode(Node* root, int x) {
        // code here
        if(!root) return NULL;
        
        if(root->data > x){
            root->left = delNode(root->left, x);
            return root;
        } else if(root->data < x){
            root->right = delNode(root->right, x);
            return root;
        } else {
            // leaf node
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            
            // 1st child exist
            else if(!root->right) { // left child exist
                Node *temp = root->left;
                delete root;
                return temp;
            }
            else if(!root->left) { // right child exits
                Node *temp = root->right;
                delete root;
                return temp;
            }
            
            // 2nd child exist
            else {
                // find the greatest element from left
                Node *child = root->left;
                Node *parent = root;
                
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