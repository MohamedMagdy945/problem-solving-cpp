class Solution {
private:
int DFS(int node , int parent ,vector<vector<int>>& graph ,
 vector<bool>& hasApple)
{
    int collectTime = 0;
    for(auto& child:graph[node])
    {
        if(child != parent) 
             collectTime += DFS(child,node , graph ,hasApple);
    }
    if (collectTime > 0  || hasApple[node]) 
        return   collectTime + 2  ;
    return 0;
}
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n) ;
        for(auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int ans = DFS(0 ,-1 ,graph , hasApple);
        return ans > 0 ?  ans - 2 : 0;
    }
};
