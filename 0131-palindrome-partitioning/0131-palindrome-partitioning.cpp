class Solution
{
private:
    vector<vector<string>> validPlaindromSubstring;
    vector<string> currentSegmant ;
    int n ;
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;

        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
public:
    void backtrack(string& s,int currentPosition){
        if(currentPosition == n)
        {
            validPlaindromSubstring.push_back(currentSegmant);
            return;
        }
        
        for(int i = currentPosition ; i < n ; i++)
        {
            string leftPart = s.substr(currentPosition , i - currentPosition + 1);
            if(isPalindrome(leftPart))
            {
                currentSegmant.push_back(leftPart);
                backtrack(s, i + 1);
                currentSegmant.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        n = s.size();
        backtrack(s,0);
        return validPlaindromSubstring;
    }
};