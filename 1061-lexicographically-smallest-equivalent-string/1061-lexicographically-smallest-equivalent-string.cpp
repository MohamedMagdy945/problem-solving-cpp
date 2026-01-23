class Solution{
    private:
    vector<vector<int>> graph ;
    vector<int> parent ;
    int find(int u){
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }
    void connect(int u , int v){
        u = find(u);
        v = find(v);
        if (u != v) 
            parent[max(u, v)] = min(u, v) ;
    }
    public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        parent.resize(26);
        for (int i = 0; i < 26; i++) parent[i] = i;
        for(int i = 0 ; i < s1.length() ; i++)
            connect( s1[i] - 'a' , s2[i] - 'a');            
        for(char &c: baseStr)
        {
            c = find(c - 'a') + 'a';
        }
        return baseStr ;
    }
};