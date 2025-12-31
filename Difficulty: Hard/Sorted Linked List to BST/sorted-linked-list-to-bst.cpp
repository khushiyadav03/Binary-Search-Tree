class Solution {
  public:

    // Step 1: Convert Linked List to Array
    vector<int> linkedlisttoArray(LNode* head) {
        vector<int> arr;

        while (head != NULL) {
            arr.push_back(head->data);
            head = head->next;
        }

        return arr;
    }

    // Step 2: Build Balanced BST from sorted array
    TNode* buildBST(vector<int>& arr, int start, int end) {
        if (start > end) return NULL;

        int mid = start + (end - start + 1) / 2;
        TNode* root = new TNode(arr[mid]);

        root->left = buildBST(arr, start, mid - 1);
        root->right = buildBST(arr, mid + 1, end);

        return root;
    }

    // Main function
    TNode* sortedListToBST(LNode* head) {

        // Convert linked list to array
        vector<int> arr = linkedlisttoArray(head);

        // Build BST
        return buildBST(arr, 0, arr.size() - 1);
    }
};
