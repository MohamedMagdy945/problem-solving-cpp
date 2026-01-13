class Solution {
    private:
    vector<string> ans;
    string path;
    int stop ;
    public:
    void backtrack(int openParenthes ,int  closedParenthes)
    {
        if ( openParenthes ==0 && closedParenthes == 0)
        {
            ans.push_back(path);
            return ;
        }
            
        if (openParenthes > 0)
        {
            path.push_back('(');
            backtrack(openParenthes - 1,closedParenthes);
            path.pop_back();
        }
        if( closedParenthes > openParenthes)
        {
            path.push_back(')');
            backtrack( openParenthes ,closedParenthes - 1);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        backtrack(n , n);
        return ans;
    }
};