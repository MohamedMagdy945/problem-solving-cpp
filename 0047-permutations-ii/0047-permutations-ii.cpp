class Solution {
    public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         vector<vector<int>> ans;
        vector<int> path;
        vector<bool> used;
        used.resize(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums , used , path , ans);
        return ans;
    }
    private:
    void backtrack(vector<int>& nums , vector<bool>& used ,
    vector<int>& path ,vector<vector<int>>& ans)
    {
        if (path.size() == nums.size())
        {
            ans.push_back(path);
            return;
        }
        for(int i = 0 ; i < nums.size(); i++)
        {
            if (used[i]) continue; 
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums , used , path , ans);
            path.pop_back();
            used[i] =false;
        }
    }
};