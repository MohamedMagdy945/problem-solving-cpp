class Solution{
    private:
    vector<vector<int>> tree;
    long long totalFuel = 0;
    int seats  ;
    
    pair<int,int> DFS(int node , int parent){
        int people = 0;
        int cars  = 0;
        for(auto& child: tree[node])
        {
            if (child == parent) continue; 
            auto [ p , c] = DFS(child, node);
            cars += c;
            people += p ;
            cars = (people + seats - 1) / seats ;
        }       
        people++;
        if(people > cars * seats) 
            cars++;
        totalFuel += cars ;
        return {people , cars};
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
        auto [r , c] =  DFS(0 , -1);
        return totalFuel != 0 ? totalFuel - c : 0  ;
    }
};

