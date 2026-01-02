class Solution {
  public:
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> ans;
        stack<Node*> s1, s2;

        Node* curr1 = root1;
        Node* curr2 = root2;

        while (curr1 || curr2 || !s1.empty() || !s2.empty()) {

            // Push left nodes of both trees
            while (curr1) {
                s1.push(curr1);
                curr1 = curr1->left;
            }

            while (curr2) {
                s2.push(curr2);
                curr2 = curr2->left;
            }

            // Decide which node to process
            if (s2.empty() || (!s1.empty() && s1.top()->data <= s2.top()->data)) {
                Node* node = s1.top(); s1.pop();
                ans.push_back(node->data);
                curr1 = node->right;
            } else {
                Node* node = s2.top(); s2.pop();
                ans.push_back(node->data);
                curr2 = node->right;
            }
        }

        return ans;
    }
};
