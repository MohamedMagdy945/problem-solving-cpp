class Solution {
private:
    vector<int> path ;
    vector<vector<int>> result ;
    void backtrack(int idx , vector<int>& nums)
    { 
        result.push_back(path);
        for ( int i = idx ;  i < nums.size() ; i++ ){
            path.push_back(nums[i]);
            backtrack( i + 1 , nums);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack( 0 , nums);
        return result ;
    }
};