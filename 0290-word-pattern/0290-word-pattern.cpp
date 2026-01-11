class Solution {
public:
    bool wordPattern(string pattern, string s) {

    unordered_map<char,string> mp1;
    unordered_map<string,char> mp2;
    char delimiter = ' ';
    vector<string> result;

    size_t start = 0;
    size_t end = s.find(delimiter);

    while (end != string::npos) {
        result.push_back(s.substr(start, end - start));
        start = end + 1;
        end = s.find(delimiter, start);
    }

    result.push_back(s.substr(start));

    if(pattern.size() != result.size()) return false;

    
    for(int i = 0; i < pattern.size(); i++)
    {
        char c = pattern[i];
        string w = result[i];

        if(mp1.count(c) && mp1[c] != w) return false;   
        if(mp2.count(w) && mp2[w] != c) return false;   
        mp1[c] = w;
        mp2[w] = c;
    }

    return true;
}
};