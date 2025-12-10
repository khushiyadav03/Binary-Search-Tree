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
    Node* insert(Node* root, int key) {
        // base case - empty spot → create new node
        if (root == nullptr) {
            return new Node(key);
        }

        // go left
        if (key < root->data) {
            root->left = insert(root->left, key);
        }
        // go right  (only when strictly greater)
        else if (key > root->data) {
            root->right = insert(root->right, key);
        }
        // key == root->data → do nothing (no duplicates)

        return root;
    }
};
