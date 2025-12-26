// User function template in C++

/*

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

*/

class Solution {
  public:
    // Function that constructs BST from its preorder traversal.
    Node* preorder(int pre[], int& index, int size, int lower, int upper){
        if(index == size || pre[index] <= lower || pre[index] >= upper) 
            return NULL;
        
        Node* root = newNode(pre[index++]);
        root->left = preorder(pre, index, size, lower, root->data);
        root->right = preorder(pre, index, size, root->data, upper);
        
        return root;
    }
    
    
    Node* Bst(int pre[], int size) {
        // code here
        int index = 0;
        return preorder(pre, index, size, INT_MIN, INT_MAX);
        
    }
};