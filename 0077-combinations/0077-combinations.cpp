class Solution {
private:
    vector<int> path ;
    vector<vector<int>> result ;
    void backtrack(int idx , int n , int k)
    {
        if (path.size() == k )
        {
            result.push_back(path);
            return;
        }
        for ( int i = idx ;  i <= n ; i++ ){
            path.push_back(i);
            backtrack( i + 1 , n ,k );
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtrack(1 , n , k);
        return result ;
    }
};