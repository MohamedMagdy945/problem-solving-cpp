class Solution {
private:
unordered_map<int, bool> memo ;

bool backtrack(const string& word , int idx , const unordered_set<string> &dict)
{
    if( word.size() == idx ) return true ;
    if(memo.count(idx)) return memo[idx] ;
    string w = "";
    for(int i = idx ; i < word.size() ;  i++)
    {
        w.push_back(word[i]);
        if(dict.count(w))
        {
            if(backtrack(word , i + 1 , dict))
            {
                return memo[idx] = true ;
            }
        }
    }
    return memo[idx] = false;
}
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> result ;
         sort(words.begin(), words.end(),
             [](const string &a, const string &b) {
                 return a.size() < b.size();
             });
        unordered_set<string> dict;
        for(auto& word : words)
        {
            memo.clear();
            if(backtrack(word , 0 ,dict))
            {
                result.push_back(word);
            }
            dict.insert(word);
        }
        return result;
    }
};

