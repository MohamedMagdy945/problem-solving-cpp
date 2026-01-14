class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;

    void backtrack(int start, int n, int k) {
        // If the combination is complete
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        // Try numbers from 'start' to 'n'
        for (int i = start; i <= n; i++) {
            current.push_back(i);
            backtrack(i + 1, n, k); // move to next number
            current.pop_back();     // undo choice
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n, k);
        return result;
    }
};
