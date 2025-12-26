/*struct Node
{
    int data;
    Node *left, *right;
};*/

Node* BST(int postorder[], int& index, int lower, int upper) {
    if (index < 0 || postorder[index] < lower || postorder[index] > upper) {
        return NULL;
    }

    Node* root = new Node(postorder[index--]);

    root->right = BST(postorder, index, root->data, upper);
    root->left  = BST(postorder, index, lower, root->data);

    return root;
}

Node* constructTree(int postorder[], int size) {
    int index = size - 1;   // start from end
    return BST(postorder, index, INT_MIN, INT_MAX);
}
