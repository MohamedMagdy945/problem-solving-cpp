class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void backtrack(int idx, vector<int>& nums) {
        if (path.size() >= 2)
            ans.push_back(path);

        unordered_set<int> used; 

        for (int i = idx; i < nums.size(); i++) {
            if (!path.empty() && nums[i] < path.back())
                continue;

            if (used.count(nums[i]))
                continue;

            used.insert(nums[i]);
            path.push_back(nums[i]);
            backtrack(i + 1, nums);
            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(0, nums);
        return ans;
    }
};