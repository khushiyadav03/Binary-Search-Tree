class Solution {
  public:
    Node *first = NULL, *middle = NULL, *last = NULL, *prev = NULL;
    
    void inorder(Node* root){
        if(!root) return;
        
        inorder(root->left);
        
        if(prev != NULL && root->data < prev->data){
            if(first == NULL){
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        
        prev = root;
        inorder(root->right);
    }
    
    void correctBST(Node* root) {
        prev = NULL;
        inorder(root);
        
        if(first && last){
            swap(first->data, last->data);
        } else if(first && middle){
            swap(first->data, middle->data);
        }
    }
};
