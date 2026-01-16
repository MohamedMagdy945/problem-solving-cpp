
class Solution{
    public :
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int , int>>> graph (n);

        for(auto &flight : flights)
        {
            graph[flight[0]].push_back({flight[1] , flight[2]});
        }

        queue<tuple<int,int,int>> q;
        q.push({src , 0 , -1 });
        int minCost = 1e9;
        vector<vector<int>> best(n , vector<int>(k+2, 1e9));
        while (!q.empty())
        {
            auto [node , cost ,steps] = q.front();
            q.pop();
            if (steps > k  || cost > minCost ) continue; ;
            if (node == dst) {
                minCost = min(minCost, cost);
                continue;
            }
            for(auto &[child , w]: graph[node])
            {   
                int newCost = cost + w;
                if (newCost < best[child][steps+1]) {
                    best[child][steps+1] = newCost;
                    q.push({child, newCost, steps+1});
                    }
            }
        }
        return minCost == 1e9 ? -1 : minCost ;
    }
};