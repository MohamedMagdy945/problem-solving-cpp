class Solution
{
    private:
    public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int , bool>>> graph(n);
        vector<int> ans(n , -1);

        for(auto &e : redEdges)
        {   
            graph[e[0]].push_back({e[1], true});
        }
        for(auto &e : blueEdges)
        {   
            graph[e[0]].push_back({e[1], false});
        }

        vector<vector<bool>> visited(n ,vector<bool>(2, false));
        visited[0][0] = visited[0][1] = true;
        queue<pair<int,bool>> q;
        q.push({0, 0});
        q.push({0, 1});
        int steps = 0;        
        while(!q.empty())
        {
            int size = q.size() ;
            while(size--)
            {
                auto [node , nodeColor] = q.front();
                q.pop();
                if (ans[node] == -1)
                    ans[node] = steps;

                for(auto &[next, color]  : graph[node])
                {
                    if ( nodeColor != color && !visited[next][color]  )
                    {
                        q.push({next, color});
                        visited[next][color] = true;
                    }
                }
            }
            steps++;
        }
        return ans;
    }
};