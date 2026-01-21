class Solution{
    private:
    string label ;
    vector<vector<int>> tree ;
    int maxLen = 1;
    int dfs (int node){
        int longest = 0 ;
        int secondLongest = 0;
        for (auto &child : tree[node])
        {
            int childLen = dfs(child);
            if(label[node] != label[child])
            {
                if(childLen > longest)
                {
                    secondLongest = longest ;
                    longest = childLen ;
                }
                else if(childLen > secondLongest)
                {
                    secondLongest = childLen ;
                }
            }
        }
        maxLen = max(maxLen , 1   + longest  + secondLongest );
        return longest + 1;
    }
    public:
    int longestPath(vector<int>& parent , string s)
    {
        int n = parent.size();
        tree.assign(n, vector<int>());
        label = s ;
        for(int i = 1; i < n ;i++)
        {
            tree[parent[i]].push_back(i);
        }
        dfs(0);
        return maxLen;
    }
};