class Solution {
private:
vector<int> parent ;
int find(int u)
{
    if(u != parent[u]) 
        return parent[u] = find(parent[u]);
    
     return parent[u];
}
void unite(int u ,int v)
{
    u = find(u);
    v = find(v);

    if(u == v) return ;
    parent[v] = u ;
}
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> tree(n , vector<int>());

        for(auto & e: edges){
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        map<int, vector<int>> mp;
        for(int i = 0; i < n ; i++)
        {
            mp[vals[i]].push_back(i);
        }

        parent.resize(n);
        for(int i = 0 ; i < n ; i++)
        {
            parent[i] = i ;
        }

        int ans = n ;
        vector<bool> active(n , false);
        for(auto &[val , nodes] : mp)
        {
            for(int &node :nodes)
            {
                active[node] = true ;
                for(auto& adj : tree[node])
                {
                    if(active[adj])
                    {
                        unite(node , adj);
                    }
                }
            }
            unordered_map<int,int> count ;
            for(int &u : nodes)
            {
                count[find(u)]++;
            }

            for(auto &[_ ,c] : count)
            {
                ans += c * (c - 1) / 2 ;
            }

        }
        return ans;
    }
};