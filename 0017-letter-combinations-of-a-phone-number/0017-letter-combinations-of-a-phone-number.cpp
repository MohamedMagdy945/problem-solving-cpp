class Solution{
    private:
        vector<string> phonenum = {"abc","def","ghi","jkl","mno","pqrs","tuv" ,"wxyz"};
        vector<string> ans;
        string path;
    public :
    void backtrack(int idx , string& digits ){
        if (idx == digits.length())
        {
            if (path.length() == digits.length()) ans.push_back(path);
            return ;
        }
        for(int i = idx ; i < digits.length() ; i++)
        {
            int phonenumIdx = digits[i] - '0' - 2 ;
            int length =  phonenum[phonenumIdx].length();
            for (int j = 0 ; j < length  ;j++ )
            {
                path.push_back(phonenum[phonenumIdx][j]);
                backtrack(i + 1 , digits);
                path.pop_back();
            }
        }

    }
    vector<string> letterCombinations(string digits) {
        backtrack(0 , digits);
        return ans;
    }
};