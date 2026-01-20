class Solution {
private:
vector<vector<int>> graph ;
vector<bool> isApple ;
int DFS(int node , int parent)
{
    int collectTime = 0;
    for(auto& child:graph[node])
    {
        if(child != parent) 
             collectTime += DFS(child, node);
    }
    return (collectTime > 0  || isApple[node]) ? collectTime + 2 : 0 ;
}
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        graph.resize(n);
        isApple = hasApple;
        for(auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int ans = DFS(0 ,-1);
        return ans > 0 ?  ans - 2 : 0;
    }
};
