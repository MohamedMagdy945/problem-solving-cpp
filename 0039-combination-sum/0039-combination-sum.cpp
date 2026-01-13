
class Solution {
    private:
    vector<vector<int>> ans;
    vector<int> path;
    
    public:
    void backtrack(int idx,int target , vector<int>& candidates)
    {
        if (target == 0)
        {
            ans.push_back(path);
            return ;
        }
        for (int i = idx ; i < candidates.size() ; i++)
        {
            if (candidates[i] > target) continue;
            path.push_back(candidates[i]);
            backtrack(i ,  target - candidates[i] , candidates);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(0 , target , candidates);
        return ans;
    }
};