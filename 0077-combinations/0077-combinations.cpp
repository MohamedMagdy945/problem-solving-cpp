class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;

    void backtrack(int start, int n, int k) {
        if (cur.size() == k) {
            res.push_back(cur);
            return;
        }

        // Pruning: آخر رقم نقدر نبدأ منه
        int need = k - cur.size();
        for (int i = start; i <= n - need + 1; i++) {
            cur.push_back(i);
            backtrack(i + 1, n, k);
            cur.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n, k);
        return res;
    }
};
