class Solution {
  public:

    struct NodeValue {
        int minNode;
        int maxNode;
        int maxSize;

        NodeValue(int minNode, int maxNode, int maxSize) {
            this->minNode = minNode;
            this->maxNode = maxNode;
            this->maxSize = maxSize;
        }
    };

    NodeValue largestBSTSubtreeHelper(Node* root) {
        // Empty tree is a BST of size 0
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);

        // Check if current tree is BST
        if (left.maxNode < root->data && root->data < right.minNode) {
            return NodeValue(
                min(root->data, left.minNode),
                max(root->data, right.maxNode),
                left.maxSize + right.maxSize + 1
            );
        }

        // Not a BST
        return NodeValue(
            INT_MIN,
            INT_MAX,
            max(left.maxSize, right.maxSize)
        );
    }

    int largestBst(Node *root) {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};
