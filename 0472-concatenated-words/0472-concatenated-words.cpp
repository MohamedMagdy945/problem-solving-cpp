
class Solution {
private:
unordered_set<string> uniqueWords ;
unordered_map<int, bool> memo ;

bool backtrack(string word , int idx )
{
    if( word.size() == idx ) return true ;
    if(memo.count(idx)) return memo[idx] ;
    string w = "";
    for(int i = idx ; i < word.size() ;  i++)
    {
        w.push_back(word[i]);
        if(uniqueWords.count(w))
        {
            if(backtrack(word , i + 1))
            {
                return memo[idx] = true ;
            }
        }
    }
    return memo[idx] = false;
}
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        uniqueWords = unordered_set(words.begin() , words.end());
        vector<string> result ;
        for(auto& word : words)
        {
            memo.clear();
            uniqueWords.erase(word);
            if(backtrack(word , 0))
            {
                result.push_back(word);
            }
            uniqueWords.insert(word);
        }
        return result;
    }
};

