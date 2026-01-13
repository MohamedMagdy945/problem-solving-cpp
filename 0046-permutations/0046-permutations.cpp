class Solution {
    private:
    vector<vector<int>> ans;

    public:
    void backtrack(int idx ,vector<int>& nums)
    {
        if (idx == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i = idx ; i < nums.size(); i++)
        {
            swap(nums[i],nums[idx]);
            backtrack(idx+1, nums);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(0, nums);
        return ans;
    }
};