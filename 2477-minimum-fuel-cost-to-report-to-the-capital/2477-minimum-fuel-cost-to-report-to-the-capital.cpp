class Solution{
    private:
    vector<vector<int>> tree;
    long long totalFuel = 0;
    int seats  ;
    
    int DFS(int node , int parent){
        int people = 1;
        for(auto& child: tree[node])
        {
            if (child == parent) continue; 
            people += DFS(child, node);
        } 
        if (node != 0)             
            totalFuel += (people + seats - 1) / seats ;
        return people ;
    }
    public: 
    long long minimumFuelCost(vector<vector<int>>& roads, int _seats)
    {
        int n = roads.size() + 1;
        tree.assign(n , vector<int>());
        seats = _seats ; 
        for(auto & road: roads)
        {
            tree[road[0]].push_back(road[1]);
            tree[road[1]].push_back(road[0]);
        }
        DFS(0 , -1);
        return totalFuel ;
    }
};