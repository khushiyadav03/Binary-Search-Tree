class Solution {
  public:
    void solve(int arr[], int& index, int N, int minVal, int maxVal) {
        if (index == N || arr[index] <= minVal || arr[index] >= maxVal)
            return;

        int root = arr[index++];

        solve(arr, index, N, minVal, root);  // left
        solve(arr, index, N, root, maxVal);  // right
    }

    int canRepresentBST(int arr[], int N) {
        int index = 0;
        solve(arr, index, N, INT_MIN, INT_MAX);
        return (index == N);
    }
};
