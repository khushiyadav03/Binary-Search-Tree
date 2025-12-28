class Solution {
  public:
    void find(Node* root, int low, int high, vector<int>& ans) {
        if (!root) return;

        // go left only if needed
        if (root->data > low)
            find(root->left, low, high, ans);

        // include node if in range
        if (root->data >= low && root->data <= high)
            ans.push_back(root->data);

        // go right only if needed
        if (root->data < high)
            find(root->right, low, high, ans);
    }

    vector<int> printNearNodes(Node* root, int low, int high) {
        vector<int> ans;
        find(root, low, high, ans);
        return ans;
    }
};
