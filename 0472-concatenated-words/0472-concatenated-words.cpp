class Solution {
public:

    bool isContacted(const string& word , const unordered_set<string>& dict)
    {
        int n = word.size();

        vector<int> dp(n + 1);
        dp[0] = true;
        for(int i = 1 ; i <= n ; i++)
        {
            int j = 0 ;
            if (i == n)  j = 1;
            while(j < i )
            {
                string x = word.substr(j , i - j) ;
                if(dp[j] && dict.count(word.substr(j , i - j)))
                {
                    dp[i] = true ;
                    break ;
                }
                j++;
            }
        }
        return dp[n];
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> result;
        unordered_set<string> dict;

        sort(words.begin(), words.end(),
        []  (const string& a , const string& b) {
        return a.size() < b.size();
        }) ;
            
        for(auto & w : words)
        {

            if(isContacted(w , dict))
            {
                result.push_back(w);
            }
            dict.insert(w);
        }
        return result;
    }        
};
