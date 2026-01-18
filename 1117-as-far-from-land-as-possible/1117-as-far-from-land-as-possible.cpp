class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int , int>> q;
        for(int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < n; j++){
                if(grid[i][j])
                {
                    q.push({i , j});
                }
            } 
        }
        if(q.empty() || q.size() == n*n) return -1;
        int dis = -1;
        int dx[4] = { 1 , -1 , 0 , 0};
        int dy[4] = { 0 , 0 , -1 , 1};

        while(!q.empty())
        {
            int size = q.size();
            dis++;
            while(size--)
            {
                auto [x , y ] = q.front();
                q.pop();
                for(int k = 0 ; k < 4 ; k++)
                {
                    int i = x + dx[k];
                    int j = y + dy[k];
                    if(i >= 0 && i < n && j >= 0 && j < n && !grid[i][j])
                    {
                        grid[i][j] =  1;
                        q.push({i , j});
                    }
                }
            }
        }
        return dis;
    }
};