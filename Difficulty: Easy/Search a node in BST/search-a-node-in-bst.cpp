/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool search(Node* root, int key) {
        // code here
        if(!root) return 0;
        
        if(root->data == key) return 1;
        
        if(root->data > key){
            search(root->left, key);
        } else {
            search(root->right, key);
        }
    }
};