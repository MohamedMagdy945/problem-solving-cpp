class Solution {
private:
vector<vector<int>> graph ;
int DFS(int node , int parent , vector<bool>& hasApple)
{
    int collectTime = 0;
    for(auto& child:graph[node])
    {
        if(child != parent) 
             collectTime += DFS(child, node,hasApple);
    }
    return (collectTime > 0  || hasApple[node]) ? collectTime + 2 : 0 ;
}
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        graph.assign(n,{});
        for(auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int ans = DFS(0 ,-1 , hasApple);
        return ans > 0 ?  ans - 2 : 0;
    }
};
