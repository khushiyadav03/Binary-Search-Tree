class Solution {
  public:
    vector<int> findCommon(Node *r1, Node *r2) {

        vector<int> ans;

        // Two stacks to perform iterative inorder traversal
        stack<Node*> s1, s2;

        // Pointers to traverse both BSTs
        Node* root1 = r1;
        Node* root2 = r2;

        // Continue traversal while there are nodes to process
        while (root1 || root2 || (!s1.empty() && !s2.empty())) {

            // Push all left children of first BST (inorder traversal)
            while (root1) {
                s1.push(root1);
                root1 = root1->left;
            }

            // Push all left children of second BST (inorder traversal)
            while (root2) {
                s2.push(root2);
                root2 = root2->left;
            }

            // If either stack becomes empty, no more common elements possible
            if (s1.empty() || s2.empty())
                break;

            // Get the top nodes from both stacks
            Node* top1 = s1.top();
            Node* top2 = s2.top();

            // If both nodes have equal values, it's a common node
            if (top1->data == top2->data) {
                ans.push_back(top1->data);   // Store common value

                // Move to the right subtree of both nodes
                s1.pop();
                s2.pop();
                root1 = top1->right;
                root2 = top2->right;
            }

            // If value in first BST is smaller, move forward in first BST
            else if (top1->data < top2->data) {
                s1.pop();
                root1 = top1->right;
            }

            // If value in second BST is smaller, move forward in second BST
            else {
                s2.pop();
                root2 = top2->right;
            }
        }

        // Return all common elements found
        return ans;
    }
};
