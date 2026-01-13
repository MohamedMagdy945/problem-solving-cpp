class Solution {
    private:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> used;
    public:
    void backtrack(vector<int>& nums)
    {
        if (path.size() == nums.size())
        {
            ans.push_back(path);
            return;
        }
        unordered_set<int> used2;
        for(int i = 0 ; i < nums.size(); i++)
        {
            if (used[i] || used2.count(nums[i])) continue; 
            used[i] = true;
            used2.insert(nums[i]);
            path.push_back(nums[i]);
            backtrack(nums);
            path.pop_back();
            used[i] =false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        used.resize(nums.size(), false);
        backtrack(nums);
        return ans;
    }
};
